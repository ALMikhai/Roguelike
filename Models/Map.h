#include <vector>
#include <string>
#include <ncurses.h>
#include "Characters/Wall.h"

class Map {
  using mapType = std::vector<std::vector<Wall>>;

 public:
  Map() : _width(0), _height(0), _data() {}
  explicit Map(Map& map) : _width(map._data[0].size()), _height(map._data.size()), _data(map._data) {}
  Map(size_t width, size_t height) : _width(width), _height(height), _data(height) {
    for (size_t i = 0; i < height; ++i) {
      for (size_t j = 0; j < width; ++j) {
        Wall a(Point(i, j));
        _data[i].emplace_back(Wall(a));
      }
    }
  }

  size_t getHeight() const {
    return _height;
  }

  size_t getWidth() const {
    return _width;
  }

  mapType& getData() {
    return _data;
  }

  void Draw() const {
    initscr();
    for (size_t i = 0; i < getHeight(); ++i) {
      for (size_t j = 0; j < getWidth(); ++j) {
        mvaddch(j, i, _data[i][j].GetSym());
      }
    }
    refresh();
    getch();
    endwin();
  }

 private:
  size_t _width;
  size_t _height;
  mapType _data;
};
