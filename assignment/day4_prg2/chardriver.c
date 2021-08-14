#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/uaccess.h>
//#include<linux/wait.h>
//#include<linux/sched.h>

MODULE_LICENSE("GPL");

#define NAME MyCharDevice
dev_t Mydev;

int flag=1;
char Buff[80];

 char Kbuff [80], Ubuff[80];


// fun prototypes

int NAME_open(struct inode *inode,struct file *filp);
int NAME_release(struct inode *inode, struct file *filp);
ssize_t NAME_write(struct file *filp, const char __user *Ubuff,size_t count ,loff_t *offp);
ssize_t NAME_read(struct file *filp,char __user *Ubuff,size_t count, loff_t *offp);
// int NAME_flush(struct file *filp);

//structure that defines the operation that driver provide

struct file_operations fops=
{
	.owner = THIS_MODULE,
	.open = NAME_open,
	.read = NAME_read,
	.write = NAME_write,
	.release= NAME_release,
	// .flush= NAME_flush,
	
};

// wait_queue_head_t mywait;
//DECLARE_WAIT_QUEUE_HEAD (mywait);

// structure for a character driver
struct cdev *my_cdev;

//init module
static int __init  CharDevice_init(void)
{
	int result;

//	int MAJOR,MINOR;
//	dev_t Mydev;
	Mydev = MKDEV(255,0); // CREATE A DEVICE NO.
//	MAJOR=MAJOR(Mydev);
//	MINOR=MINOR(Mydev);
//	printk("\n Major no. is %d...Minor no. is %d\n",MAJOR,MINOR);
	printk("\n Inside the Char device\n");
	result=register_chrdev_region(Mydev,1, "MyCharDevice"); //register device region
	if(result<0)
	{
		printk(KERN_ALERT "\nThe regin is not obtanied\n");
		return(-1);
	}

	my_cdev = cdev_alloc(); // allocate memory to char structuire
	my_cdev->ops = &fops; // link our file operation to char device

	result=cdev_add(my_cdev,Mydev,1); //notify kernel abt the new device
	if(result<0)
	{
             printk(KERN_ALERT "\n The char device not created...\n");
	     unregister_chrdev_region(Mydev,1);
	     return (-1);
	}
	return 0;
}

//clean module
void __exit  CharDevice_exit(void)
{

//	int MAJOR,MINOR;
//	Mydev=MKDEV(255,0);
//	MAJOR=MAJOR(Mydev);
//	MINOR=MINOR(Mydev);
//	printk("\n The Major no is %d ...The Minor no. is %d\n",MAJOR,MINOR);
	unregister_chrdev_region(Mydev,1); //unregister the device no and the device is created
	cdev_del(my_cdev);
	printk(KERN_ALERT "\n I have unregister the stuff that was allocated... Good bye for ever...\n");
	 
}

//Open system call

int NAME_open(struct inode *inode,struct file *filp)
{
	printk(KERN_ALERT "\n this kernel open call.. i have nothing to do...but u have all\n");
	return 0;
}

//sszint NAME_read(ssize_t)

ssize_t NAME_read(struct file *filp, char __user *Ubuff, size_t count ,loff_t *offp)
{
	unsigned long int result;
	ssize_t retval;
//         printk("\n Inside read ...before wait ");
//	if(flag==1)
//	{
//		wait_event_interrupt(mywait,flag==0);
//	}
//	printk("\n In read ...after wait...data available");
	result=copy_to_user((char *)Ubuff,(char *) Buff,count);
	if(result!=0)
	{
		printk(KERN_ALERT "\n data not copied\n");
	        retval=-EFAULT;
                return retval;
	}

	else
	{
	 flag=1;
	 printk("\n Reading data\n");
	 retval=count;
	 return retval;
	 }
}

 ssize_t NAME_write(struct file *filp, const char __user *Ubuff, size_t count , loff_t *offp)
{
    unsigned long result;
    ssize_t retval;
    //wait_event(mywait,flag==1);
     
    printk("\n In write...shortly to write the data");
    result=copy_from_user((char *)Buff,(char *)Ubuff,count);
    if(result==0)
    {
	    printk(KERN_ALERT "\n mESSAGE FROM USER IS >>>>%s<<<\n",Buff);
	    retval=count;
	    flag=0;
//	    wake_up_interrupible(&mywait);
	    return retval;
    }

    else
    {
	    printk(KERN_ALERT"\n some prob in write\n");
	    retval=-EFAULT ;
	    return retval ;
    }

    

}
//close system call

int NAME_release(struct inode *inode,struct file *filp)
{
	printk(KERN_ALERT"\n This is release method of my character driver ... bye \n");
	return 0;
}

module_init(CharDevice_init);
module_exit(CharDevice_exit);
