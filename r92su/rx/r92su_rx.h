#ifndef __R92SU_RX_H__
#define __R92SU_RX_H__

#include <linux/skbuff.h>
#include "api/r92su_def.h"

int r92su_rx(struct r92su *r92su, struct sk_buff *skb);

#endif