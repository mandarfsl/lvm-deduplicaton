/*
 * Copyright (C) 2005-2007 Red Hat GmbH
 *
 * A target that delays reads and/or writes and can send
 * them to different devices.
 *
 * This file is released under the GPL.
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/blkdev.h>
#include <linux/bio.h>
#include <linux/slab.h>

#include <linux/completion.h>
#include <linux/err.h>
#include <linux/kernel.h>
#include <linux/mempool.h>
#include <linux/workqueue.h>
#include <linux/backing-dev.h>
#include <linux/percpu.h>
#include <linux/atomic.h>
#include <linux/scatterlist.h>
#include <asm/page.h>
#include <asm/unaligned.h>
#include <crypto/hash.h>
#include <crypto/md5.h>
#include <crypto/algapi.h>

#include <linux/device-mapper.h>

#define DM_MSG_PREFIX "dedup"

/*
 * Mapping parameters:
 *    <device> <offset> <delay> [<write_device> <write_offset> <write_delay>]
 *
 * With separate write parameters, the first set is only used for reads.
 * Delays are specified in milliseconds.
 */
static int dedup_ctr(struct dm_target *ti, unsigned int argc, char **argv)
{
	printk(KERN_ERR "MJ we come in dedup_ctr.\n");
	return 0;
}

static void dedup_dtr(struct dm_target *ti)
{
	printk(KERN_ERR "MJ we come in dedup_dtr.\n");
}

/*
static void dedup_map_request(struct dm_target *ti, struct request *clone,
				union map_info *map_context)
{
	printk(KERN_ERR "MJ dedup_map_request.\n");
}
*/

static int dedup_end_io(struct dm_target *ti, struct bio *bio,
			int error, union map_info *map_context)
{
	printk(KERN_ERR "MJ dedup_end_io\n");
	return 0;
}

static int dedup_rq_end_io(struct dm_target *ti, struct request *clone,
			   int error, union map_info *map_context)
{
	printk(KERN_ERR "MJ dedup_rq_end_io\n");
	return 0;
}

static void dedup_postsuspend(struct dm_target *ti)
{
	printk(KERN_ERR "MJ dedup_postsuspend\n");

}

static int dedup_preresume(struct dm_target *ti)
{
	printk(KERN_ERR "MJ dedup_preresume\n");
	return 0;

}

static int dedup_message(struct dm_target *ti, unsigned argc, char **argv)
{
	printk(KERN_ERR "MJ dedup_message\n");
	return 0;

}

static int dedup_ioctl(struct dm_target *ti, unsigned int cmd, unsigned long arg)
{
	printk(KERN_ERR "MJ dedup_ioctl\n");
	return 0;

}

static int dedup_merge(struct dm_target *ti, struct bvec_merge_data *bvm,
			struct bio_vec *biovec, int max_size)
{
	printk(KERN_ERR "MJ dedup_merge\n");
	return 0;

}

static void dedup_io_hints(struct dm_target *ti, struct queue_limits *limits)
{
	printk(KERN_ERR "MJ dedup_io_hints\n");

}

static void dedup_presuspend(struct dm_target *ti)
{
	printk(KERN_ERR "MJ we come in dedup_presuspend.\n");
}

static void dedup_resume(struct dm_target *ti)
{
	printk(KERN_ERR "MJ we come in dedup_resume.\n");
}

static int dedup_map(struct dm_target *ti, struct bio *bio,
		     union map_info *map_context)
{
	printk(KERN_ERR "MJ we come in dedup_map.\n");
	return DM_MAPIO_SUBMITTED;	// MJ-Icant call remapped here, as IO goes into infinite loop.
}

static int dedup_status(struct dm_target *ti, status_type_t type,
			char *result, unsigned maxlen)
{
	printk(KERN_ERR "MJ we come in dedup_status.\n");
	return 0;
}

/*
void lvm_dedup(struct request_queue *q, struct bio *bio)
{
	int i;
	struct bio_vec *ptr;

	printk(KERN_ERR "MJ we come in lvm_dedup.\n");
	printk(KERN_ERR "MJ MINOR is %u\n", MINOR(bio->bi_bdev->bd_dev));
	printk(KERN_ERR "MJ bi_vcnt is %hd\n", bio->bi_vcnt);
	printk(KERN_ERR "MJ no. of sectors are %d\n", bio_sectors(bio));
	printk(KERN_ERR "MJ sector index is %u\n", bio->bi_sector);
	printk(KERN_ERR "MJ bi_phys_segments are %u\n", bio->bi_phys_segments);
	printk(KERN_ERR "MJ bi_size is %u\n", bio->bi_size);
	printk(KERN_ERR "MJ bi_max_vecs is %u\n", bio->bi_max_vecs);
	printk(KERN_ERR "MJ bi_cnt is %u\n", bio->bi_cnt);
	printk(KERN_ERR "MJ bi_inline_vecs is %p\n", bio->bi_inline_vecs);

	ptr = bio->bi_io_vec;
	for(i=0;i< bio->bi_vcnt;i++){
		if(ptr != NULL) {
			printk(KERN_ERR "MJ ptr->bv_len is %u\n", ptr->bv_len);
			printk(KERN_ERR "MJ ptr->bv_offset is %u\n", ptr->bv_offset);
			ptr += 1;	 Comment=Point to next bio_vec 
		}
	}


}
EXPORT_SYMBOL(lvm_dedup);
*/

static int dedup_iterate_devices(struct dm_target *ti,
				 iterate_devices_callout_fn fn, void *data)
{
	printk(KERN_ERR "MJ WE come in dedup_iterate_devices.\n");
	return 0;
}

static struct target_type dedup_target = {
	.name	     = "dedup",
	.version     = {1, 1, 0},
	.module      = THIS_MODULE,
	.ctr	     = dedup_ctr,
	.dtr	     = dedup_dtr,
	.map	     = dedup_map,
//	.map_rq	     = dedup_map_request, NOTE: Observed panic if we define this function,
//						Also, this is for request based DM's,
//						I am thinking that we can be bio based.
	.end_io	     = dedup_end_io,
	.rq_end_io   = dedup_rq_end_io,
//	.flush	     = dedup_flush,
	.presuspend  = dedup_presuspend,
	.postsuspend = dedup_postsuspend,
	.preresume   = dedup_preresume,
	.message     = dedup_message,
	.ioctl	     = dedup_ioctl,
	.merge	     = dedup_merge,
//	.busy	     = dedup_busy,
	.resume	     = dedup_resume,
	.status	     = dedup_status,
	.iterate_devices = dedup_iterate_devices,
	.io_hints        = dedup_io_hints,
};

static int __init dm_dedup_init(void)
{
	int r;

	r = dm_register_target(&dedup_target);
	if (r < 0) {
		DMERR("register failed %d", r);
	}
	printk(KERN_ERR "MJ WE come in dedup_init.\n");
	return r;
}

static void __exit dm_dedup_exit(void)
{
	dm_unregister_target(&dedup_target);
	printk(KERN_ERR "MJ WE come in dedup_exit.\n");
}

/* Module hooks */
module_init(dm_dedup_init);
module_exit(dm_dedup_exit);

MODULE_DESCRIPTION(DM_NAME " deduplication target");
MODULE_AUTHOR("Mandar Joshi <mandar.sh.joshi@gmail.com>");
MODULE_LICENSE("GPL");
