#ifndef __R92SU_FW_H__
#define __R92SU_FW_H__

#include <linux/types.h>
#include <linux/firmware.h>

#include "api/r92su_def.h"

#define RTL8192SU_FIRMWARE	"rtl8712u.bin"

struct fw_hdr {
	__le32 signature;
	__le32 version;
	__le32 dmemap;
	__le32 textmap;
	__le32 textlen;
	__le32 piltxmap;
	__le32 piltxlen;
	__le32 secmap;
	__le32 seclen;
	__le32 kermap;
	__le32 kerlen;
	__le32 rsvd;
	__le32 imgend;
} __attribute__((packed));

struct fw_priv {
	__le32 mold_id;
	__le32 nic_cap;
	__le32 proto_ver;
	__le32 fw_para;
	u8 mp_mode;
	u8 qos_en;
	__le16 resv;
	__le32 insize;
	__le32 rsvd2[3];
} __attribute__((packed));

int r92su_fw_download(struct r92su *r92su);
void r92su_fw_free(struct r92su *r92su);

#endif