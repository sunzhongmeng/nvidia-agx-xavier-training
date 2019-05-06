#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/i2c.h>
#include <linux/err.h>
#include <linux/regmap.h>
#include <linux/slab.h>

static const struct i2c_device_id ds90ub96x_id_table[] = {
	{ "ds90ub96x", 0x30},
	{}
};
MODULE_DEVICE_TABLE(i2c,ds90ub96x_id_table);	


static int ds90ub96x_probe(struct i2c_client *client,
				const struct i2c_device_id *id)
{
	printk("%s %s %d\n", __FILE__, __FUNCTION__, __LINE__);
	return 0;
}

static int ds90ub96x_remove(struct i2c_client *client)
{
	printk("%s %s %d\n", __FILE__, __FUNCTION__, __LINE__);
	return 0;
}


/* 1. ∑÷≈‰/…Ë÷√i2c_driver */
static struct i2c_driver ds90ub96x_driver = {
	.driver	= {
		.name	= "ds90ub96x",
		.owner	= THIS_MODULE,
	},
	.probe		= ds90ub96x_probe,
	.remove		= ds90ub96x_remove,
	.id_table	= ds90ub96x_id_table,
};

static int __init ds90ub96x_drv_init(void)
{
	return i2c_add_driver(&ds90ub96x_driver);
}
module_init(ds90ub96x_drv_init);

static void __exit ds90ub96x_drv_exit(void)
{
	i2c_del_driver(&ds90ub96x_driver);
}
module_exit(ds90ub96x_drv_exit);
MODULE_LICENSE("GPL");


