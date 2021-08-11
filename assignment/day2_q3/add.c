#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("JITU");

static int add(char* s, int a, int b)
{
	if(strcmp(s,"add")==0)
	{
		return (a+b);
	}
	else if(strcmp(s,"sub")==0)
	{
		return(a-b);
	}
	else if(strcmp(s,"mul")==0)
	{
		return(a*b);
	}
	else if(strcmp(s,"div")==0)
	{
		return(a/b);
	}

	return 0;
}

static char* s=0;
static int x=0;
static int y=0;

module_param (s , charp ,S_IRUGO);
module_param (x , int ,S_IRUGO);
module_param (y ,int ,S_IRUGO);

static int __init add_init(void)
{
	printk("we r going  to give command line %d %d %s\n",x,y,s);
	printk("result is %d\n",add(s,x,y));
        return 0;
}

static void __exit add_exit(void)
{
	printk("sum is over\n");
}
module_init(add_init);
module_exit(add_exit);

