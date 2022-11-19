#include <stdio.h>
#include <assert.h>
#include <stdint.h>

enum {
    ERR,
    OK,
};

int load_numbers3(int *arr);
int get_identical_count3(const int* arr);
void print_nunmbers3(const int* arr);

int main() {
    int arr[3] = {0};
    assert(load_numbers3(arr));
    print_nunmbers3(arr);
    printf("Identical num count: %d\n", get_identical_count3(arr));
}

int load_numbers3(int *arr) {
    assert(arr != NULL);
    for (int i = 0; i < 3; ++i) {
        if (scanf("%d", arr + i) != 1) {
            return ERR;
        }
    }
    return OK;
}

int format_result(int x) {
    int bit0 = x & 1;
    int bit1 = (x >> 1) & 1;
    int xor = bit0 ^ bit1;
    return x + xor;
}

int get_identical_count3(const int* arr) {
    assert(arr != NULL);
    int result = 0;
    for (int i = 0 ; i < 3; ++i) {
        result += (arr[i%3] == arr[(i+1)%3]);
    }
    return format_result(result);
}

void print_nunmbers3(const int* arr) {
    assert(arr != NULL);
    for (int i = 0; i < 3; ++i) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}