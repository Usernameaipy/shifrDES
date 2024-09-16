#ifndef STDIO_H_LIB_H_INT
#define STDIO_H_LIB_H_INT
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#endif
#ifndef DES_IP_H
#define DES_IP_H
void perm_IP(uint64_t **, int);
uint64_t init_per_IP(uint64_t);
static const uint64_t IP[64] = {
    58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9 , 1, 59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7,
};
#endif