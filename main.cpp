#include <iostream>
#include <cstring>
#include "Miner.h"
#include "Block.h"
#include "Chain.h"

using namespace std;

int main() {
	srand(time(NULL));
	Miner m(4);
	Chain c;
	Block b;
	b.add_data("salut");
	m.mine_block(b);
	b.print();

	m.mine_block(b);
	b.print();

	m.mine_block(b);
	b.print();

}
