#ifndef DM_DEDUP_H
#define DM_DEDUP_H

extern void lvm_dedup(struct request_queue *q, struct bio *bio);

#endif
