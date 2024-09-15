#include "matrix.h"

char **creat_new_matrix(int num_str, int str) {
  int p_trig=0;
  char **mem_point = malloc(num_str * str * sizeof(char) + num_str * sizeof(char *));
  char *p_mem = (char *)(mem_point + num_str);
  if (mem_point != NULL) {
    for (int i = 0; i < num_str; i++) {
      mem_point[i] = p_mem + str * i;
    }
  } else {
    p_trig = 1;
  }
  return (p_trig==0) ? mem_point : NULL;
}

char **fiil_matrix(char **matrix, char *message, int num_str, int str){
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

void delete_matrix(char **matrix){
    free(matrix);
}