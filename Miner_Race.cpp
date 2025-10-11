#include "Miner_Race.h"

Miner_Race::Miner_Race(int threads) { this->threads = threads; }
Miner_Race::Miner_Race() : Miner_Race(4) {}

void Miner_Race::race(Block &b) {
  vector<thread> ths;
  vector<pair<int, Block>> blocks(threads, pair<int, Block>(0, b));
  //cout << threads << endl;

  for (int i = 0; i < threads; i++) {
    auto &[timestamp, block] = blocks[i];
    ths.push_back(thread(thread_line, ref(timestamp), ref(block)));
  }

  for (auto &it : ths) {
    it.join();
  }

  int min = 0;
  for (int i = 1; i < threads; i++) {
    if (blocks[i].first < blocks[min].first) min = i;
  }

  cout << "Miner " << min << " a castigat cursa" << endl;

  b = blocks[min].second;
}

void Miner_Race::thread_line(int &timestamp, Block &b) {
  Miner m(2);
  m.mine_block(b);
  timestamp = time(NULL);
}
