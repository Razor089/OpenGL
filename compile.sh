#!/bin/zsh

echo 'Compling main.cpp...'
g++ src/*.cpp -framework OpenGL -framework GLUT -o bin/Glew -Wno-deprecated-declarations
echo 'Finished! Output file is in bin/ directory.'
