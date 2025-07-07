#ifndef MINER_H
#define MINER_H

#include <openssl/sha.h>
#include <ctime>
#include <cstdlib>
#include <climits>
#include "Block.h"

class Miner {
private:
	int sign;
public:
	Miner();
	Miner(int sign);
	void mine_block(Block &b);
	void mine_block(Block &b, int start);
	void hash_block(Block &b);
	bool check_signed(Block b);
};

#endif
