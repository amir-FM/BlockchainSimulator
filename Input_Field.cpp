#include "Input_Field.h"

void Input_Field::make_window() { win = newwin(3, size, start_y, start_x); }

void Input_Field::clear_window() {
  wclear(win);
  box(win, 0, 0);
  wrefresh(win);
}

string Input_Field::get_input(string placeholder) {
  mvwprintw(win, 1, 1, placeholder.data());
  refresh();
  wrefresh(win);
  int index = 1;
  string input = "";
  int ch;
  int once;
  while ((ch = getch()) != '\n') {
    if (once) {
      clear_window();
      wmove(win, 1, 1);
      once = 0;
    }

    if (ch == KEY_BACKSPACE || ch == KEY_DC || ch == 127) {
      if (index > 1) {
        index--;
        mvwaddch(win, 1, index, ' ');
        wmove(win, 1, index);
        wrefresh(win);
        input.pop_back();
      }
    } else if (index >= 49) {
      continue;
    } else {
      waddch(win, ch);
      wrefresh(win);
      input.push_back((char)ch);
      index++;
    }
  }

  clear_window();

  return input;
}
