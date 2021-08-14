obj-m:= chardriver.o
KDIR= /lib/modules/$(shell uname -r)/build
PWD:= $(shell pwd)

default:
	make -C $(KDIR) M=$(PWD) modules
	gcc -o  Application Application.c

clean:
	make -C $(KDIR) M=$(PWD) clean
	rm Application

install:
	make -C $(KDIR) M=$(PWD) modules_install
