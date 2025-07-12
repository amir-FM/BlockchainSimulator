#include "TUI_Chain.h"

TUI_Chain::TUI_Chain(int start_y, int start_x) {
  this->start_y = start_y;
  this->start_x = start_x;
}

void TUI_Chain::make_window() {
  win = newwin(50, 79, start_y, start_x);
  box(win, 0, 0);
}

void TUI_Chain::draw_block(Block block, int start_y, int start_x) {
  mvwprintw(win, start_y + 2, start_x + 2, "Timestamp: %d", block.timestamp);
  mvwprintw(win, start_y + 3, start_x + 2, "Nonce:     %d", block.pivot);
  mvwprintw(win, start_y + 4, start_x + 2, "Data:      %s", block.data);
  mvwprintw(win, start_y + 5, start_x + 2, "Prev Hash: ");
  print_hash(win, block.prev_hash);
  mvwprintw(win, start_y + 6, start_x + 2, "Hash:      ");
  print_hash(win, block.hash);
  wmove(win, start_y + 7, 1);
  whline(win, ACS_HLINE, 77);
}

void TUI_Chain::refresh_window() { wrefresh(win); }

void TUI_Chain::print_hash(WINDOW *win, char *hash) {
  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    wprintw(win, "%.2x", hash[i] & 0xFF);
}
