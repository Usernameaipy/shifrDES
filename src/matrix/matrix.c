#include "matrix.h"

uint64_t **creat_new_matrix(int num_str, int str) {
  int p_trig=0;
  uint64_t **mem_point = malloc(num_str * str * sizeof(uint64_t) + num_str * sizeof(uint64_t *));
  uint64_t *p_mem = (uint64_t *)(mem_point + num_str);
  if (mem_point != NULL) {
    for (int i = 0; i < num_str; i++) {
      mem_point[i] = p_mem + str * i;
    }
  } else {
    p_trig = 1;
  }
  return (p_trig==0) ? mem_point : NULL;
}

uint64_t **fiil_matrix(uint64_t **matrix, char *message, int num_str, int str){
    for(int i = 0; i<num_str; i++){
        for(int j = 0; j<str; j++){
            matrix[i][j]=0;
        }
    }
    for(int i = 0, str_pos=0; i<num_str && str_pos!=num_str*str; i++){
        for(int j = 0; j<str && str_pos!=num_str*str; j++, str_pos++){
            matrix[i][j]=message[str_pos];
            if(j+1==str){
                matrix[i][j+1]='\0';
            }
        }
    }
    return matrix;
}

void delete_matrix(uint64_t **matrix){
    free(matrix);
}