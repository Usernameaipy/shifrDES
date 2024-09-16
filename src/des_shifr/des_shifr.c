#include "des_shifr.h"

void start(void){
    uint8_t* message=NULL;
    message=input(message);
    int num_blocks=0;
    if(message!=NULL){
        uint64_t **blocks=division_into_blocks(message, &num_blocks);
        // for(int i = 0; i<num_blocks; i++){
        //     printf("%0lX ", blocks[i][0]);
        //     printf("\n");
        // }
        perm_IP(blocks, num_blocks);
        // for(int i = 0; i<num_blocks; i++){
        //     printf("%0lX ", blocks[i][0]);
        //     printf("\n");
        // }
        for(int i = 0; i<16; i++){
            for(int j = 0; j<num_blocks; j++){
                uint32_t block_left=0;
                uint32_t block_right=0;
                splits_block_64_32(blocks[j][0], &block_left, &block_right);
            }
        }
        delete_matrix(blocks);
        free(message);
    }
    printf("%d\n", num_blocks);
}

int main(){
    start();
    return 0;
}