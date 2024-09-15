#include "input.h"

char* input(char* array){
    char* arr=calloc(2, sizeof(char));
    if(arr!=NULL){
        int size_arr=2;
        int size_array=0;
        for(int i = 0; scanf("%c", &arr[i]) && arr[i]!='\n' && arr!=NULL; i++, size_array++){
            if(i+1==size_arr){
                arr=dynamic_array(arr, i+1);
                size_arr*=2;
            }
        }
        arr[size_array]='\0';
        array=arr;
    }
    return array;
}