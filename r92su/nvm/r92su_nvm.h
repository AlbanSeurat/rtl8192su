#ifndef __R92SU_NVM_H__
#define __R92SU_NVM_H__

#include <linux/types.h>

#include "api/r92su_def.h"

enum r92su_eeprom_type {
	R92SU_EEPROM_UNINITIALIZED,
	R92SU_EEPROM_93C46,
	R92SU_EEPROM_93C56,
};

enum r92su_eeprom_en {
	R92SU_EEPROM_DBG,
	R92SU_EEPROM_XMT_POWER,
	R92SU_EEPROM_RSSI,
	R92SU_EEPROM_TSSI,
	R92SU_EEPROM_XTAL,
	R92SU_EEPROM_PANIC,
};

struct r92su_eeprom {
	u8 mac_addr[6];
	u8 crystal_cap;
	u8 efuse_use;
	u8 pa_setting;
	u8 lna_type_2g;
	u8 lna_type_5g;

	u8 tx_power_2g[14];
	u8 tx_power_5g[14][2];

	u8 channel_plan;
	u8 country_code[2];
	u8 version;
	u8 resv;

	u8 rfe_op_mode;
};

int r92su_eeprom_read(struct r92su *r92su);

#endif