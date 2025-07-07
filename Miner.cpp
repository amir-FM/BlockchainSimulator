#include "Miner.h"

#include <openssl/sha.h>

#include <cstring>
#include <iostream>

using namespace std;

Miner::Miner(int sign) {
  this->sign = sign;
  srand(time(NULL));
}

Miner::Miner() : Miner(3) {}

void Miner::hash_block(struct Block &b) {
  unsigned char *data = (unsigned char *)&b;
  unsigned char hash[SHA256_DIGEST_LENGTH];

  memset(b.hash, 0, SHA256_DIGEST_LENGTH);
  SHA256(data, sizeof(Block), hash);

  memcpy(b.hash, hash, SHA256_DIGEST_LENGTH);
}

void Miner::mine_block(Block &b) { mine_block(b, rand() % INT_MAX); }

void Miner::mine_block(struct Block &b, int start) {
  b.pivot = start;
  do {
    hash_block(b);
    // cout << "trying pivot: " << b.pivot << " with hash: ";
    // b.print_hash(b.hash);
    b.pivot++;
  } while (!check_signed(b));

  // cout << "pivot is " << --b.pivot  << endl;
}

bool Miner::check_signed(Block b) {
  int count = sign;
  char *p = b.hash;
  while (count > 0) {
    if (*p != 0) return false;
    count--;
    p += 1;
  }
  return true;
}
