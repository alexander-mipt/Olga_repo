#include <stdio.h>

#ifdef UNSIGNED_VARIANT
typedef unsigned month_id_t; // reason why unsigned is a bad choce: try to debug w/ it
#else
typedef int month_id_t;
#endif

void print_month(const month_id_t num);

int main() {
    fprintf(stderr, "For stop press Cntrl+D\n");
    unsigned input = 0;
    while (scanf("%u", &input) > 0) {
        print_month(input);
    }
    return 0;
}

void print_month(const month_id_t idx) {
    const char *months[] = {"winter", "spring", "summer", "autumn"};
    size_t months_size = (int)(sizeof(months) / sizeof(char *));
    if (idx <= 0 || (size_t)((idx + 3) / 4) >= months_size) {
        fprintf(stderr, "%s: %d\n", "Wrong number", idx);
        return;
    }

    month_id_t i = ((idx) / 3) % 4;
    fprintf(stderr, "Season[%d]: %s\n", idx, months[i]);
    return;
}
