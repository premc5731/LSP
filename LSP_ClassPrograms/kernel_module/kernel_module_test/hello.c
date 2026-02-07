#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Marvellous Infosystems by Piyush Khairnar");
MODULE_DESCRIPTION("First Kernel Module");
static int __init hello_init(void)
{
printk(KERN_INFO "Jay Ganesh: Module Loaded\n");
return 0;
}
static void __exit hello_exit(void)
{
printk(KERN_INFO "Jay Ganesh: Module Removed\n");
}
module_init(hello_init);
module_exit(hello_exit);