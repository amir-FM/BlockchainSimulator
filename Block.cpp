#include "Block.h"

Block::Block() {
  timestamp = pivot = 0;
  memset(data, 0, 1000);
  memset(prev_hash, 0, SHA256_DIGEST_LENGTH);
  memset(hash, 0, SHA256_DIGEST_LENGTH);
}

void Block::add_data(string str) {
  timestamp = time(NULL);
  strncpy(data, str.data(), 1000);
}

void Block::print_hash(char *hash) {
  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) printf("%.2x", hash[i] & 0xFF);
  printf("\n");
}

void Block::print() {
  printf("%d\n%s\n%d\n", timestamp, data, pivot);
  print_hash(prev_hash);
  print_hash(hash);
}
