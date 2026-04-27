#ifndef __R92SU_STA_H__
#define __R92SU_STA_H__

#include <linux/types.h>
#include "api/r92su_def.h"

struct r92su_sta {
	struct list_head list;
	u8 mac_addr[6];
	unsigned int generation;
	u8 plcp_hdr[4];
	u64 priv;
};

struct r92su_key {
	u8 type;
	u8 idx;
	bool group;
};

struct r92su_rx_tid {
	u16 seq_start;
};

int r92su_sta_add(struct r92su *r92su, const u8 *mac);
void r92su_sta_remove(struct r92su *r92su, const u8 *mac);
struct r92su_sta *r92su_sta_get(struct r92su *r92su, const u8 *mac);
struct r92su_sta *r92su_sta_get_by_idx(struct r92su *r92su, unsigned int idx);

#endif