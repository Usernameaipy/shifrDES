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
#ifndef MATRIX_H
#define MATRIX_H
uint64_t **creat_new_matrix(int, int);
uint64_t **fiil_matrix(uint64_t **, char *, int, int);
void delete_matrix(uint64_t **);
#endif