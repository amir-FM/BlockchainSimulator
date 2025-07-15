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
    int block_index;
  };

 public:
  int size;
  struct Node *head, *tail;
  Miner miner;

  Chain();
  struct Node *new_node(Block b);
  void add_block(Block b);
  void print_chain();
  void edit_block(int index, string new_data);
  struct Node *get_block(int index);
  void update_blocks_from(struct Node *node);
  void remine_blocks_from(int index);
  void remine_block(int index);
  Block *block_iterator(int start);
};

#endif
