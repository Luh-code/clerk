@echo off

cmake -G "MinGW Makefiles" -B ./build -S .
cmake --build ./build
