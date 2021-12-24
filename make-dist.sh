#!/bin/bash

BLANK=dist/blank160.dsk
DSK=dist/fnc-tools-adam-cpm.dsk
CP="cpmcp -f adam $DSK"

rm -f $DSK
cp $BLANK $DSK
$CP finfo/finfo.com 0:finfo.com
$CP feject/feject.com 0:feject.com
$CP fld/fld.com 0:fld.com
$CP flh/flh.com 0:flh.com
$CP fmount/fmount.com 0:fmount.com
$CP fnew/fnew.com 0:fnew.com
$CP README.md 0:README.TXT
$CP LICENSE 0:LICENSE.TXT

