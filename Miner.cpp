#include <iostream>
#include <cstring>
#include <openssl/sha.h>
#include "Miner.h"

using namespace std;

void Miner::mine_block(struct Block &b) {
	unsigned char *data = (unsigned char *)&b;
	unsigned char hash[64];
	SHA256_Update(data, sizeof(Block), hash);

	memcpy(b.hash, hash, 64);
}

