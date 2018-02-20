#!/bin/sh
if [ ! -d ~/SDL_INVADERS/SDL2_image ] ; then
    mkdir -p build
    cd build
    ../SDL2/configure --prefix ~/SDL_INVADERS/SDL2_image/
    make
    make install
    cd ..
    rm -rf build
fi