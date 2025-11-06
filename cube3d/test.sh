#!/bin/bash

# Script de test pour cube3D

if [ "$1" == "debug" ]; then
    echo "🔍 Mode DEBUG activé"
    sed -i 's/# define DEBUG 0/# define DEBUG 1/' include/cube3d.h
    make
    ./cube3d test.cub
elif [ "$1" == "3d" ]; then
    echo "🎮 Mode 3D activé"
    sed -i 's/# define DEBUG 1/# define DEBUG 0/' include/cube3d.h
    make
    ./cube3d test.cub
else
    echo "Usage: $0 [debug|3d]"
    echo "  debug - Lance en mode debug (vue 2D de dessus)"
    echo "  3d    - Lance en mode 3D normal"
fi
