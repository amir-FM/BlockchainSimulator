#ifndef TUI_STATS_H
#define TUI_STATS_H

#include <ncurses.h>

using namespace std;

class TUI_Stats {
 public:
  int start_x, start_y;
  int miners, sign_len;

  WINDOW *win;
  TUI_Stats(int start_y, int start_x, int miners, int sign_len);
  void make_window();
  void draw_stats();
  void refresh_window();
};

#endif
