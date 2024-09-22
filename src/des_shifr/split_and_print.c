#include "split_and_print.h"

uint8_t* split_64bi_8by(uint64_t** matrix, int num_block){
    uint8_t *des_cipher = malloc(sizeof(uint8_t)*(num_block*8));
    if(des_cipher!=NULL){
        for(int j = 0, n=0;j<num_block; ++j, n+=8){
            for (int i = n; i < n+8  && i<num_block*8; ++i) {
                des_cipher[i] = (uint8_t)(matrix[j][0] >> ((7 - i) * 8));
            }
        }
    }
    return des_cipher;
}

void print(uint8_t* des_message, int num_blocks){
    for(int i = 0; i<num_blocks*8; ++i){
        printf("%d ", des_message[i]);
    }
    printf("\n");
}