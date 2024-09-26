#include "keys.h"

uint64_t split_8by_64bi(uint8_t *key) {
  uint64_t new_key = 0;
  for (uint8_t *p = key; p < key + 8; ++p) {
    new_key = (new_key << 8) | *p;
  }
  return new_key;
}

uint8_t *copy_key(char *key) {
  uint8_t *new_key = malloc(sizeof(uint8_t) * 8);
  for (int i = 0; i < 8; i++) {
    new_key[i] = key[i];
  }
  return new_key;
}

void creat_rounds_key(uint64_t block, uint64_t *keys_round) {
  uint32_t key_left = 0, key_right = 0;
  perm_two_key(block, &key_left, &key_right);
  finel_56_key(keys_round, key_left, key_right);
}

void perm_two_key(uint64_t orig_key, uint32_t *key_left, uint32_t *key_right) {
  for (int i = 0; i < 28; i++) {
    *key_left |= ((orig_key >> (64 - K1P[i])) & 0x01) << (31 - i);
    *key_right |= ((orig_key >> (64 - K2P[i])) & 0x01) << (31 - i);
  }
}

void finel_56_key(uint64_t *round_keys, uint32_t key_left, uint32_t key_right) {
  uint64_t key56 = 0;
  uint8_t n = 0;
  for (uint32_t i = 0; i < 16; ++i) {
    switch (i) {
    case 0:
    case 1:
    case 8:
    case 15:
      n = 1;
      break;
    default:
      n = 2;
      break;
    }
    key_left = LSHIFT_28BIT(key_left, n);
    key_right = LSHIFT_28BIT(key_right, n);
    key56 = join_28b_56b(key_left, key_right);
    round_keys[i] = finel_key_per(key56);
  }
}

uint64_t join_28b_56b(uint32_t key_left, uint32_t key_right) {
  uint64_t key = 0;
  key = (key_left >> 4);
  key = ((key << 32) | key_right) << 4;
  return key;
}

uint64_t finel_key_per(uint64_t key56_orig) {
  uint64_t key48 = 0;
  for (int i = 0; i < 48; ++i) {
    key48 |= ((key56_orig >> (64 - CP[i])) & 0x01) << (63 - i);
  }
  return key48;
}