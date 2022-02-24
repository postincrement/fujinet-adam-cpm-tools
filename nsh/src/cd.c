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
#include "cd.h"
#include "network.h"

extern  char response[1024];

void cd(char *s)
{
  memset(response,0,sizeof(response));
  
  response[0]=','; // 0x2C

  if (s!=NULL)
    strncpy(&response[1],s,256);
  
  TRANSPORT_WRITE((unsigned char *)response,strlen(response));
}
