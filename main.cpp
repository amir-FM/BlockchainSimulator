#include <cstring>
#include <iostream>
#include <thread>

#include "Block.h"
#include "Chain.h"
#include "Miner.h"
#include "Miner_Race.h"

using namespace std;

int main() {
  srand(time(NULL));
  Miner m;
  Chain c;
  Block b;
  Miner_Race mr(10);
  b.add_data_with_time("salut");
  c.add_block(b);

  b.add_data_with_time("ce mai faci");
  c.add_block(b);

  b.add_data_with_time("eu bine tu");
  c.add_block(b);

  c.print_chain();

  c.edit_block(1, "sa nu te mai vad");
  c.print_chain();
}
