/*-------------------------------------------------------------------------------
# Instituto Tecnologico de Costa Rica-Area Academica Ingenieria en Computadores
# Principios de Sistemas Operativos - Proyecto 2 - Robotic Finger
# Estudiante-carnet: Giovanni Villalobos Quiros - 2013030976
# Based on code from - Basado en codigo tomado de
# http://nairobi-embedded.org/access_dev_files_from_krn.html
-------------------------------------------------------------------------------*/

#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <asm/uaccess.h>

/*------------------------------Module Info-----------------------------------*/

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Giovanni Villalobos, ITCR");
MODULE_DESCRIPTION("This module is used to send instructions to robotic Finger"
    "throught serial communication");
MODULE_VERSION("1.0");

/*------------------------------Definitions-----------------------------------*/

// Max len of the buffer that will be write
#define ROBOTIC_FINGER_LEN_BUFFER 500
// Name of the module driver
#define ROBOTIC_FINGER_NAME_STRING "robotic_finger"
// Mutex to avoid having more than one accesing the file
DEFINE_MUTEX(mutex_file_only_one_user_at_the_time);
//Creates a new struct type of file to open the serial of Arduino
static struct file *robotic_finger = NULL;

/*---------------------Auxiliar functions and structures----------------------*/

/*
** This is a struct that will help to use a file inside the kernel space
** filename is the name of the file to open
** flags are the regular flags same as open function of user space
** mode is the mode  for the new file
*/


static struct file *robotic_finger_aux_open(const char *filename, int flags, umode_t mode)
{
    return filp_open(filename, 0, O_RDWR);
}

/*
** This function write data to the arduino serial
** file is the file that will be write with something
** buf is the buffer of data to write
** count is the size of the buffer to write
*/

static ssize_t robotic_finger_aux_write(struct file *file_to_write, const char *buffer, int count)
{

    int result_of_write;
    /* This three lines help to  avoid the system call from failing because
    this is kernel space that is usually forbidden */
    mm_segment_t oldfs;

    oldfs = get_fs();
    set_fs(KERNEL_DS);

    //Here we write the buffer to the file of serial port
    file_to_write->f_pos = 0;
    result_of_write = file_to_write->f_op->write(file_to_write, buffer, count, &file_to_write->f_pos);
    //Restore the space of the kernel space and prevent further system calls
    set_fs(oldfs);

    return result_of_write;
}

/*
** This function close the file opened in the function open
** file is the file to close
** id is the owner of the file
**
*/
static void robotic_finger_aux_close(struct file *file_to_close, fl_owner_t id)
{
        filp_close(file_to_close, id);
}

/*-------------------Main functions allowed in module-------------------------*/


/*
** This function called when someone wants to open /dev/robotic_finger
** so it is initializated and also opens a second file to write data to
**
**
*/
static int robotic_finger_open(struct inode *inode, struct file *filp)
{
    //To proccess only one at the time and to avoid error that can be done
    if(!(mutex_trylock(&mutex_file_only_one_user_at_the_time)))
    {
        return -1;
    }

    robotic_finger = robotic_finger_aux_open("/dev/ttyACM0", 0, O_RDWR);
    //If there was no error opening the file unlock the mux
    if (PTR_RET(robotic_finger))
    {
        mutex_unlock(&mutex_file_only_one_user_at_the_time);
        return PTR_RET(robotic_finger);
    }

    return 0;
}

/*
** To release the robotic finger module
**
**
**
*/
static int robotic_finger_release(struct inode *inode, struct file *file)
{
    if(!IS_ERR_OR_NULL(robotic_finger))
        robotic_finger_aux_close(robotic_finger, 0);
    mutex_unlock(&mutex_file_only_one_user_at_the_time);
    return 0;
}


