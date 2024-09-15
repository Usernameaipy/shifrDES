#include "dynamic.h"

char* dynamic_array(char* data, int capacity) {
    if (capacity!=0) {
        capacity *= 2;
        char* tmp = realloc(data, capacity * sizeof(char));
        if(tmp!=NULL){
            data = tmp;
        }
        else{
            free(data);
            data=NULL;
        }
    }
    return data;
}
