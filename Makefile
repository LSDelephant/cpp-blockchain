.PHONY: all build clean run test docker


all: build


build:
mkdir -p build && cd build && cmake .. && make


run: build
./build/node


test: build
./build/test_chain


docker:
docker build -t cpp-blockchain .


clean:
rm -rf build
