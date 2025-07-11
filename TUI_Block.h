#ifndef TUI_BLOCK_H
#define TUI_BLOCK_H

#include <ncurses.h>

#include "Block.h"

class TUI_Block {
 private:
  WINDOW *win;

 public:
  Block block;
  TUI_Block(Block block);
  void make_window();
  void fill_window();
  void refresh_window();
  void print_hash(WINDOW *win, char *hash);
};

#endif
