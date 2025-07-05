#include <iostream>
#include <cstring>
#include "Miner.h"
#include "Block.h"

using namespace std;

int main() {
	Miner m;
	struct Block b;
	memset(b.prev_hash, 0, SHA256_DIGEST_LENGTH);
	strcpy(b.data, "salut");
	cout << "size short = " << sizeof(short) << endl;
	m.mine_block(b);
	b.print();
	cout << *(short *)b.hash << endl;

}
