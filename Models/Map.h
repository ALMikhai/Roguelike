#include <vector>
#include <string>
#include <memory>
#include <ncurses.h>
#include <cstdlib>
#include "Characters/Wall.h"
#include "Characters/Floor.h"
#include "Characters/Knight.h"

class Map {
  using mapType = std::vector<std::vector<std::unique_ptr<Character>>>;
  using mapElement = std::unique_ptr<Character>;

 public:
  Map(size_t width, size_t height) : _width(width), _height(height), _data(height), _knightPos(0, 0){
    for (size_t i = 0; i < height; ++i) {
      for (size_t j = 0; j < width; ++j) {
        if(i == 0 || j == 0 || i == _height - 1 || j == _width - 1)
          _data[i].push_back(mapElement (new Wall(Point(j, i))));
        else
          _data[i].push_back(mapElement (new Floor(Point(j, i))));
      }
    }

    Point knightPos = findFreePosition();
    _knightPos = knightPos;
    _data[knightPos.Y][knightPos.X] = mapElement (new Knight(knightPos));
  }

  void Draw() const {
    for (const auto& row : _data) {
      for (const auto& cell : row) {
        mvaddch(cell->GetPos().Y, cell->GetPos().X, cell->GetSym());
      }
    }
  }

  bool KnightMove(Point side) {
    Point newPos = _knightPos + side;
    mapElement& knight = _data[_knightPos.Y][_knightPos.X];
    mapElement& newPlace = _data[newPos.Y][newPos.X];

    if (newPlace->GetSym() == FloorSym) {
      swapCells(knight, newPlace);
      _knightPos = newPos;
      return true;
    }

    return false;
  }

 private:
  size_t _width;
  size_t _height;
  mapType _data;

  Point _knightPos;

  Point findFreePosition() {
    Point result(0, 0);

    do {
      result.X = rand() % _width;
      result.Y = rand() % _height;
    } while (_data[result.X][result.Y]->GetSym() != FloorSym);

    return result;
  }

  void swapCells(mapElement& a, mapElement& b) {
    a.swap(b);
    Point tmp = a->GetPos();
    a->GetPos() = b->GetPos();
    b->GetPos() = tmp;
  }
};
