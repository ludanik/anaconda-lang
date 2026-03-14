CXX := g++
CXXFLAGS := -g -O3 $(shell llvm-config --cxxflags)
LDFLAGS := $(shell llvm-config --ldflags --system-libs --libs core orcjit native)

SRC_DIR := src
TARGET := $(SRC_DIR)/anaconda

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC_DIR)/main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGET)
