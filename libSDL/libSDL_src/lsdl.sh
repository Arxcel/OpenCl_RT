#!/bin/sh
if [ ! -d ./ready_libs/SDL2 ] ; then
	path=$(pwd)
    mkdir -p build1
    cd build1
    ../libSDL_src/SDL2/configure --prefix $path/ready_libs/SDL2
    make
    make install
    cd ..
    rm -rf build1
fi