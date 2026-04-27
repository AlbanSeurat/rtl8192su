#ifndef __R92SU_PWR_H__
#define __R92SU_PWR_H__

#include <linux/types.h>
#include "api/r92su_def.h"

void r92su_pwr_init(struct r92su *r92su);
int r92su_pwr_set_mode(struct r92su *r92su, u8 mode);

#endif