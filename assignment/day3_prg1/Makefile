obj-m:= export.o average.o
KDIR=/lib/modules/$(shell uname -r)/build/
PWD=$(shell pwd)

default:
	make -C $(KDIR) M=$(PWD) modules

install:
	make -C $(KDIR) M=$(PWD) modules_install

clean:
	make -C $(KDIR) M=$(PWD) clean
