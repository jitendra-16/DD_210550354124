#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include "header.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("JITENDRA");

static int one=1;
static int two=2;

static int  __init add_init(void)
{
	int average;

	printk("we r going to sum\n");
	printk("add is %d\n",my_add(one,two));
	average=my_add(one,two)/2;
	printk("avg is %d\n",average);
	return 0;
}

static void __exit add_exit(void)
{
	printk("we r leaving\n");
}

module_init (add_init);
module_exit (add_exit);
