kmod = robotic_finger
ifneq ($(KERNELRELEASE),)
obj-m := $(kmod).o
else

KDIR ?= /lib/modules/$$(uname -r)/build

all:
				$(MAKE) -C $(KDIR) M=$$PWD modules

clean:
				rm *.o
				rm *.mod.c
				rm *.symvers
				rm *.order
				rm *.ko

#clean:
#				$(MAKE) -C $(KDIR) M=$$PWD clean

.PHONY  : clean
endif
