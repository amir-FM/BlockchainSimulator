#ifndef BLOCK_H
#define BLOCK_H

#include <openssl/sha.h>

using namespace std;

class Block {
//private:
public:
	int timestamp;
	char data[1000];
	int pivot;
	char prev_hash[SHA256_DIGEST_LENGTH];
	char hash[SHA256_DIGEST_LENGTH];

	Block();
	void print();
	void print_hash(char *hash);
};

#endif
