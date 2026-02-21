// how to register user defined functions for init and exit

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");

static int __init Marvellous_init(void)
{
    printk(KERN_INFO "Marvellous module loaded: Jay Ganesh...\n");
    return 0;
}

static void __exit Marvellous_cleanup(void)
{
    printk(KERN_INFO "Marvellous module unloaded : Jay Ganesh...\n");
}

module_init(Marvellous_init);
module_exit(Marvellous_cleanup);