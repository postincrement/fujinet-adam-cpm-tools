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
#include "pwd.h"
#include "network.h"

extern unsigned char response[1024];

void pwd(void)
{
  unsigned char c='0'; // 0x30 PWD
  unsigned char r=TRANSPORT_WRITE(&c,1);

  if (r!=0x80)
    return;

  memset(response,0,sizeof(response));
  
  r=TRANSPORT_READ(response,sizeof(response));

  if (response[0]==0x00)
    printf("NO PREFIX IS SET\n");
  else
    printf("%s\n",response);
}
