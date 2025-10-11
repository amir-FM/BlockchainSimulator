#include "Chain.h"

using namespace std;

Chain::Chain(int miners, int sign_len) {
  head = tail = NULL;
  size = 0;
  miner = Miner(sign_len);
  mr = Miner_Race(miners, sign_len);
  mine_race = true;
}

Chain::Chain(int sign_len) {
  head = tail = NULL;
  size = 0;
  miner = Miner(sign_len);
  mine_race = false;
}

Chain::Chain() {
  head = tail = NULL;
  size = 0;
  miner = Miner(2);
  mine_race = false;
}

Chain::Node *Chain::new_node(Block b) {
  struct Node *node = new struct Node;
  node->block = b;

  return node;
}

int Chain::add_block(Block b) {
  struct Node *node = new_node(b);
  int miner_won;

  if (head == NULL) {
    miner_won = mine_controller(node->block);
    head = tail = node;
    node->prev = node->next = NULL;
    node->block_index = 0;
  } else {
    memcpy(node->block.prev_hash, tail->block.hash, SHA256_DIGEST_LENGTH);
    miner_won = mine_controller(node->block);
    node->block_index = tail->block_index + 1;
    node->next = NULL;
    node->prev = tail;
    tail->next = node;
    tail = node;
  }

  size++;

  return miner_won;
}

void Chain::print_chain() {
  struct Node *p = head;

  while (p != NULL) {
    cout << "#" << p->block_index << endl;
    p->block.print();
    cout << endl;
    p = p->next;
  }
}

void Chain::edit_block(int index, string new_data) {
  struct Node *node = get_block(index);
  if (node == NULL) {
    cerr << "Block not found by index\n";
    return;
  }

  node->block.add_data(new_data);
  update_blocks_from(node);
}

Chain::Node *Chain::get_block(int index) {
  if (index >= size) return NULL;
  struct Node *p = head;
  while (p->block_index != index) {
    p = p->next;
  }

  return p;
}

void Chain::update_blocks_from(struct Node *node) {
  while (node != NULL) {
    if (node != head)
      memcpy(node->block.prev_hash, node->prev->block.hash,
             SHA256_DIGEST_LENGTH);
    miner.hash_block(node->block);
    node = node->next;
  }
}

Block *Chain::block_iterator(int start) {
  static struct Node *p;
  if (start >= 0)
    p = get_block(start);
  else if (p == NULL)
    return NULL;

  Block *res = &(p->block);
  p = p->next;
  return res;
}

void Chain::remine_blocks_from(int index) {
  struct Node *node = get_block(index);
  if (node == NULL) {
    cerr << "Block not found\n";
    return;
  }

  while (node != NULL) {
    if (node != head)
      memcpy(node->block.prev_hash, node->prev->block.hash,
             SHA256_DIGEST_LENGTH);
    miner.mine_block(node->block);
    node = node->next;
  }
}

void Chain::remine_block(int index) {
  struct Node *node = get_block(index);
  if (node == NULL) {
    cerr << "Block not found\n";
    return;
  }

  miner.mine_block(node->block);
  node = node->next;

  while (node != NULL) {
    memcpy(node->block.prev_hash, node->prev->block.hash, SHA256_DIGEST_LENGTH);
    miner.hash_block(node->block);
    node = node->next;
  }
}

int Chain::mine_controller(Block &b) {
  if(mine_race)
    return mr.race(b);

  miner.mine_block(b);
  return -1;
  
}
