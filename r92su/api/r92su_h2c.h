#ifndef __R92SU_API_H2C_H__
#define __R92SU_API_H2C_H__

#include <linux/types.h>
#include <linux/ieee80211.h>

struct h2c_rates {
	u8 rates[8];
} __packed;

struct h2c_ext_rates {
	u8 rates[16];
} __packed;

enum r92su_auth_mode {
	R92SU_AUTH_OPEN = 0,
	R92SU_AUTH_SHARED = 1,
	R92SU_AUTH_8021X = 2,
};

enum h2c_op_modes {
	OP_AUTO = 0,
	OP_ADHOC,
	OP_INFRA,
	__MAC_OP_MODES
};

enum h2c_network_type {
	TYPE_11FH = 0,
	TYPE_11DS,
	TYPE_11OFDM5GHZ,
	TYPE_11OFDM2GHZ,
	__MAX_NETWORK_TYPE
};

struct h2c_key {
	u8 algorithm;
	u8 key_id;
	u8 group_key;
	u8 key[16];
} __packed;

struct h2c_sta_key {
	u8 mac_addr[ETH_ALEN];
	u8 algorithm;
	u8 key[16];
};

struct h2c_add_ba_req {
	__le32 tid;
};

struct h2c_set_mac {
	u8 mac_addr[ETH_ALEN];
} __packed;

struct h2c_join_bss_rpt {
	u8 opmode;
	u8 ps_qos_info;
	u8 bssid[6];
	__le16 bcnitv;
	__le16 aid;
} __packed;

int r92su_h2c_send(struct r92su *r92su, const void *data, unsigned int len);

#endif