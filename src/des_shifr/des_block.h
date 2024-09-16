#ifndef STDIO_H_LIB_H_INT
#define STDIO_H_LIB_H_INT
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#endif
#ifndef STRING_H
#define STRING_H
#include "string.h"
#endif
#ifndef DES_BLOCK_H
#define DES_BLOCK_H
#define BLOCK_SIZE 8
#include "../matrix/matrix.h"
uint8_t** division_into_blocks(char*, int*);
#endif