/**
 * nsh - the N: Shell
 *
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license GPL v. 3 (see LICENSE.md)
 */

#include <stdio.h>
#include "nsh.h"

#if __CPM__
void banner(void)
{
  printf("\x1b" "E" "Welcome to N:\n\nTYPE 'HELP' FOR COMMANDS.\n\n");
}

void main(void)
#endif

#if __UNIX__
void banner(void)
{
  printf("Welcome to N:\n\nTYPE 'HELP' FOR COMMANDS.\n\n");
}
int main(int argc, char *argv[])
#endif
{
  banner();
  
  while (1)
    nsh();
}
