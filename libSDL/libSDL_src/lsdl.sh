#!/bin/sh
if [ ! -d ./ready_libs/SDL2 ] ; then
    mkdir -p build1
    cd build1
    ../libSDL_src/SDL2/configure --prefix /tmp/SDL2/
    make
    make install
    cd ..
    cp -Rf /tmp/SDL2 ./ready_libs/
    rm -rf build1
    rm -rf /tmp/SDL2/
fi