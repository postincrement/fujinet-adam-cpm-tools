/**
 * Read from channel 
 *
 * @param buf Buffer
 * @param len length
 * @return adamnet status code
 */

#include <string.h>
#include "dcb.h"
#include "find_dcb.h"
#include "../network.h"
#include "../platform.h"

extern unsigned char response[1024];

unsigned short network_read(unsigned char *buf, unsigned short len)
{
  DCB *dcb = find_dcb();
  unsigned char r=adamnet_read(response,sizeof(response));
  
  if (r == 0x80)
    {
      memcpy(buf,response,dcb->len);
      return dcb->len;
    }
  else
    return 0;
}
