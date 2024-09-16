#include "des_shifr.h"

void start(void){
    uint8_t* message=NULL;
    message=input(message);
    int num_blocks=0;
    if(message!=NULL){
        uint64_t **blocks=division_into_blocks(message, &num_blocks);
        // for(int i = 0; i<num_blocks; i++){
        //     for(int j = 0; j<BLOCK_SIZE; j++){
        //         printf("%ld ", blocks[i][j]);
        //     }
        //     printf("\n");
        // }
        delete_matrix(blocks);
        free(message);
    }
    // printf("%d", num_blocks);
}

// int main(){
//     start();
//     return 0;
// }