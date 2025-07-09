#ifndef LEDGERS_H
#define LEDGERS_H

#include <vector>

#include "Chain.h"

class Ledgers {
 private:
  vector<Chain> chains;
  int chain_number;

 public:
  Ledgers();
  Ledgers(int chain_number);
};

#endif
