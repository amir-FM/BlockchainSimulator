#include <cstring>
#include <iostream>
#include <thread>

#include "Block.h"
#include "Chain.h"
#include "Miner.h"
#include "Miner_Race.h"
#include <ncurses.h>
#include "TUI_Block.h"

using namespace std;

//int main() {
//  srand(time(NULL));
//  Miner m;
//  Chain c;
//  Block b;
//  Miner_Race mr(10);
//  b.add_data_with_time("salut");
//  c.add_block(b);
//
//  b.add_data_with_time("ce mai faci");
//  c.add_block(b);
//
//  b.add_data_with_time("eu bine tu");
//  c.add_block(b);
//
//  c.print_chain();
//
//  c.edit_block(1, "sa nu te mai vad");
//  c.print_chain();
//}
//
int main() {
  initscr();

  Block b;
  b.add_data_with_time("hello");
  TUI_Block tb1(b);
  tb1.make_window();
  tb1.fill_window();
  refresh();

  tb1.refresh_window();

  int c = getch();

  Miner m(2);
  m.mine_block(tb1.block);
  tb1.fill_window();
  refresh();

  tb1.refresh_window();

  c = getch();

  endwin();
}
