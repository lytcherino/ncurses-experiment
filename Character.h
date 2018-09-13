#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
  int m_row, m_col;
  char m_symbol;
public:
  Character(char symbol, int row, int col);

  auto adjustPosition(int row, int col) -> void;

  auto row() const -> decltype(m_row);
  auto col() const -> decltype(m_col);
  auto symbol() const -> decltype(m_symbol);

};

#endif
