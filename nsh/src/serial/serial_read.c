#include <stdio.h>
#include "../network.h"
#include "../debug.h"

#define READ_MAX_LEN 1024

/**
 * @brief Read from Network device
 * @param buf Buffer to read to (must have enough room, 1024 bytes max)
 * @param len Buffer length
 * @param returns DCB status
 */
unsigned char serial_read(unsigned char *buf, unsigned short len)
{
  /*
  DCB *dcb = find_dcb();

  if (debug_enabled())
    printf("\nSERIAL READ: %d BYTES INTO %p\n",len,buf);
  
  while (1)
    {
      dcb->len = READ_MAX_LEN;
      dcb->buf = buf;
      dcb->status = 4; // read
      
      while (dcb->status < 0x80);

      if (dcb->status != 0x9B)
	break;
    }
  
  return dcb->status;
  */
 return 0;
}
