
#ifndef TUI_CHAIN_H
#define TUI_CHAIN_H

#include <ncurses.h>

#include "Block.h"
#include "Chain.h"

class TUI_Chain {
 public:
  int start_x, start_y;
  Chain *chain;
  int page;
  int sign_len;

  WINDOW *win;
  TUI_Chain(Chain *chain, int start_y, int start_x, int sign_len);
  void make_window();
  void draw_block(Block block, int start_y, int start_x, int last_block,
                  int id);
  void refresh_window();
  void print_hash(WINDOW *win, char *hash);
  void draw_chain();
  void next_page();
  void prev_page();
  bool check_hash(char *hash);
};

#endif
