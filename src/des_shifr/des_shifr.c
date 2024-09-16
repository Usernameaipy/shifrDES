#include "des_shifr.h"

void start(void){
    uint8_t* message=NULL;
    message=input(message);
    int num_blocks=0;
    uint8_t *key=copy_key(KEY_DES);
    uint64_t key48_round[16] = {0};
    if(message!=NULL){
        uint64_t **blocks=division_into_blocks(message, &num_blocks);
        perm_IP(blocks, num_blocks);
        uint64_t new_key=split_8by_64bi(key);
        creat_rounds_key(new_key, key48_round);
        /// for(int i = 0; i<16; i++){
        //     for(int j = 0; j<num_blocks; j++){
        //         uint32_t block_left=0;
        //         uint32_t block_right=0;
        //         splits_block_64_32(blocks[j][0], &block_left, &block_right);
        //     }
        /// }
        delete_matrix(blocks);
        free(message);
        free(key);
    }
}

// int main(){
//     start();
//     return 0;
// }