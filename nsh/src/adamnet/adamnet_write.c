#include <stdio.h>
#include "find_dcb.h"
#include "dcb.h"
#include "../debug.h"

/**
 * @brief Write to Network device
 * @param buf Buffer to write
 * @param len Buffer length
 * @param returns DCB status
 */
unsigned char adamnet_write(char *buf, unsigned short len)
{
  DCB *dcb = find_dcb();

  if (debug_enabled())
    printf("\nADAMNET WRITE: %u BYTES INTO %p\n",len,buf);
    
  while (1)
    {
      dcb->len = len;
      dcb->buf = buf;
      dcb->status = 3; // write
      
      while (dcb->status < 0x80);

      if (dcb->status != 0x9B)
	break;
    }
  
  return dcb->status;
}
