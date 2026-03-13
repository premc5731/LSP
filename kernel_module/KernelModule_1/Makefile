obj-m += KernelModule.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(pwd) modules
