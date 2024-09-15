#include "des_shifr.h"

void start(void){
    char* message=NULL;
    message=input(message);
    int num_blocks=0;
    if(message!=NULL){
        char **blocks=division_into_blocks(message, &num_blocks);
        delete_matrix(blocks);
        free(message);
    }
}