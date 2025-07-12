#include "TUI_Block.h"

TUI_Block::TUI_Block(Block block, int start_x, int start_y, int id) {
  this->block = block;
  this->start_x = start_x;
  this->start_y = start_y;
  this->id = id;
}

void TUI_Block::make_window() { win = newwin(8, 79, start_y, start_x); }

void TUI_Block::fill_window() {
  box(win, 0, 0);
  mvwprintw(win, 0, 2, "Block #%d", id);
  mvwprintw(win, 2, 2, "Timestamp: %d", block.timestamp);
  mvwprintw(win, 3, 2, "Nonce:     %d", block.pivot);
  mvwprintw(win, 4, 2, "Data:      %s", block.data);
  mvwprintw(win, 5, 2, "Prev Hash: ");
  print_hash(win, block.prev_hash);
  mvwprintw(win, 6, 2, "Hash:      ");
  print_hash(win, block.hash);
}

void TUI_Block::refresh_window() { wrefresh(win); }

void TUI_Block::print_hash(WINDOW *win, char *hash) {
  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    wprintw(win, "%.2x", hash[i] & 0xFF);
}
