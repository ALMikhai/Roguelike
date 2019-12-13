#include <map>
#include <vector>
#include <string>
#include <memory>
#include <ncurses.h>
#include <cstdlib>
#include "Characters/Character.h"
#include "Characters/Wall.h"
#include "Characters/Floor.h"
#include "Characters/Knight.h"
#include "Characters/Princess.h"
#include "Map.h"

#define mapSize 40

static std::map<size_t, Point> Sides = {
    std::make_pair(KEY_UP, Point(0, -1)),
    std::make_pair(KEY_DOWN, Point(0, 1)),
    std::make_pair(KEY_LEFT, Point(-1, 0)),
    std::make_pair(KEY_RIGHT, Point(1, 0)),
};

class Game {
 public:

  Game() : _map(mapSize, mapSize) {}
  void Start() {
    initscr();
    noecho();
    keypad(stdscr, TRUE);

    while (true) {
      clear();
      _map.Draw(); // Draw.
      refresh();

      TurnResult turnResult = BAD;
      size_t input = 0;

      while (turnResult == BAD && input != 27) { // Wait action.
        input = getch();
        auto side = Sides.find(input);
        if (side != Sides.end())
          turnResult = _map.KnightMove(side->second);
      }

      if (turnResult == WIN) {
        Win();
      }

      if (input == 27)
        break;
    }

    endwin();
  }

 private:
  void Win() {
    clear();
    _map = Map(mapSize, mapSize);
  }

  void Restart() {

  }

  Map _map;
};