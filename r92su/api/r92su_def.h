/******************************************************************************
 *
 * Copyright(c) 2009-2013  Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 * The full GNU General Public License is included in this distribution in the
 * file called LICENSE.
 *
 *****************************************************************************/
#ifndef __R92SU_API_DEF_H__
#define __R92SU_API_DEF_H__

#include <linux/types.h>

#define RX_MPDU_QUEUE				0
#define RX_CMD_QUEUE				1
#define RX_MAX_QUEUE				2
#define NUM_ACS					4

#define SHORT_SLOT_TIME				9
#define NON_SHORT_SLOT_TIME			20

#define	PHY_RSSI_SLID_WIN_MAX			100
#define	PHY_LINKQUALITY_SLID_WIN_MAX		20
#define	PHY_BEACON_RSSI_SLID_WIN_MAX		10

/* Tx Desc */
#define TX_DESC_SIZE				32

#define QSLT_BK					0x1
#define QSLT_BE					0x3
#define QSLT_VI					0x5
#define QSLT_VO					0x7
#define QSLT_BEACON				0x10
#define QSLT_HIGH				0x11
#define QSLT_MGNT				0x12
#define QSLT_CMD				0x13

enum r92su_state_t {
	R92SU_DEAD,
	R92SU_UNLOAD,
	R92SU_PROBE,
	R92SU_STOP,
	R92SU_INIT,
	R92SU_OPEN,
	R92SU_CONNECTED,
};

enum r92su_chip_revision_t {
	R92SU_FPGA  = 0,
	R92SU_A_CUT = 1,
	R92SU_B_CUT = 2,
	R92SU_C_CUT = 3,
	__R92SU_MAX_REV
};

enum r92su_rf_type_t {
	R92SU_1T1R = 0x11,
	R92SU_1T2R = 0x12,
	R92SU_2T2R = 0x22
};

enum ieee80211_ac_numbers {
	IEEE80211_AC_VO         = 0,
	IEEE80211_AC_VI         = 1,
	IEEE80211_AC_BE         = 2,
	IEEE80211_AC_BK         = 3,
};

static const int ieee802_1d_to_ac[8] = {
	IEEE80211_AC_BE,
	IEEE80211_AC_BK,
	IEEE80211_AC_BK,
	IEEE80211_AC_BE,
	IEEE80211_AC_VI,
	IEEE80211_AC_VI,
	IEEE80211_AC_VO,
	IEEE80211_AC_VO
};

#endif