#!/bin/sh

make -j$(nproc) || exit

mksquashfs \
    music         \
    res		\
    sfx 	\
    skins	\
    yatka	\
    icon.png                      \
    default.gcw0.desktop yatka-$(date '+%s').opk -noappend
