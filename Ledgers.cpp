#include "Ledgers.h"

Ledgers::Ledgers(int chain_number) {
  this->chain_number = chain_number;
  chains.resize(this->chain_number, Chain());
}

Ledgers::Ledgers() : Ledgers(4) {}
