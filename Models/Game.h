#include "Map.h"

#define mapSize 20

//TODO Словарь с направлениями, где ключ код клавиши, а значение point.

class Game{
 public:
  Map _map;
  Game() : _map(mapSize, mapSize) {}
  void Start() {
    initscr();
    noecho();
    keypad(stdscr, TRUE);

    while(true) {
      clear();
      _map.Draw();
      refresh();

      bool moveDone = false;
      size_t input = 0;

      while (!moveDone && input != 27) {
        input = getch();
        if (input == KEY_UP) {
          moveDone = _map.KnightMove(Point(0, -1));
        }
      }

      if (input == 27)
        break;
    }

    endwin();
  }

 private:

};