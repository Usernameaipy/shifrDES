#include "des_blocksplit_64_32.h"

void splits_block_64_32(uint64_t block, uint32_t* block_left, uint32_t* block_right){
    *block_left=(uint32_t)(block >> 32);
    *block_right=(uint32_t)(block);
}