# Steps to build
mkdir -p build
cd build
cmake ..

cmake --build .
./main

cd ..
make r // from Makefile