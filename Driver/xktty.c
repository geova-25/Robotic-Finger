#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <asm/uaccess.h>

/*-------------------------------------------------------------------------------
# Instituto Tecnologico de Costa Rica-Area Academica Ingenieria en Computadores
# Principios de Sistemas Operativos - Proyecto 2 - Robotic Finger
# Estudiante-carnet: Giovanni Villalobos Quiros - 2013030976
# Based on code from - Basado en codigo tomado de
# http://nairobi-embedded.org/access_dev_files_from_krn.html
-------------------------------------------------------------------------------*/



static struct file *ktty_open(const char *filename, int flags, umode_t mode)
{
    return filp_open(filename, 0, O_RDWR);
}

static ssize_t ktty_write(struct file *f, const char *buf, int count)
{

    int result;
    mm_segment_t oldfs;

    oldfs = get_fs();
    set_fs(KERNEL_DS);
    f->f_pos = 0;
    result = f->f_op->write(f, buf, count, &f->f_pos);
    set_fs(oldfs);

    return result;
}

static void ktty_close(struct file *xktty, fl_owner_t id)
{
        filp_close(xktty, id);
}

/* =============== module file operations ===================== */
DEFINE_MUTEX(xmutex);
static struct file *xktty = NULL;
static int xktty_open(struct inode *inode, struct file *filp)
{
    #define XKTTY_MAX_PATH 20
    #define XKTTY_NUM 0
    char filename[XKTTY_MAX_PATH];

    /* only one process at a time */
    if(!(mutex_trylock(&xmutex)))
        return -EBUSY;

    snprintf(filename, XKTTY_MAX_PATH, "/dev/ttyS%d", XKTTY_NUM);
    xktty = ktty_open("/dev/ttyACM0", 0, O_RDWR);
    if (PTR_RET(xktty)) {
        mutex_unlock(&xmutex);
        return PTR_RET(xktty);
    }

    return 0;
}

static int xktty_release(struct inode *inode, struct file *file)
{
    if(!IS_ERR_OR_NULL(xktty))
        ktty_close(xktty, 0);
    mutex_unlock(&xmutex);
    return 0;
}

static ssize_t xktty_write(struct file *filp,
                 const char __user * buf, size_t count,
                 loff_t * f_pos)
{

    #define XKTTY_MAX_BUF_LEN 200
    const char kbuf[XKTTY_MAX_BUF_LEN];

    count = count < XKTTY_MAX_BUF_LEN ? count : XKTTY_MAX_BUF_LEN;
    if (copy_from_user((char *)kbuf, (const char __user *)buf, count))
        return -EFAULT;

    if (!IS_ERR_OR_NULL(xktty))
        return ktty_write(xktty, kbuf, count);
    else
        return -EFAULT;
}

static struct file_operations xktty_ops = {
    .owner = THIS_MODULE,
    .open = xktty_open,
    .release = xktty_release,
    .write = xktty_write,
};

/* =================== init/exit ======================== */

static struct cdev cdev;
static struct class *class;
static int xktty_mjr;

static int xktty_init(void)
{
    #define XKTTY_NAME "xktty"

    dev_t devt = MKDEV(0, 0);
    if (alloc_chrdev_region(&devt, 0, 1, XKTTY_NAME) < 0)
        return -1;
    xktty_mjr = MAJOR(devt);

    cdev_init(&cdev, &xktty_ops);
    cdev.owner = THIS_MODULE;
    devt = MKDEV(xktty_mjr, 0);
    if (cdev_add(&cdev, devt, 1))
        goto exit0;

    class = class_create(THIS_MODULE, XKTTY_NAME);
    if (!class)
        goto exit1;

    devt = MKDEV(xktty_mjr, 0);
    if (!(device_create(class, NULL, devt, NULL, XKTTY_NAME)))
        goto exit2;

    return 0;

exit2:
    class_destroy(class);
exit1:
    cdev_del(&cdev);
exit0:
    unregister_chrdev_region(MKDEV(xktty_mjr, 0), 1);

    return -1;
}

static void xktty_fini(void)
{
    device_destroy(class, MKDEV(xktty_mjr, 0));
    class_destroy(class);
    cdev_del(&cdev);
    unregister_chrdev_region(MKDEV(xktty_mjr, 0), 1);
}

module_init(xktty_init);
module_exit(xktty_fini);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("siro mugabi, nairobi-embedded.org");
