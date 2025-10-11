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
#include "TUI_Stats.h"

using namespace std;

int main() {
  initscr();
  noecho();

  Block b;
  Chain c;
  TUI_Chain tc(&c, 3, 3);
  Input_Field inpf(3, 100);
  Input_Field inpf2(6, 100);
  TUI_Stats stats(6, 100, 4, 3);

  stats.make_window();
  refresh();
  stats.draw_stats();
  //stats.refresh_window();

  int ch = getch();

  b.add_data_with_time("Hello World!");
  c.add_block(b);
  tc.make_window();
  tc.draw_chain();
  inpf.make_window();
  inpf2.make_window();
  //inpf2.clear_window();


  refresh();
  tc.refresh_window();
  inpf.clear_window();

  while (int ch = getch()) {
    if (ch == '1') {
      tc.next_page();
      wclear(tc.win);
    } else if (ch == '2') {
      tc.prev_page();
      wclear(tc.win);
    } else if (ch == 'i') {
      b.add_data_with_time(inpf.get_input("Input data for block"));
      inpf.print_log("Miners running");
      int res = c.add_block(b);
      inpf.print_log("Miner " + to_string(res) + " won");
    } else if (ch == 'e') {
      c.edit_block(stoi(inpf.get_input("Input index")),
                   inpf.get_input("Input new data"));
    } else if (ch == 'R') {
      c.remine_blocks_from(stoi(inpf.get_input("Input index")));
    } else if (ch == 'r') {
      c.remine_block(stoi(inpf.get_input("Input index")));
    }

    tc.draw_chain();
    refresh();
    tc.refresh_window();
  }

  endwin();
}
