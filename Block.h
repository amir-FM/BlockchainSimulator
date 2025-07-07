#ifndef BLOCK_H
#define BLOCK_H

#include <openssl/sha.h>
#include <stdio.h>

#include <cstring>
#include <ctime>
#include <string>

using namespace std;

class Block {
 public:
  int timestamp;
  char data[1000];
  int pivot;
  char prev_hash[SHA256_DIGEST_LENGTH];
  char hash[SHA256_DIGEST_LENGTH];

  Block();
  void add_data(string str);
  void print();
  void print_hash(char *hash);
};

#endif
