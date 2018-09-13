#include "Frame.h"
#include <iostream>

Frame::Frame(int nr_rows, int nr_cols, int row, int col)
{
  m_has_super = false;
  m_superw = nullptr;
  m_w = newwin(nr_rows, nr_cols, row, col);
  m_height = nr_rows;
  m_width = nr_cols;
  m_row = row;
  m_col = col;
}

Frame::Frame(Frame &sw, int nr_rows, int nr_cols, int row, int col)
{
  m_has_super = true;
  m_superw = sw.win();
  m_w = derwin(sw.win(), nr_rows, nr_cols, row, col);
  m_height = nr_rows;
  m_width = nr_cols;
  m_row = row;
  m_col = col;
}

Frame::~Frame()
{
  delwin(m_w);
}

auto Frame::add(Character & c) -> void
{
  mvwaddch(m_w, c.row(), c.col(), c.symbol());
}

auto Frame::erase(Character & c) -> void
{
  mvwaddch(m_w, c.row(), c.col(), ' ');
}

auto Frame::add(Character &c, int row, int col) -> void
{
  if (row >= 0 && row < m_height && col >= 0 && col < m_width) {
    erase(c);
    mvwaddch(m_w, row, col, c.symbol());
    c.adjustPosition(row, col);
  }
}

auto Frame::center(Character &c) -> void
{
  if (m_has_super) {
    int rr = m_row;
    int cc = m_col;
    int hh, ww;

    int _r = c.row() - m_height / 2;
    int _c = c.col() - m_width / 2;

    getmaxyx(m_superw, hh, ww);


    if (_c + m_width >= ww) {
      int delta = ww - (_c + m_width);
        cc = _c - delta;
    }
    else {
      cc = _c;
    }

    if (_r + m_height >= hh) {
      int delta = hh - (_r + m_height);
      rr = _r - delta;
    }
    else {
      rr = _r;
    }

    if (_r < 0) {
      rr = 0;
    }

    if (_c < 0) {
      cc = 0;
    }

    //std::cout << "rr: " << rr << " cc: " << cc << "\n";
    move(rr, cc);

  }
}

void Frame::fillWindow()
{
  int max_x = m_width / 2;
  int max_y = m_height / 2;

  // First region with 0
  for (int y = 0; y < max_y; y++) {
    for (int x = 0; x < max_x; x++) {
      mvwaddch(m_w, y, x, '0');
    }
  }
  // Second region with 3
  for (int y = max_y; y < m_height; y++) {
    for (int x = 0; x < max_x; x++) {
      mvwaddch(m_w, y, x, '3');
    }
  }
  // First region with 1
  for (int y = 0; y < max_y; y++) {
    for (int x = max_x; x < m_width; x++) {
      mvwaddch(m_w, y, x, '1');
    }
  }
  // First region with 2
  for (int y = max_y; y < m_height; y++) {
    for (int x = max_x; x < m_width; x++) {
      mvwaddch(m_w, y, x, '2');
    }
  }

}


void Frame::move(int r, int c)
{
  if (m_has_super) {
    mvderwin(m_w, r, c);
    m_row = r;
    m_col = c;
    refresh();
  }
}

WINDOW* Frame::win()
{
  return m_w;
}

WINDOW* Frame::super()
{
  return m_superw;
}

bool Frame::has_super()
{
  return m_has_super;
}

int Frame::height()
{
  return m_height;
}

int Frame::width()
{
  return m_width;
}

int Frame::row()
{
  return m_row;
}

int Frame::col()
{
  return m_col;
}

void Frame::refresh()
{
  if (m_has_super) { touchwin(m_superw); }
  wrefresh(m_w);
}
