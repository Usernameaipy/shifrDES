#include "feistel_cipher.h"

void round_castling_feistel(uint32_t *left_block, uint32_t *right_block,
                            uint64_t *rounds_keys) {
  for (int i = 0; i < 16; i++) {
    uint32_t temp = *right_block;
    *right_block = func_F(*right_block, rounds_keys[i]) ^ *left_block;
    *left_block = temp;
  }
  swap(left_block, right_block);
}

uint32_t func_F(uint32_t block, uint64_t key_round) {
  uint64_t block48 = perm_round_first(block);
  block48 ^= key_round;
  block = substitutions(block48);
  return perm_block_F(block);
}

uint64_t perm_round_first(uint32_t block) {
  uint64_t new_block = 0;
  for (uint8_t j = 0; j < 48; ++j) {
    new_block |= (uint64_t)((block >> (32 - EP[j])) & 0x01) << (63 - j);
  }
  return new_block;
}

uint32_t substitutions(uint64_t block48) {
  uint8_t blocks4[4] = {0}, blocks6[8] = {0};
  split_48_6(block48, blocks6);
  split_6_4(blocks6, blocks4);
  return join_4_32(blocks4);
}

void split_48_6(uint64_t block48, uint8_t *blocks6) {
  for (int i = 0; i < 8; ++i) {
    blocks6[i] = (block48 >> (58 - (i * 6))) << 2;
  }
}

void split_6_4(uint8_t *blocks6, uint8_t *blocks4) {
  uint8_t block2 = 0, block4 = 0;
  for (int i = 0, j = 0; i < 8; i += 2, ++j) {
    block2 = extreme_bits(blocks6[i]);
    block4 = middle_bits(blocks6[i]);
    blocks4[j] = Sbox[i][block2][block4];
    block2 = extreme_bits(blocks6[i + 1]);
    block4 = middle_bits(blocks6[i + 1]);
    blocks4[j] = (blocks4[j] << 4) | Sbox[i + 1][block2][block4];
  }
}

uint8_t extreme_bits(uint8_t block6) {
  return ((block6 >> 6) & 0x2) | ((block6 >> 2) & 0x1);
}

uint8_t middle_bits(uint8_t block6) { return (block6 >> 3) & 0xF; }

uint32_t join_4_32(uint8_t *blocks4) {
  uint32_t new_block = 0;
  for (uint8_t *p = blocks4; p < blocks4 + 4; ++p) {
    new_block = (new_block << 8) | *p;
  }
  return new_block;
}

uint32_t perm_block_F(uint32_t block) {
  uint32_t new_block = 0;
  for (uint8_t i = 0; i < 32; ++i) {
    new_block |= ((block >> (32 - P[i])) & 0x01) << (31 - i);
  }
  return new_block;
}

void swap(uint32_t *B_L, uint32_t *B_R) {
  uint32_t temp = *B_L;
  *B_L = *B_R;
  *B_R = temp;
}