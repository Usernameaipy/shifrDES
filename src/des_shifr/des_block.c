#include "des_block.h"

uint8_t** division_into_blocks(char* message, int* num_blocks){
    int symbol = strlen(message);
    int blocks = (symbol%BLOCK_SIZE==0) ? symbol/BLOCK_SIZE : symbol/BLOCK_SIZE+1;
    *num_blocks=blocks;
    uint8_t **matrix=creat_new_matrix(blocks, BLOCK_SIZE+1);
    fiil_matrix(matrix, message, blocks, BLOCK_SIZE);
    return matrix;
}