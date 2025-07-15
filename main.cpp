#include <ncurses.h>

#include <iostream>
#include <string>
#include <thread>

#include "Block.h"
#include "Chain.h"
#include "Input_Field.h"
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
  noecho();

  Block b;
  Chain c;
  TUI_Chain tc(&c, 3, 3);
  Input_Field inpf(3, 100);
  b.add_data_with_time("hello");
  c.add_block(b);
  tc.make_window();
  tc.draw_chain();
  inpf.make_window();

  refresh();
  tc.refresh_window();
  inpf.clear_window();

  int ch = getch();

  b.add_data_with_time("salutare");
  c.add_block(b);
  c.add_block(b);
  c.add_block(b);
  c.add_block(b);
  c.add_block(b);
  c.add_block(b);
  tc.draw_chain();

  refresh();
  tc.refresh_window();

  while (ch = getch()) {
    if (ch == '1') {
      tc.next_page();
      wclear(tc.win);
    } else if (ch == '2') {
      tc.prev_page();
      wclear(tc.win);
    } else if (ch == 'i') {
      b.add_data_with_time(inpf.get_input("Input data for block"));
      c.add_block(b);
    } else if (ch == 'e') {
      c.edit_block(stoi(inpf.get_input("Input number")),
                   inpf.get_input("Input new data"));
    } else if (ch == 'r') {
      c.remine_blocks_from(stoi(inpf.get_input("Input index")));
    }

    tc.draw_chain();
    refresh();
    tc.refresh_window();
  }

  endwin();
}
