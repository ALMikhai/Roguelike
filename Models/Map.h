#define r1_cutoff 5
#define r2_cutoff 2
#define generateIterations 4
#define extraGenerateIterations 3
#define randPercent 40

class Map {
  using mapType = std::vector<std::vector<std::unique_ptr<Character>>>;
  using mapElement = std::unique_ptr<Character>;

 public:
  Map(int32_t width, int32_t height) : _width(width), _height(height), _data(height), _dataTmp(height) {
    for (int32_t  i = 0; i < height; ++i) {
      for (int32_t j = 0; j < width; ++j) {
        if(i == 0 || j == 0 || i == _height - 1 || j == _width - 1)
          _data[i].push_back(mapElement (new Wall(Point(j, i))));
        else
          if (randpick())
            _data[i].push_back(mapElement (new Wall(Point(j, i))));
          else
            _data[i].push_back(mapElement (new Floor(Point(j, i))));
        _dataTmp[i].push_back(mapElement (new Wall(Point(j, i))));
      }
    }

    for (int i = 0; i < generateIterations; ++i) {
      generationLevel(true);
    }
    for (int i = 0; i < extraGenerateIterations; ++i) {
      generationLevel(false);
    }
  }

  void Draw() const {
    for (const auto& row : _data) {
      for (const auto& cell : row) {
        mvaddch(cell->GetPos().Y, cell->GetPos().X, cell->GetSym());
      }
    }
  }

  bool CheckCellForStep (Point pos) {
    return  _data[pos.Y][pos.X]->GetSym() == FloorSym;
  }

 private:
  int32_t _width;
  int32_t _height;
  mapType _data;
  mapType _dataTmp;

  void generationLevel(bool useSecondProperty) {
    for (int32_t y = 1; y < _height - 1; ++y) {
      for (int32_t x = 1; x < _width - 1; ++x) {
        int32_t floors = 0;
        int32_t walls = 0;

        for (int32_t I = -1; I <= 1; ++I) {
          for (int32_t J = -1; J <= 1; ++J) {
            if (_data[y + I][x + J]->GetSym() != FloorSym) {
              floors++;
            }
          }
        }

        for (int32_t I = y - 2; I <= y + 2; ++I) {
          for (int32_t J = x - 2; J <= x + 2; ++J) {
            if (abs(I - y) == 2 && abs(J - x) == 2)
              continue;
            if (J < 0 || I < 0 || I >= _height || J >= _width)
              continue;
            if (_data[I][J]->GetSym() != FloorSym)
              walls++;
          }
        }

        if (floors >= r1_cutoff || (useSecondProperty && walls <= r2_cutoff))
          _dataTmp[y][x] = mapElement(new Wall(Point(x, y)));
        else
          _dataTmp[y][x] = mapElement(new Floor(Point(x, y)));
      }
    }

    for (int32_t y = 1; y < _height - 1; ++y) {
      for (int32_t x = 1; x < _width - 1; ++x) {
        _data[y][x].swap(_dataTmp[y][x]);
      }
    }
  }

  bool randpick() {
    return rand() % 100 < randPercent;
  }
};
