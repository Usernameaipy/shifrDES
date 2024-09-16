#include "des_block.h"

uint64_t** division_into_blocks(uint8_t* message, int* num_blocks){
    int symbol = 0;
    for(int i = 0; message[i]!='\0'; i++){
        symbol+=1;
    }
    int blocks = (symbol%BLOCK_SIZE==0) ? symbol/BLOCK_SIZE : symbol/BLOCK_SIZE+1;
    *num_blocks=blocks;
    uint64_t **matrix=creat_new_matrix(blocks);
    fiil_matrix(matrix, message, blocks);
    return matrix;
}