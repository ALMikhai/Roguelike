#include <vector>
#include <string>
#include <memory>
#include <ncurses.h>
#include "Characters/Wall.h"
#include "Characters/Floor.h"
#include "Characters/Knight.h"

class Map {
  using mapType = std::vector<std::vector<std::unique_ptr<Character>>>;
  using mapElement = std::unique_ptr<Character>;

 public:
  Map(size_t width, size_t height) : _width(width), _height(height), _data(height) {
    for (size_t i = 0; i < height; ++i) {
      for (size_t j = 0; j < width; ++j) {
        if(i == 0 || j == 0 || i == _height - 1 || j == _width - 1)
          _data[i].push_back(mapElement (new Wall(Point(i, j))));
        else
          _data[i].push_back(mapElement (new Floor(Point(i, j))));
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
    for (size_t i = 0; i < getHeight(); ++i) {
      for (size_t j = 0; j < getWidth(); ++j) {
        mvaddch(j, i, _data[i][j]->GetSym());
      }
    }
  }

 private:
  size_t _width;
  size_t _height;
  mapType _data;
};
