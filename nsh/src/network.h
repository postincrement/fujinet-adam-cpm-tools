/**
 * nsh - the N: Shell
 *
 * @author Thomas Cherryhomes
 * @email thom dot cherryhomes at gmail dot com
 * @license GPL v. 3 (see LICENSE.md)
 */

#ifndef NETWORK_H
#define NETWORK_H

unsigned char network_open(char *url, unsigned char mode, unsigned char translation);
unsigned char network_close(void);
unsigned char network_statusbyte(void);
unsigned short network_read(unsigned char *buf, unsigned short len);
unsigned char network_write(unsigned char *buf, unsigned short len);

#if __ADAMNET__

#include "adamnet/adamnet_read.h"
#include "adamnet/adamnet_write.h"

#define TRANSPORT_WRITE     adamnet_write
#define TRANSPORT_READ      adamnet_read

#endif

#if __SERIAL__

#include "serial/serial_read.h"
#include "serial/serial_write.h"

#define TRANSPORT_WRITE     serial_write
#define TRANSPORT_READ      serial_read

#endif


#endif /* NETWORK_H */
