#include "TUI_Stats.h"

TUI_Stats::TUI_Stats(int start_y, int start_x, int miners, int sign_len) {
  this->start_y = start_y;
  this->start_x = start_x;
  this->miners = miners;
  this->sign_len = sign_len;
}

void TUI_Stats::make_window() { win = newwin(14, 32, start_y, start_x); }

void TUI_Stats::draw_stats() {
  int y = 2;
  wclear(win);
  box(win, 0, 0);
  mvwprintw(win, 0, 2, "Help");

  mvwprintw(win, y++, 2, "1 / 2 - Page Up / Page Down");
  mvwprintw(win, y++, 2, "i - New Block");
  mvwprintw(win, y++, 2, "e - Edit Block");
  mvwprintw(win, y++, 2, "e - Edit Block");
  mvwprintw(win, y++, 2, "r - Remine Block");
  mvwprintw(win, y++, 2, "R - Remine Blocks from Index");

  // draw line;
  y++;
  wmove(win, y, 1);
  whline(win, ACS_HLINE, 30);
  mvwprintw(win, y, 2, "Stats");

  y += 2;
  mvwprintw(win, y++, 2, "Miners active: %d", miners);
  mvwprintw(win, y, 2, "Sign Length: %d", sign_len); 

  wrefresh(win);
}

void TUI_Stats::refresh_window() { wrefresh(win); }
