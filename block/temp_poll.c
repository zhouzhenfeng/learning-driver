	...
	...
	...
static unsigned int xxx_poll(struct file *filp, poll_table *wait)
{
	unsigned int mask = 0;
	struct xxx_dev *dev = filp->private_data;	/* get the device struct pointer */

	...
	poll_wait(filp, &dev->r_wait, wait);	/* add read wait queue */
	poll_wait(filp, &dev->w_wait, wait);	/* add write wait queue */

	if (...)	/* can read */
		mask |= POLLIN | POLLRDNORM;
	
	if (...)	/* can write */
		mask |= POLLOUT | POLLWRNNORM;
	...
	return mask;
}
	...
	...
	...
