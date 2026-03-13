#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>

static int__init marvellous_init(void)
{
    printk(KERN_INFO "Marvellous Module gets inserted : Jay Ganesh...\n");
    return 0;
}

static void__exit marvellous_exit(void)
{
    printk(KERN_INFO "Marvellous Module gets removed\n");
}

module_init(marvellous_init);
module_exit(marvellous_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PREM CHOUDHARY");
MODULE_DESCRIPTION("DEMO KERNEL MODULE");

// device driver is a special version of kernel module which is written to handle the operations of device 

// every device driver is kernel modeule but every kernel module is not device driver