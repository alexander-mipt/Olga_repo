#include "stdio.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STR_LIMIT 1000
typedef long numT;

numT generate_number(numT min, numT max, numT seed);
void print_digits(numT x);

int main() {
    numT x = generate_number(0, RAND_MAX, time(0));
    print_digits(x);
}

numT generate_number(numT min, numT max, numT seed) {
    assert(min <= max);
    srand(seed);
    numT result = (rand() % (max - min + 1)) + min;
    printf("%ld\n", result);
    return result;
}

void print_digits(numT x) {
    char buf[STR_LIMIT] = {0};
    numT chars_saved = snprintf(buf, STR_LIMIT, "%ld", x);
    assert(chars_saved > 0 && chars_saved <= STR_LIMIT);
    for (size_t i = 0; i < strlen(buf) - 1; ++i) {
        printf("%c, ", buf[i]);
    }
    printf("%c\n", buf[strlen(buf) - 1]);
}