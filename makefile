CXX = clang++
CXXFLAGS = -std=c++20 -Iinclude
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
