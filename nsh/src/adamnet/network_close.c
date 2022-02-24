/**
 * Close Connection
 *
 * @return status
 */

#include <stdio.h>
#include <string.h>
#include "../network.h"
#include "dcb.h"
#include "find_dcb.h"
#include "../debug.h"
#include "../platform.h"
#include "adamnet_write.h"

unsigned char network_close(void)
{
  unsigned char resp='C';

  if (debug_enabled())
    printf("\nNETWORK CLOSE\n");
  
  return adamnet_write(&resp,1);
}
