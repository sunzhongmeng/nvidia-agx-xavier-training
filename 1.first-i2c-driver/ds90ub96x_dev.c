#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/i2c.h>
#include <linux/err.h>
#include <linux/regmap.h>
#include <linux/slab.h>

static struct i2c_client *ds90ub96x_client;

static const unsigned short addr_list[] = { 0x30, I2C_CLIENT_END };
static int ds90ub96x_dev_init(void)
{
	struct i2c_adapter *i2c_adap;
	struct i2c_board_info ds90ub96x_info;

	memset(&ds90ub96x_info, 0, sizeof(struct i2c_board_info));	
	strlcpy(ds90ub96x_info.type, "ds90ub96x", I2C_NAME_SIZE);

	i2c_adap = i2c_get_adapter(2);/*ds90ub964使用Xavier上的I2C3(所有索引号为2)*/
	ds90ub96x_client = i2c_new_probed_device(i2c_adap, &ds90ub96x_info, addr_list, NULL);
	i2c_put_adapter(i2c_adap);

	if (ds90ub96x_client)
		return 0;
	else
		return -ENODEV;
}

static void ds90ub96x_dev_exit(void)
{
	i2c_unregister_device(ds90ub96x_client);
}


module_init(ds90ub96x_dev_init);
module_exit(ds90ub96x_dev_exit);
MODULE_LICENSE("GPL");


