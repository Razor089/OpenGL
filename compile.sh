#!/bin/zsh

echo 'Compling main.cpp...'
g++ src/*.cpp src/utility/*.cpp -framework OpenGL -framework GLUT -o bin/Pong -Wno-deprecated-declarations \
-Wno-nonportable-include-path -Wno-c++11-compat-deprecated-writable-strings
echo 'Finished! Output file is in bin/ directory.'
