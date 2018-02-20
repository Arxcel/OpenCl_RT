#!/bin/sh
if [ ! -d ./ready_libs/SDL2_image ] ; then
    mkdir -p build2
    cd build2
    ../libSDL_src/SDL2_image/configure --prefix /tmp/SDL2_image/
    make
    make install
    cd ..
    cp -Rf /tmp/SDL2_image ./ready_libs/
    rm -rf build2
    rm -rf /tmp/SDL2_image/
fi