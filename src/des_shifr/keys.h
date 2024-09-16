#ifndef STDIO_H_LIB_H_INT
#define STDIO_H_LIB_H_INT
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#endif
#ifndef KEYS
#define KEYS
#define LSHIFT_28BIT(x, L) ((((x) << (L)) | ((x) >> (-(L) & 27))) & (((uint64_t)1 << 32) - 1))
static const uint8_t K1P[28] = {
    57, 49, 41, 33, 25, 17, 9 , 1 , 58, 50, 42, 34, 26, 18,
    10, 2 , 59, 51, 43, 35, 27, 19, 11, 3 , 60, 52, 44, 36,
};

static const uint8_t K2P[28] = {
    63, 55, 47, 39, 31, 23, 15, 7 , 62, 54, 46, 38, 30, 22,
    14, 6 , 61, 53, 45, 37, 29, 21, 13, 5 , 28, 20, 12, 4 ,
};
static const uint8_t CP[48] = {
    14, 17, 11, 24, 1 , 5 , 3 , 28, 15, 6 , 21, 10, 
    23, 19, 12, 4 , 26, 8 , 16, 7 , 27, 20, 13, 2 , 
    41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 
    44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32,
};
uint64_t split_8by_64bi(uint8_t*);
uint8_t *copy_key(char*);
void creat_rounds_key(uint64_t, uint64_t *);
void perm_two_key(uint64_t, uint32_t*, uint32_t*);
void finel_56_key(uint64_t*, uint32_t, uint32_t);
uint64_t join_28b_56b(uint32_t, uint32_t);
uint64_t finel_key_per(uint64_t);
#endif