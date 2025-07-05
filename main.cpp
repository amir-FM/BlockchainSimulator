#include <iostream>
#include <cstring>
#include "Miner.h"
#include "Block.h"
#include "Chain.h"

using namespace std;

int main() {
	Miner m;
	Chain c;
	struct Block b;
	memset(b.prev_hash, 0, SHA256_DIGEST_LENGTH);
	strcpy(b.data, "salut");
	c.add_block(b);
	c.print_chain();
	cout << "-------------------------------\n";
	strcpy(b.data, "ce mai faceti domnilor");
	c.add_block(b);
	c.print_chain();
	


}
