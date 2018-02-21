#!/bin/sh
if [ ! -d ./ready_libs/SDL2_image ] ; then
	path=$(pwd)
    mkdir -p build2
    cd build2
    ../libSDL_src/SDL2_image/configure --prefix $path/ready_libs/SDL2_image/
    make
    make install
    cd ..
    rm -rf build2
fi