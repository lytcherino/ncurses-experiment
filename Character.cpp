#include "Character.h"

Character::Character(char symbol, int row, int col) : m_symbol(symbol), m_row(row), m_col(col)
{
  
}

auto Character::adjustPosition( int row, int col ) -> void
{
  m_row = row;
  m_col = col;
}

auto Character::row() const -> decltype(m_row)
{
  return m_row;
}

auto Character::col() const -> decltype(m_col)
{
  return m_col;
}

auto Character::symbol() const -> decltype(m_symbol)
{
  return m_symbol;
}
