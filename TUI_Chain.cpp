#include "TUI_Chain.h"

TUI_Chain::TUI_Chain(Chain *chain, int start_y, int start_x) {
  this->chain = chain;
  this->start_y = start_y;
  this->start_x = start_x;
  this->page = 0;
}

void TUI_Chain::make_window() { win = newwin(43, 79, start_y, start_x); }

void TUI_Chain::draw_block(Block block, int start_y, int start_x,
                           int last_block, int id) {
  mvwprintw(win, start_y, start_x + 74, "#%d", id);
  mvwprintw(win, start_y, start_x + 2, "Timestamp: %d", block.timestamp);
  mvwprintw(win, start_y + 1, start_x + 2, "Nonce:     %d", block.pivot);
  mvwprintw(win, start_y + 2, start_x + 2, "Data:      %s", block.data);
  mvwprintw(win, start_y + 3, start_x + 2, "Prev Hash: ");
  print_hash(win, block.prev_hash);
  mvwprintw(win, start_y + 4, start_x + 2, "Hash:      ");
  // add color here
  print_hash(win, block.hash);
  if (last_block) {
    wmove(win, start_y + 5, 1);
    whline(win, ACS_HLINE, 77);
  }
}

void TUI_Chain::refresh_window() { wrefresh(win); }

void TUI_Chain::print_hash(WINDOW *win, char *hash) {
  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    wprintw(win, "%.2x", hash[i] & 0xFF);
}

void TUI_Chain::draw_chain() {
  wclear(win);
  box(win, 0, 0);
  mvwprintw(win, 0, 2, "Ledger");

  Block *p = chain->block_iterator(page * 6);
  int index = 2;
  int no_pages = 6;
  int id = page * 6;
  while (p != NULL && no_pages--) {
    draw_block(*p, index, 0, no_pages, id++);

    index += 7;
    p = chain->block_iterator(-1);
  }

  mvwprintw(win, 42, 72, "%d/%d", page, (chain->size - 1) / 6);
}

void TUI_Chain::next_page() {
  if (page < (chain->size - 1) / 6) page++;
}
void TUI_Chain::prev_page() {
  if (page > 0) page--;
}
