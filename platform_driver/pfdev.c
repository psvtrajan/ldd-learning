#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>

static struct platform_device *pdev;

static int __init my_pdev_add(void)
{
	int inst_id = 0;

	pdev = platform_device_alloc("platform-dummy-char", inst_id);
	platform_device_add(pdev);
	pr_info("Platform-dummy-char device added\n");
	return 0;
}

static void __exit my_pdev_put(void)
{
	pr_info("platform-dummy-char device removed\n");

	/* Unregistering from Kernel */
	platform_device_put(pdev);
}

module_init(my_pdev_add);
module_exit(my_pdev_put);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Thiyagarajan P <psvthiyagarajan@gmail.com>");
MODULE_DESCRIPTION("platform device");
