.RECIPEPREFIX = > 
COMMON_FLAGS = -Wall -Wextra -g
SRC = main.c

CC = gcc
CFLAGS=$(COMMON_FLAGS)

CXX = g++
CXXFLAGS = $(COMMON_FLAGS)

.PHONY: all
all: $(SRC)
> $(CC) $(CFLAGS) $^ -o main

.PHONY: test
test: main input0.txt input2_1.txt input2_2.txt input2_3.txt input3.txt
> ./main < input0.txt
> ./main < input2_1.txt
> ./main < input2_2.txt
> ./main < input2_3.txt
> ./main < input3.txt