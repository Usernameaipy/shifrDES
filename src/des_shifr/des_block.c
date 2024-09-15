#include "des_block.h"

char** division_into_blocks(char* message){
    int symbol = strlen(message);
    int blocks = (symbol%BLOCK_SIZE==0) ? symbol/BLOCK_SIZE : symbol/BLOCK_SIZE+1;
    char **matrix=creat_new_matrix(blocks, BLOCK_SIZE+1);
    fiil_matrix(matrix, message, blocks, BLOCK_SIZE);
    return matrix;
}