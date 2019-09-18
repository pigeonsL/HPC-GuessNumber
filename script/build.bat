@echo off
pushd .

if not exist build (
     md build
)

cd build
cmake -G"MinGW Makefiles" ..
mingw32-make.exe

popd
