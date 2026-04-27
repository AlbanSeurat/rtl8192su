#ifndef __R92SU_CORE_H__
#define __R92SU_CORE_H__

#include <linux/mutex.h>
#include <linux/workqueue.h>
#include <linux/spinlock.h>
#include <linux/completion.h>
#include <linux/llist.h>
#include <net/cfg80211.h>
#include <linux/ieee80211.h>
#include <linux/usb.h>

#include "api/r92su_def.h"
#include "../eeprom.h"
#include "../fw.h"
#include "../debugfs.h"

#define R92SU_DRVNAME		"r92su"
#define RTL8192SU_FIRMWARE	"rtl8712u.bin"

struct r92su_ops;

struct r92su {
	struct r92su_trans *trans;

	struct usb_interface *intf;
	struct usb_device *udev;
	struct usb_anchor rx_submitted;
	struct usb_anchor tx_wait;
	struct usb_anchor tx_submitted;
	atomic_t tx_pending_urbs;
	unsigned int ep_num;

	struct mutex lock;
	struct workqueue_struct *wq;
	enum r92su_state_t state;
	struct wireless_dev wdev;
	struct ieee80211_channel *current_channel;
	struct delayed_work service_work;

	unsigned int h2c_seq:7;
	unsigned int c2h_seq:7;
	spinlock_t tx_cmd_lock;

	spinlock_t rx_path;
	unsigned int ampdu_reference;
	struct sk_buff_head rx_queue;
	struct tasklet_struct rx_tasklet;
	unsigned int rx_alignment;

	unsigned int sta_generation;
	unsigned int sta_num;
	struct list_head sta_list;
	struct spinlock sta_lock;

	struct ieee80211_supported_band band_2GHZ;

	struct cfg80211_scan_request *scan_request;
	struct c2h_join_bss_event *connect_result;
	struct cfg80211_bss *wep_shared_bss;
	struct cfg80211_bss *want_connect_bss;
	struct cfg80211_bss __rcu *connect_bss;
	struct work_struct connect_bss_work;
	struct delayed_work survey_done_work;
	struct completion scan_done;
	struct llist_head add_bss_list;
	struct work_struct add_bss_work;
	struct work_struct disconnect_work;
	bool scanned;

	struct r92su_eeprom eeprom;
	enum r92su_eeprom_type eeprom_type;
	enum r92su_chip_revision_t chip_rev;
	enum r92su_rf_type_t rf_type;

	const struct firmware *fw;
	const struct fw_hdr *fw_header;
	const void *fw_imem;
	const void *fw_sram;
	u32 fw_imem_len;
	u32 fw_sram_len;
	u16 fw_version;
	struct fw_priv fw_dmem;
	bool fw_loaded;
	bool disable_ht;

	struct input_dev *wps_pbc;
	bool wps_pbc_state;

	u8 rpwm;
	u8 rpwm_tog;
	u8 cpwm;
	u8 cpwm_tog;

	struct dentry *dfs;
	struct r92su_debug debug;
};

static inline bool r92su_is_dead(struct r92su *r92su)
{
	return r92su->state == R92SU_DEAD;
}

static inline bool r92su_is_probing(struct r92su *r92su)
{
	return r92su->state >= R92SU_PROBE;
}

static inline bool r92su_is_initializing(struct r92su *r92su)
{
	return r92su->state >= R92SU_INIT;
}

static inline bool r92su_is_stopped(struct r92su *r92su)
{
	return r92su->state == R92SU_STOP;
}

static inline bool r92su_is_open(struct r92su *r92su)
{
	return r92su->state >= R92SU_OPEN;
}

static inline bool r92su_is_connected(struct r92su *r92su)
{
	return r92su->state >= R92SU_CONNECTED;
}

static inline void r92su_set_state(struct r92su *r92su, enum r92su_state_t new_state)
{
	r92su->state = new_state;
}

static inline void r92su_mark_dead(struct r92su *r92su)
{
	struct net_device *ndev = r92su->wdev.netdev;
	r92su_set_state(r92su, R92SU_DEAD);
	if (ndev)
		netif_carrier_off(ndev);
}

struct r92su *r92su_alloc(struct device *main_dev);
int r92su_setup(struct r92su *r92su);
int r92su_register(struct r92su *r92su);
void r92su_unregister(struct r92su *r92su);
void r92su_free(struct r92su *r92su);
void r92su_disconnect_bss_event(struct r92su *r92su);

#endif