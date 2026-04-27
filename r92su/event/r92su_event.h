#ifndef __R92SU_EVENT_H__
#define __R92SU_EVENT_H__

#include <linux/types.h>
#include "api/r92su_def.h"

void r92su_event_parse(struct r92su *r92su, const u8 *data, unsigned int len);

#endif