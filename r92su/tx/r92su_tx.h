#ifndef __R92SU_TX_H__
#define __R92SU_TX_H__

#include <linux/skbuff.h>
#include "api/r92su_def.h"

struct r92su_tx_info {
	u8 mac_id;
	u8 qos;
	u8 ack_policy;
	u8 mcs;
	u16 sequence;
};

int r92su_tx(struct r92su *r92su, struct sk_buff *skb, u8 qos);

#endif