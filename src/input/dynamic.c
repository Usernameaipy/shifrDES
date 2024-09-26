#include "dynamic.h"

uint8_t *dynamic_array(uint8_t *data, int capacity) {
  if (capacity != 0) {
    capacity *= 2;
    uint8_t *tmp = realloc(data, capacity * sizeof(uint8_t));
    if (tmp != NULL) {
      data = tmp;
    } else {
      free(data);
      data = NULL;
    }
  }
  return data;
}
