#!/bin/sh
SRC=uboot
CROSS_COMPILE=arm-none-linux-gnueabi-
ARCH=arm
DEFAULT_CONFIG=""

case "$1" in
    clean)
        echo -n "Starting $SRC make $1"
        make CROSS_COMPILE=$CROSS_COMPILE ARCH=$ARCH distclean
        echo "."
        ;;
    uboot)
        echo -n "Starting $SRC make $1"
        make CROSS_COMPILE=$CROSS_COMPILE ARCH=$ARCH da850evm_config;make CROSS_COMPILE=$CROSS_COMPILE ARCH=$ARCH all
        echo "."
        ;;
    *)
        echo "Usage: $0 {clean|uboot}"
        exit 1
        ;;
esac

exit 0


#DAEMON=/usr/sbin/pcscd
#NAME=pcscd
#DESC="PCSC Daemon"
#PIDFILE=/var/run/pcscd/pcscd.pid
#ARGS=""
#test -f $DAEMON || exit 0
