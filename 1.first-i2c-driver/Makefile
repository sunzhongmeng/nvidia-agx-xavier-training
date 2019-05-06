#build: kernel_modules

kernel_modules:
	make -C /usr/src/linux-headers-4.9.140-tegra-ubuntu18.04_aarch64/kernel-4.9/  M=$(CURDIR) modules

clean:
	make -C /usr/src/linux-headers-4.9.140-tegra-ubuntu18.04_aarch64/kernel-4.9/ M=$(CURDIR) clean
	rm -rf modules.order
	
obj-m += ds90ub96x_dev.o
obj-m += ds90ub96x_drv.o
