# Uncomment lines below if you have problems with $PATH
#SHELL := /bin/bash
#PATH := /usr/local/bin:$(PATH)

#adding all files
SOURCES = $(wildcard src/*.cpp) $(wildcard lib/*/*.cpp) $(wildcard test/*.cpp)
HEADERS = $(wildcard lib/*/*.h *.hpp)

# linting using cpplint for python: https://github.com/google/styleguide/tree/gh-pages/cpplint
lint:
	 python cpplint.py ${HEADERS} ${SOURCES}

# perform unit test
test:
	platformio test

# build then upload to device, print size of the sections in a firmware/program
all:
	platformio run -t upload -t size

# clean project
clean:
	platformio run -t clean

# Check or update installed PIO Core packages, Development Platforms and global Libraries. 
update:
	platformio -f update

# Print makefile variable, use for debugging
print-%  : ; @echo $* = $($*)
