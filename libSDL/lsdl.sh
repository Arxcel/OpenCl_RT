#!/bin/sh
if [ ! -d ~/SDL_INVADERS/SDL2 ] ; then
    mkdir -p build
    cd build
    ../SDL2/configure --prefix ~/SDL_INVADERS/SDL2/
    make
    make install
    cd ..
    rm -rf build
fi