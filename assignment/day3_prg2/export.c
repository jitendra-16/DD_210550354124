#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE ("GPL");
MODULE_AUTHOR ("JITENDRA");

static int my_add(int a, int b)
{
	return(a+b);
}

EXPORT_SYMBOL_GPL(my_add);

static int __init hello_init(void)
{
	printk("\n hello add code is here\n\n");
        return 0;
}
 
static void  __exit hello_exit(void)
{
	printk("bye\n\n");
}

module_init (hello_init);
module_exit (hello_exit);
