#ifndef STDIO_H_LIB_H_INT
#define STDIO_H_LIB_H_INT
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#endif
#ifndef SPLIT_AND_PRINT
#define SPLIT_AND_PRINT
uint8_t* split_64bi_8by(uint64_t**, int);
void print(uint8_t*, int);
#endif