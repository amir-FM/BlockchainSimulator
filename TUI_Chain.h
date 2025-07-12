
#ifndef TUI_CHAIN_H
#define TUI_CHAIN_H

#include <ncurses.h>

#include "Block.h"

class TUI_Chain {
 private:
  int start_x, start_y;

 public:
  WINDOW *win;
  TUI_Chain(int start_y, int start_x);
  void make_window();
  void draw_block(Block block, int start_y, int start_x);
  void refresh_window();
  void print_hash(WINDOW *win, char *hash);
};

#endif
