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
  int miners = 8;
  int sign_len = 3;
  initscr();
  noecho();
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_WHITE, COLOR_BLACK);

  Block b;
  Chain c(miners, sign_len);
  TUI_Chain tc(&c, 3, 3, sign_len);
  Input_Field inpf(46, 3);
  TUI_Stats stats(3, 82, miners, sign_len);

  inpf.make_window();
  tc.make_window();
  stats.make_window();
  refresh();


  b.add_data_with_time("Hello World!");
  c.add_block(b);
  tc.draw_chain();
  stats.draw_stats();


  refresh();
  tc.refresh_window();
  inpf.clear_window();

  while (int ch = getch()) {
    if(ch == 'q') {
      break;
    } else if (ch == '1') {
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
