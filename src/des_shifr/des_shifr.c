#include "des_shifr.h"

void start(void){
    char* message=NULL;
    message=input(message);
    if(message!=NULL){
        char **blocks=division_into_blocks(message);
        delete_matrix(blocks);
        free(message);
    }
}