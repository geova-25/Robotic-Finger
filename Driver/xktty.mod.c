#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x5c7202ab, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xb4edef60, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x6499f889, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x883f9b2f, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0x1eb87674, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0xe7d06ec4, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x82d89bf6, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x7033b463, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0x53f00cac, __VMLINUX_SYMBOL_STR(filp_open) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0x4e7b455f, __VMLINUX_SYMBOL_STR(mutex_trylock) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x3356b90b, __VMLINUX_SYMBOL_STR(cpu_tss) },
	{ 0x4f6b400b, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0xb1c193fe, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0xd46908ef, __VMLINUX_SYMBOL_STR(filp_close) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "2D7C82A8F765898CD1EEECA");
