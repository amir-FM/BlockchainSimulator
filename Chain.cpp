#include "Chain.h"

using namespace std;

Chain::Chain() {
	head = tail = NULL;
}

Chain::Node* Chain::new_node(Block b) {
	struct Node *node = new struct Node;
	node->block = b;

	return node;
}

void Chain::add_block(Block b) {
	struct Node *node = new_node(b);

	if(head == NULL){
		miner.mine_block(node->block);
		head = tail = node;
	}else{
		memcpy(node->block.prev_hash, tail->block.hash, SHA256_DIGEST_LENGTH);
		miner.mine_block(node->block);
		tail->next = node;
		tail = node;
	}
}

void Chain::print_chain() {
	struct Node *p = head;

	while(p != NULL) {
		p->block.print();
		p = p->next;
	}
}
