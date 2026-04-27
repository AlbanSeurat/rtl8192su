#ifndef __R92SU_USB_H__
#define __R92SU_USB_H__

#include <linux/usb.h>
#include <linux/skbuff.h>

#include "api/r92su_reg.h"
#include "../core/r92su_core.h"

struct r92su_trans_ops {
	int (*write8)(struct r92su *r92su, u32 addr, u8 val);
	int (*write16)(struct r92su *r92su, u32 addr, u16 val);
	int (*write32)(struct r92su *r92su, u32 addr, u32 val);
	int (*read8)(struct r92su *r92su, u32 addr, u8 *val);
	int (*read16)(struct r92su *r92su, u32 addr, u16 *val);
	int (*read32)(struct r92su *r92su, u32 addr, u32 *val);
	int (*write_sync)(struct r92su *r92su, u16 addr, const void *data, u16 size);
	int (*read_sync)(struct r92su *r92su, u16 addr, void *data, u16 size);
	int (*tx)(struct r92su *r92su, struct sk_buff *skb, unsigned int queue);
	int (*start)(struct r92su *r92su);
	void (*stop)(struct r92su *r92su);
};

struct r92su_trans {
	struct device *dev;
	struct r92su *r92su;
	const struct r92su_trans_ops *ops;
	struct usb_device *udev;
	struct usb_interface *intf;
	struct usb_anchor rx_submitted;
	struct usb_anchor tx_wait;
	struct usb_anchor tx_submitted;
	atomic_t tx_pending_urbs;
	unsigned int ep_num;
};

int r92su_usb_init(struct r92su_trans *trans, struct r92su *r92su);
void r92su_usb_exit(struct r92su_trans *trans);

#endif