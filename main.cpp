#include <iostream>
#include <cstring>
#include "Miner.h"
#include "Block.h"

using namespace std;

int main() {
	Miner m;
	struct Block b;
	strcpy(b.data, "salut");
	m.mine_block(b);
	b.print();

}
