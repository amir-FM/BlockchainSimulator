#ifndef INPUT_FIELD_H
#define INPUT_FIELD_H

#include <ncurses.h>

#include <iostream>

using namespace std;

class Input_Field {
 public:
  WINDOW *win;
  int start_y, start_x;
  int size;
  Input_Field(int y, int x) : start_y(y), start_x(x), size(50) {}
  void make_window();
  void clear_window();
  string get_input(string placeholder);
};

#endif
