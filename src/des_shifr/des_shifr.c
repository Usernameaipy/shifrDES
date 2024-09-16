#include "des_shifr.h"

void start(void){
    char* message=NULL;
    message=input(message);
    int num_blocks=0;
    if(message!=NULL){
        uint8_t **blocks=division_into_blocks(message, &num_blocks);
        // for(int i = 0; i<4; i++){
        //     for(int j = 0; j<BLOCK_SIZE; j++){
        //         printf("%d ", blocks[i][j]);
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