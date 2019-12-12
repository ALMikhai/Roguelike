#include "Map.h"

#define mapSize 50

class Game{
 public:
  Game() : _map(mapSize, mapSize) {}
  void Start() {
    initscr();
    noecho();
    keypad(stdscr, TRUE);

    while(true) {
      clear();
      _map.Draw();
      refresh();

      if (getch() == 27)
        break;
    }

    endwin();
  }

 private:
  Map _map;
};