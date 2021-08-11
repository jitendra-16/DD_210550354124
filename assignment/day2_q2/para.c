#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE ("GPL");
MODULE_AUTHOR ("JITU");

static int intvar=6;

module_param (intvar, int, S_IRUGO);

static int __init  hello_init(void)
{
	printk("\n we r in init fun");
	printk("\n value of integer is %d\n",intvar);
	return 0;
}

static void __exit hello_exit(void)
{
	printk("\n bye parameter");

}

 module_init(hello_init);
 module_exit(hello_exit);
