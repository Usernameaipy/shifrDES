#include "des_blocksplit_64_32.h"

void splits_block_64_32(uint64_t block, uint32_t* block_left, uint32_t* block_right){
    *block_left=(uint32_t)(block >> 32);
    *block_right=(uint32_t)(block);
}

uint64_t join_32_64(uint32_t left_block, uint32_t right_block){
    uint64_t new_block = 0;
    new_block = (uint64_t)(left_block);
    new_block = (uint64_t)(new_block << 32) | right_block;
    return new_block;
}