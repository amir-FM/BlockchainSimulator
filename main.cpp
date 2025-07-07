#include <iostream>
#include <cstring>
#include <thread>
#include "Miner.h"
#include "Block.h"
#include "Chain.h"
#include "Miner_Race.h"

using namespace std;

int main() {
	srand(time(NULL));
	Miner m(2);
	Chain c;
	Block b;
	Miner_Race mr(10);
	b.add_data("salut");
	mr.race(b);
	b.print();
}
