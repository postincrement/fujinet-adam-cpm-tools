/**
 * Write to channel 
 *
 * @param buf Pointer to buffer, should have +1 more than number of bytes to write.
 * @param len number of actual bytes to write
 * @return number of bytes written
 * @return status
 */

#include <string.h>
#include "../network.h"
#include "../platform.h"

unsigned char network_write(unsigned char *buf, unsigned short len)
{  
  unsigned char r=0;
  while (len>0)
    {
      char out[513]={'W'};
      unsigned short l = len > 128 ? 128 : len;
      
      memcpy(&out[1],buf,l);

      r=TRANSPORT_WRITE((unsigned char *)out,l+1);

      if (r!=0x80)
	break;
      else
	{
	  len -= l;
	}
      
    }
  return r;
}

