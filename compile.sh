#!/bin/zsh

echo 'Compling main.cpp...'
g++ src/main.cpp -lGLEW -framework OpenGL -framework GLUT -o bin/Glew
echo 'Finished! Output file is in bin/ directory.'
