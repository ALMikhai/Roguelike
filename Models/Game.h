#include <map>
#include "Map.h"

#define mapSize 20

static std::map<size_t, Point> Sides = {
    std::make_pair(KEY_UP, Point(0, -1)),
    std::make_pair(KEY_DOWN, Point(0, 1)),
    std::make_pair(KEY_LEFT, Point(-1, 0)),
    std::make_pair(KEY_RIGHT, Point(1, 0)),
};

class Game{
 public:

  Game() : _map(mapSize, mapSize) {}
  void Start() {
    initscr();
    noecho();
    keypad(stdscr, TRUE);

    while(true) {
      clear();
      _map.Draw(); // Draw.
      refresh();

      bool moveDone = false;
      size_t input = 0;

      while (!moveDone && input != 27) { // Wait action.
        input = getch();
        auto side = Sides.find(input);
        if (side != Sides.end())
          moveDone = _map.KnightMove(side->second);
      }

      if (input == 27)
        break;
    }

    endwin();
  }

 private:
  Map _map;
};