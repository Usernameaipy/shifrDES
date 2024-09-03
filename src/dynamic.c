#include "dynamic.h"

char* dynamic_array(char* data, int capacity) {
    if (capacity!=0) {
        capacity *= 2;
        char* tmp = realloc(data, capacity * sizeof(char));
        if(tmp!=NULL){
            if (tmp == NULL) {
                free(data);
            } else {
                data = tmp;
            }
        }
        else{
            data=NULL;
        }
    }
    return data;
}
