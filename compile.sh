#!/bin/zsh

echo 'Compling main.cpp...'
g++ src/*.cpp -framework OpenGL -framework GLUT -o bin/Pong -Wno-deprecated-declarations \
-Wno-nonportable-include-path
echo 'Finished! Output file is in bin/ directory.'
