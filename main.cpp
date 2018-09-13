#include "Screen.h"
#include "Frame.h"
#include "Character.h"

void game_loop(Frame &game_map, Frame &viewport, Character &main_char, int ch);

int main()
{
  Screen scr;

  scr.add("Welcome to this world!");

  int ch = getch();

  Frame game_map(2*scr.height(), 2*scr.width(), 0, 0);

  Frame viewport(game_map, scr.height(), scr.width(), 0, 0);

  Character main_char('@', game_map.height()/2, game_map.width()/2);

  game_map.fillWindow();

  game_loop(game_map, viewport, main_char, ch);

  return 0;

}

void game_loop(Frame &game_map, Frame &viewport, Character &main_char, int ch)
{
  if (ch == 'q' || ch == 'Q') { return; }

  // Show main character on the screen
  game_map.add(main_char);
  viewport.center(main_char);
  viewport.refresh();

  while(true) {
    ch = getch();

    int colAdjust = 0;
    int rowAdjust = 0;
    // Main character movements
    if (ch == KEY_LEFT) {
      colAdjust = -1;
    }
    else if (ch == KEY_RIGHT) {
      colAdjust = 1;
    }
    else if (ch == KEY_UP) {
      rowAdjust = -1;
    }
    else if (ch == KEY_DOWN) {
      rowAdjust = 1;
    }
    else if (ch == 'q' || ch == 'Q') { break; }

    game_map.add(main_char, main_char.row() + rowAdjust, main_char.col() + colAdjust);
    viewport.center(main_char);
    viewport.refresh();

  }


}
