/**
 * nsh - the N: Shell
 *
 * @author Craig Southeren
 * @email craig at postincrement dot com
 * @license GPL v. 3 (see LICENSE.md)
 */

#ifndef PLATFORM_H
#define PLATFORM_H

#if __CPM__
#include <conio.h>
#endif /* __CPM__ */

#if __UNIX__
#include <unistd.h>

#define cprintf printf
#define cputc   putchar
#define cgetc   getchar
#define csleep  sleep

int kbhit();

#endif /* __UNIX__ */

#endif /* PLATFORM_H */