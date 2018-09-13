#ifndef FRAME_H
#define FRAME_H

#include <ncurses.h>
#include "Character.h"

class Frame
{
  // Frame dimensions
  int m_height, m_width;
  // Frame position
  int m_row, m_col;
  // FALSE for window, TRUE for subwindow
  bool m_has_super;
  // Pointer to ncurses WINDOW
  WINDOW * m_w;
  // Pointer to ncurses WINDOW; points to a parent / super window
  WINDOW * m_superw;

public:
  Frame(int nr_rows, int nr_cols, int row, int col);

  Frame(Frame &sw, int nr_rows, int nr_cols, int row, int col);

  ~Frame();

  auto fillWindow() -> void;

  auto add(Character &c) -> void;
  auto add(Character &c, int row, int col) -> void;

  auto erase(Character& c) -> void;

  auto move(int row, int col) -> void;

  int width();
  int height();

  int row();
  int col();

  void center(Character& c);

  void refresh();
  WINDOW* super();
  WINDOW* win();
  bool has_super();

};

#endif
