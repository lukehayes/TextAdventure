#CXX = clang++
CXX = g++
CXXFLAGS = -Iinclude
SRC_DIR = src
LDFLAGS = -L.
OUTPUT = -o bin/app
ENTRY = main.cpp

OBJ     = obj
OBJS    = $(patsubst src/%.cpp, obj/%.o, $(wildcard src/*.cpp))

$(OBJ)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

all: $(OBJS)
	$(CXX) $(CXXFLAGS) $(ENTRY) $^ $(OUTPUT)


# Cleanup
.PHONY:clean
clean:
	rm -rf bin/*
	rm *.o *.a
