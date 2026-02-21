// how to use "modinfo Hello.ko" command

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#define DRIVER_AUTHOR "Prem Choudhary"
#define DRIVER_DESC "It is a Marvellous Infosystems Driver"

MODULE_LICENSE("GPL");

static int no __initdata = 11;

static int __init Marvellous_init(void)
{
    printk(KERN_INFO "Marvellous module loaded: Jay Ganesh %d\n", no);
    return 0;
}

static void __exit Marvellous_cleanup(void)
{
    printk(KERN_INFO "Marvellous module unloaded : Jay Ganesh...\n");
}

module_init(Marvellous_init);
module_exit(Marvellous_cleanup);

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);