/*
** This function writes the file from the user
** file is the file in which things are going to be written
** buf is the buffer of data to write
** count is the number of data to write
*/
static ssize_t robotic_finger_write(struct file *filp,
                 const char __user * buf, size_t count,
                 loff_t * f_pos)
{

    const char instr_buf[ROBOTIC_FINGER_LEN_BUFFER];

    //This checks if count is minor than the max buffer aasign count value,
    //else assign the max buffer size
    if(count < ROBOTIC_FINGER_LEN_BUFFER)
    {
      count = count;
    }
    else
    {
      count = ROBOTIC_FINGER_LEN_BUFFER;
    }

    //The function copy from user send the data that user passes to the
    //serial, the data is stored in instr_buf.
    if (copy_from_user((char *)instr_buf, (const char __user *)buf, count))
    {
        return -1;
    }
    //Here if there is no error en robotic_finger then data is write to the serial
    //that was stored in instr_buf
    if (!IS_ERR_OR_NULL(robotic_finger))
    {
      return robotic_finger_aux_write(robotic_finger, instr_buf, count);
    }
    else
        return -1;
}


/*
** The file operations struct that hold pointers to the functions defined by
** the driver to handle the requested operations
** the owner prevents for module being unloaded whe it is in use
**
*/
static struct file_operations robotic_finger_ops = {
    .owner = THIS_MODULE,
    .open = robotic_finger_open,
    .release = robotic_finger_release,
    .write = robotic_finger_write,
};

/* --------------------------- Insert and Exlude functions--------------------*/

static struct cdev cdev;
static struct class *class;
static int robotic_finger_major;

/*
** This function init the module when is inserted
**
**
**
*/

static int robotic_finger_init(void)
{

    //dev_t is used to hold major and minor numbers
    //MKDEV can give as return a dev_t is you have major and minor
    //minor is to distinguish from different ports as COM1, COM2 each has a
    //different minor number. The major will tell what kind of device is,
    //like hard disk or serial terminal, in this case we dont know which numbers
    //So we create a simple structure and then obtain the Major assignated

    dev_t devt = MKDEV(0, 0);

    //This will allocate a Major Number for us, just one, with the given name
    if (alloc_chrdev_region(&devt, 0, 1, ROBOTIC_FINGER_NAME_STRING) < 0)
        return -1;
    robotic_finger_major = MAJOR(devt);
    //Struct cdev is a element of the inode, struct cdev is the representation
    //inside the kernel to represent char devices in this case the serial port.
    //As I want to make use of a char device, I had to create a cdev structure
    //so I can invoke a device of this type
    cdev_init(&cdev, &robotic_finger_ops);
    // the owner prevents for module being unloaded whe it is in use
    cdev.owner = THIS_MODULE;
    devt = MKDEV(robotic_finger_major, 0);
    //This will simple add the char device to the system
    if (cdev_add(&cdev, devt, 1))
    {
        unregister_chrdev_region(MKDEV(robotic_finger_major, 0), 1);
        return -1;
    }
    //Creates a new class of device that is in /sys/class
    class = class_create(THIS_MODULE, ROBOTIC_FINGER_NAME_STRING);
    if (!class)
    {
        cdev_del(&cdev);
        return -1;
    }
    //This lines will take the Major number assignated above,then assign those
    //to the class created before
    devt = MKDEV(robotic_finger_major, 0);
    if (!(device_create(class, NULL, devt, NULL, ROBOTIC_FINGER_NAME_STRING)))
    {
        class_destroy(class);
        return -1;
    }
    return 0;
}

/*
** Function called when the module is excluded from kernel space
**
**
**
*/
static void robotic_finger_fini(void)
{
    device_destroy(class, MKDEV(robotic_finger_major, 0));
    class_destroy(class);
    cdev_del(&cdev);
    unregister_chrdev_region(MKDEV(robotic_finger_major, 0), 1);
}

/*-----------------Functions called when the module is inserted---------------*/

module_init(robotic_finger_init);
module_exit(robotic_finger_fini);
