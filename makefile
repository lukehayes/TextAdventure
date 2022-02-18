CXX = g++
CXXFLAGS = -std=c++17 -I./include
SRC_DIR = src
LDFLAGS = -L.
OUTPUT = -o bin/app
ENTRY = main.cpp

all:
	$(CXX) $(CXXFLAGS) $(ENTRY) $(OUTPUT)


# Cleanup
.PHONY:clean
clean:
	rm -rf bin/*
	rm *.o *.a
