#include <ncurses.h>
#include "Map.h"

class MapDraw {
 public:
  MapDraw() = default;
  static void Draw(const Map& map) {
    initscr();
    for (size_t i = 0; i < map.getHeight(); ++i) {
      for (size_t j = 0; j < map.getWidth(); ++j) {
        mvaddch(j, i, map.getData()[i][j]);
      }
    }
    refresh();
    getch();
    endwin();
  }
};