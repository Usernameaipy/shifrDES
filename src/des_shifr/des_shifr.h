#ifndef STDIO_H_LIB_H_INT
#define STDIO_H_LIB_H_INT
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#endif
#ifndef DES_SHIFR_H
#define DES_SHIFR_H
#include "../input/input.h"
#include "des_IP_FP.h"
#include "des_block.h"
#include "des_blocksplit_64_32.h"
#include "feistel_cipher/feistel_cipher.h"
#include "keys.h"
#include "split_and_print.h"
#define KEY_DES "DESkey56"
void des(void);
#endif