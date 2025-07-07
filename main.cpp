#include <iostream>
#include <cstring>
#include "Miner.h"
#include "Block.h"
#include "Chain.h"

using namespace std;

int main() {
	Miner m;
	Chain c;
	Block b;
	b.add_data("salut");
	c.add_block(b);
	c.print_chain();
	cout << "-------------------------------\n";
	b.add_data("ce mai faceti aici");
	c.add_block(b);
	c.print_chain();
	


}
