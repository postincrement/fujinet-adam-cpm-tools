#include <stdio.h>
#include "../debug.h"
#include "../network.h"

/**
 * @brief Write to serial port
 * @param buf Buffer to write
 * @param len Buffer length
 * @param returns DCB status
 */
unsigned char serial_write(unsigned char *buf, unsigned short len)
{
  if (debug_enabled()) {
    printf("\nSERIAL WRITE:");
    for (int i = 0; i < len; ++i) {
        printf(" %02x", buf[i]);
    }
    printf("\n");
  }

#if __UNIX__
  for (int i = 0; i < len; ++i) {
    printf(" %02x", buf[i]);
  }
#endif  

#if __CPM__
  for (int i = 0; i < len; ++i) {
    bdos()
    printf(" %02x", buf[i]);
  }
#endif  

#if 0    
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
  #endif

  return 0;

}
