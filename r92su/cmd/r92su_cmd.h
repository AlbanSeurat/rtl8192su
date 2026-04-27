#ifndef __R92SU_CMD_H__
#define __R92SU_CMD_H__

#include <linux/types.h>
#include "api/r92su_def.h"

int r92su_cmd_send(struct r92su *r92su, const void *data, unsigned int len);

#endif