#include "des_IP_FP.h"

void perm_IP(uint64_t **matrix, int nun_blocks){
    for(int i = 0; i<nun_blocks; i++){
        matrix[i][0]=init_per_IP(matrix[i][0]);
    }
}

void perm_FP(uint64_t **matrix, int nun_blocks){
    for(int i = 0; i<nun_blocks; i++){
        matrix[i][0]=init_per_FP(matrix[i][0]);
    }
}

uint64_t init_per_IP(uint64_t block){
    uint64_t new_block=0;
    for(int j = 0; j<64; ++j){
        new_block |= ((block >> (64-IP[j])) & 0x01) << (63-j);
    }
    return new_block;
}

uint64_t init_per_FP(uint64_t block){
    uint64_t new_block=0;
    for(int j = 0; j<64; ++j){
        new_block |= ((block >> (64-FP[j])) & 0x01) << (63-j);
    }
    return new_block;
}