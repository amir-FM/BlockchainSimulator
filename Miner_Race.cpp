#include "Miner_Race.h"

Miner_Race::Miner_Race(int threads, int sign) { this->threads = threads; this->sign = sign;}
Miner_Race::Miner_Race() : Miner_Race(4, 2) {}

int Miner_Race::race(Block &b) {
  vector<thread> ths;
  vector<pair<int, Block>> blocks(threads, pair<int, Block>(0, b));

  for (int i = 0; i < threads; i++) {
    auto &[timestamp, block] = blocks[i];
    ths.push_back(thread(thread_line, ref(timestamp), ref(block), sign));
  }

  for (auto &it : ths) {
    it.join();
  }

  int min = 0;
  for (int i = 1; i < threads; i++) {
    if (blocks[i].first < blocks[min].first) min = i;
  }

  //cout << "Miner " << min << " a castigat cursa" << endl;

  b = blocks[min].second;
  
  return min;
}

void Miner_Race::thread_line(int &timestamp, Block &b, int sign) {
  Miner m(sign);
  m.mine_block(b);
  timestamp = time(NULL);
}
