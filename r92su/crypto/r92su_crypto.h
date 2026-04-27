#ifndef __R92SU_CRYPTO_H__
#define __R92SU_CRYPTO_H__

#include <linux/types.h>
#include "api/r92su_def.h"

int r92su_wep_encrypt(struct r92su *r92su, struct sk_buff *skb, const u8 key[], int keylen);
int r92su_wep_decrypt(struct r92su *r92su, struct sk_buff *skb, const u8 key[], int keylen);
int r92su_tkip_encrypt(struct r92su *r92su, struct sk_buff *skb, const u8 key[], int keylen);
int r92su_tkip_decrypt(struct r92su *r92su, struct sk_buff *skb, const u8 key[], int keylen);
int r92su_aes_encrypt(struct r92su *r92su, struct sk_buff *skb, const u8 key[], int keylen);
int r92su_aes_decrypt(struct r92su *r92su, struct sk_buff *skb, const u8 key[], int keylen);

#endif