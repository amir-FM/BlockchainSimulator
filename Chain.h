#ifndef CHAIN_H
#define CHAIN_H

#include <openssl/sha.h>

#include <cstdlib>
#include <cstring>
#include <iostream>

#include "Block.h"
#include "Miner.h"

using namespace std;

class Chain {
 private:
  struct Node {
    struct Node *prev, *next;
    Block block;
  };

 public:
  struct Node *head, *tail;
  Miner miner;

  Chain();
  struct Node *new_node(Block b);
  void add_block(Block b);
  void print_chain();
};

#endif
