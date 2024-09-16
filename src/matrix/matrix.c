#include "matrix.h"

uint64_t **creat_new_matrix(int num_str) {
  int p_trig=0;
  uint64_t **mem_point = malloc(num_str * sizeof(uint64_t) + num_str * sizeof(uint64_t *));
  uint64_t *p_mem = (uint64_t *)(mem_point + num_str);
  if (mem_point != NULL) {
    for (int i = 0; i < num_str; i++) {
      mem_point[i] = p_mem + i;
    }
  } else {
    p_trig = 1;
  }
  return (p_trig==0) ? mem_point : NULL;
}

uint64_t **fiil_matrix(uint64_t **matrix, uint8_t *message, int num_str){
    for(int i = 0; i<num_str; i++){  
        matrix[i][0]=0;
    }
    for(int i = 0; i<num_str; i++){
        matrix[i][0]=join_message_in_matrix(message+i*8);
    }
    return matrix;
}

void delete_matrix(uint64_t **matrix){
    free(matrix);
}

uint64_t join_message_in_matrix(uint8_t * message_8b) {
    uint64_t block;
    for (uint8_t *p = message_8b; p < message_8b + 8 && *p!='\0'; ++p) {
        block = (block << 8) | *p;
    }
    return block;
}