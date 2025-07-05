#include <iostream>
#include <cstring>
#include <openssl/sha.h>
#include "Miner.h"

using namespace std;

void Miner::hash_block(struct Block &b) {
	unsigned char *data = (unsigned char *)&b;
	unsigned char hash[SHA256_DIGEST_LENGTH];

	memset(b.hash, 0, SHA256_DIGEST_LENGTH);
	SHA256(data, sizeof(Block), hash);

	memcpy(b.hash, hash, SHA256_DIGEST_LENGTH);
}

void Miner::mine_block(struct Block &b) {
	b.pivot = 0;
	do{
		hash_block(b);
		cout << "trying pivot: " << b.pivot << " with hash: ";
		b.print_hash(b.hash);
		b.pivot++;
	}while(*(short *)b.hash != 0);

	cout << "pivot is " << --b.pivot  << endl;
}

