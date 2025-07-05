#ifndef MINER_H
#define MINER_H

#include <openssl/sha.h>
#include "Block.h"

class Miner {
public:
	Miner() {};
	void mine_block(Block &b);
	void hash_block(Block &b);
};

#endif
