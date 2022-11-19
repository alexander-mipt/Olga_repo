.RECIPEPREFIX = > 
COMMON_FLAGS = -Wall -Wextra -g #-DUNSIGNED_VARIANT
SRC = main.c

CC = gcc
CFLAGS=$(COMMON_FLAGS)

CXX = g++
CXXFLAGS = $(COMMON_FLAGS)

.PHONY: all
all: $(SRC)
> $(CC) $(CFLAGS) $^ -o main

.PHONY: test
test: main input.txt
> ./main < input.txt