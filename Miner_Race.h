#ifndef MINER_RACE_H
#define MINER_RACE_H

#include <cstring>
#include <ctime>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include "Block.h"
#include "Miner.h"

using namespace std;

class Miner_Race {
 private:
  int threads;
  int sign;
  Miner m;

 public:
  Miner_Race();
  Miner_Race(int threads, int sign);
  int race(Block &b);
  void static thread_line(int &timestamp, Block &b, int sign);
};

#endif
