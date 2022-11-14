.RECIPEPREFIX = > 
COMMON_FLAGS = -Wall -Wextra
SRC = printer.cc task_1.cc

CC = gcc
CFLAGS=$(COMMON_FLAGS)

CXX = g++
CXXFLAGS = $(COMMON_FLAGS)

.PHONY: all
all: cxx_version

.PHONY: cxx_version
cxx_version: $(SRC)
> $(CXX) $(CXXFLAGS) -DUSE_CXX $^ -o main

.PHONY: c_version
c_version: $(SRC)
> $(CC) $(CFLAGS) $^ -o main

.PHONY: test
test:
> ./main 1 2 3
> ./main 1 2 d
> ./main 12.3 -34 5
> ./main 1000000 1000000 0

.PHONY: clean
clean:
> rm main

