#include<linux/init.h>
#include<linux/module.h>

static int hello_init(void)
{
	printk("hello_world\n");
	return 0;
}

static void hello_cleanup(void)
{
	printk("GOOD BYE\n");
}

module_init(hello_init);
module_exit(hello_cleanup);

MODULE_LICENSE("GPL");// license is General Public license
MODULE_AUTHOR("JITU");
MODULE_DESCRIPTION("A simple hello world LKM!");


