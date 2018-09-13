#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <string>

class Screen
{
  int m_height, m_width;

public:
  // Initialise ncurses library
  Screen();
  // Clear ncurses
  ~Screen();

  // Print message to the screen
  auto add (const std::string& message) -> void;

  // Get screen height and width
  auto height() const -> decltype(m_height);
  auto width() const -> decltype(m_width);
};

#endif
