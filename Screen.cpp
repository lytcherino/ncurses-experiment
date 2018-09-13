#include "Screen.h"

Screen::Screen()
{
  initscr();
  clear();
  noecho();
  cbreak();
  keypad(stdscr, TRUE);
  curs_set(0);

  // Get screen dimensions
  getmaxyx(stdscr, m_height, m_width);
}

Screen::~Screen()
{
  endwin();
}

auto Screen::add(const std::string& message) -> void
{
  printw(message.c_str());
}

auto Screen::height() const -> decltype(m_height)
{
  return m_height;
}

auto Screen::width() const -> decltype(m_width)
{
  return m_width;
}
