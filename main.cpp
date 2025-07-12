#include <ncurses.h>

#include <cstring>
#include <iostream>
#include <thread>

#include "Block.h"
#include "Chain.h"
#include "Miner.h"
#include "Miner_Race.h"
#include "TUI_Block.h"
#include "TUI_Chain.h"

using namespace std;

// int main() {
//   srand(time(NULL));
//   Miner m;
//   Chain c;
//   Block b;
//   Miner_Race mr(10);
//   b.add_data_with_time("salut");
//   c.add_block(b);
//
//   b.add_data_with_time("ce mai faci");
//   c.add_block(b);
//
//   b.add_data_with_time("eu bine tu");
//   c.add_block(b);
//
//   c.print_chain();
//
//   c.edit_block(1, "sa nu te mai vad");
//   c.print_chain();
// }
//
int main() {
  initscr();

  Block b;
  TUI_Chain tc(3, 3);
  b.add_data_with_time("hello");
  tc.make_window();
  tc.draw_block(b, 0, 0);
  tc.draw_block(b, 7, 0);
  tc.draw_block(b, 14, 0);
  tc.draw_block(b, 21, 0);
  tc.draw_block(b, 28, 0);
  tc.draw_block(b, 35, 0);
  tc.draw_block(b, 42, 0);
  tc.draw_block(b, 49, 0);
  tc.draw_block(b, 56, 0);

  refresh();
  tc.refresh_window();

  int c = getch();

  endwin();
}
