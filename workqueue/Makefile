KERNELDIR ?= /lib/modules/$(shell uname -r)/build

obj-m := wq.o dedicated_wq.o

all default: modules
install: modules_install

modules modules_install help clean:
	$(MAKE) -C $(KERNELDIR) M=$(shell pwd) $@
