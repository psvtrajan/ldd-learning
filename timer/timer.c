#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/timer.h>

static struct timer_list my_timer;

void my_timer_callback(struct timer_list *data)
{
	pr_info("%s called (%ld).\n", __func__, jiffies);
}

static int __init my_init(void)
{
	int ret;

	pr_info("Timer module loaded\n");

	timer_setup(&my_timer, my_timer_callback, 0);

	pr_info("Setup timer to fire in 300ms (%ld)\n", jiffies);

	ret = mod_timer(&my_timer, jiffies + msecs_to_jiffies(10000));
	if (ret)
		pr_err("Timer firing failed\n");

	return 0;
}

static void my_exit(void)
{
	int ret;

	ret = del_timer(&my_timer);
	if (ret)
		pr_err("Timer is still in use...\n");

	pr_info("Timer module unloaded\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("Thiyagarajan P <psvthiyagarajan@gmail.com>");
MODULE_DESCRIPTION("Standard timer example");
MODULE_LICENSE("GPL");
