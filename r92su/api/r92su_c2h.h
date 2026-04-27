#ifndef __R92SU_API_C2H_H__
#define __R92SU_API_C2H_H__

#include <linux/types.h>
#include <linux/ieee80211.h>

enum c2h_join_network_types_t {
	WIRELESS_INVALID	= 0,
	WIRELESS_11B		= 1,
	WIRELESS_11G		= 2,
	WIRELESS_11BG		= (WIRELESS_11B | WIRELESS_11G),
	WIRELESS_11A		= 4,
	WIRELESS_11N		= 8,
	WIRELESS_11GN		= (WIRELESS_11G | WIRELESS_11N),
	WIRELESS_11BGN	= (WIRELESS_11B | WIRELESS_11G | WIRELESS_11N),
};

struct c2h_join_bss_event {
	__le32 head;
	__le32 tail;
	__le32 network_type;
	__le32 fixed;
	__le32 last_scanned;
	__le32 aid;
	__le32 join_result;
	struct h2cc2h_bss bss;
} __packed;

struct c2h_survery_done_event {
	__le32 bss_cnt;
} __packed;

struct c2h_sta_key_event {
	u8 mac_addr[ETH_ALEN];
	u8 keyid;
	u8 rsvd;
};

void r92su_c2h_parse(struct r92su *r92su, const u8 *data, unsigned int len);

#endif