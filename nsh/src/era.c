/**
 * nsh - the N: Shell
 *
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license GPL v. 3 (see LICENSE.md)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "era.h"
#include "input.h"
#include "network.h"

extern char response[1024];

void era(char *s)
{
  char dir[256];
  
  if (s==NULL)
    {
      s=dir;
      printf("URL: ");
      input(s);
    }

  if (s==NULL)
    return;
  
  memset(response,0,sizeof(response));
  
  response[0]='!'; // 0x21

  if (s!=NULL)
    strncpy(&response[1],s,256);
  
  TRANSPORT_WRITE((unsigned char *)response,strlen(response));
}
