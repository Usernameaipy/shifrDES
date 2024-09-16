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
uint8_t **creat_new_matrix(int, int);
uint8_t **fiil_matrix(uint8_t **, char *, int, int);
void delete_matrix(uint8_t **);
#endif