#include "task_1.hpp"

#ifdef USE_CXX
#include <array>
#include <cassert>
#include <iostream>
constexpr int MAX_ARGS_COUNT = 10;
using arrayT = std::array<double, MAX_ARGS_COUNT>;

#else
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_ARGS_COUNT 10
typedef double elemT;
#endif

enum OperationType {
    SUM = 0,
    MUL = 1,
    AVG = 2,
};

#ifndef USE_CXX

int getInput_(elemT *array, int argsNum, int argc, char **argv) {
    assert(array != NULL);
    assert(argsNum <= MAX_ARGS_COUNT);
    assert((argc > 1 && argsNum == argc - 1) || argc == 1);
    for (int i = 0; i < argsNum; ++i) {
        if (argc == 1) {
            if (scanf("%lf", array + i) != 1) {
                array[i] = 0.;
            };
        } else {
            array[i] = atof(argv[i + 1]);
        }
    }
    return 0;
}

void printResult_(OperationType op, const elemT *array, int argsNum) {
    assert(array != NULL);
    assert(argsNum <= MAX_ARGS_COUNT);
    double result = 0.0;
    switch (op) {
    case SUM:
        for (int i = 0; i < argsNum; ++i) {
            result += array[i];
        }
        for (int i = 0; i < argsNum - 1; ++i) {
            printf("%f + ", array[i]);
        }
        printf("%f = %f\n", array[argsNum - 1], result);
        break;
    case MUL:
        result = 1.;
        for (int i = 0; i < argsNum; ++i) {
            result *= array[i];
        }
        for (int i = 0; i < argsNum - 1; ++i) {
            printf("%f * ", array[i]);
        }
        printf("%f = %f\n", array[argsNum - 1], result);
        break;
    case AVG:
        for (int i = 0; i < argsNum; ++i) {
            result += array[i];
        }
        result /= argsNum;
        printf("(");
        for (int i = 0; i < argsNum - 1; ++i) {
            printf("%f + ", array[i]);
        }
        printf("%f) / %d = %f\n", array[argsNum - 1], argsNum, result);
    default:
        break;
    }
}

#else
int getInput_(arrayT &array, int argsNum, int argc, char **argv) {
    assert(static_cast<size_t>(argsNum) <= array.size());
    assert((argc > 1 && argsNum == argc - 1) || argc == 1);
    for (auto i = 0; i < argsNum; ++i) {
        if (argc == 1) {
            std::cin >> array[i];
        } else {
            array[i] = std::atof(argv[i + 1]);
        }
    }
    return 0;
}

void printResult_(OperationType op, const arrayT &array, int argsNum) {
    assert(static_cast<size_t>(argsNum) <= array.size());
    double result{0.0};
    switch (op) {
    case SUM:
        for (int i = 0; i < argsNum; ++i) {
            result += array[i];
        }
        for (int i = 0; i < argsNum - 1; ++i) {
            std::cout << array[i] << " + ";
        }
        std::cout << array[argsNum - 1] << " = ";
        std::cout << result;
        break;
    case MUL:
        result = 1.;
        for (int i = 0; i < argsNum; ++i) {
            result *= array[i];
        }
        for (int i = 0; i < argsNum - 1; ++i) {
            std::cout << array[i] << " * ";
        }
        std::cout << array[argsNum - 1] << " = ";
        std::cout << result;
        break;
    case AVG:
        for (int i = 0; i < argsNum; ++i) {
            result += array[i];
        }
        result /= argsNum;
        std::cout << "(";
        for (int i = 0; i < argsNum - 1; ++i) {
            std::cout << array[i] << " + ";
        }
        std::cout << array[argsNum - 1] << ") / ";
        std::cout << argsNum;
        std::cout << " = " << result;
        break;
    default:
        assert(false);
    }
    std::cout << std::endl;
}

#endif

void runTask(int argsNum, const int argc, char **argv) {
#ifdef USE_CXX
    // std::cout << "using CXX API\n" << std::endl;
    std::array<double, MAX_ARGS_COUNT> array{0};
#else
    // printf("using C API\n");
    double array[MAX_ARGS_COUNT] = {0};
#endif
    getInput_(array, argsNum, argc, argv);
    printResult_(SUM, array, argsNum);
    printResult_(MUL, array, argsNum);
    printResult_(AVG, array, argsNum);
}