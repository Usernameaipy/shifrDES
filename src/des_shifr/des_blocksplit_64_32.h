#ifndef STDIO_H_LIB_H_INT
#define STDIO_H_LIB_H_INT
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#endif
#ifndef DES_BLOCK_SPLIT_64_32
#define DES_BLOCK_SPLIT_64_32
void splits_block_64_32(uint64_t, uint32_t*, uint32_t*);
uint64_t join_32_64(uint32_t, uint32_t);
#endif