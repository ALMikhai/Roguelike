class Map {
  using mapType = std::vector<std::vector<std::unique_ptr<Character>>>;
  using mapElement = std::unique_ptr<Character>;

 public:
  Map(size_t width, size_t height) : _width(width), _height(height), _data(height) {
    for (size_t i = 0; i < height; ++i) {
      for (size_t j = 0; j < width; ++j) {
        if(i == 0 || j == 0 || i == _height - 1 || j == _width - 1)
          _data[i].push_back(mapElement (new Wall(Point(j, i))));
        else
          _data[i].push_back(mapElement (new Floor(Point(j, i))));
      }
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
  size_t _width;
  size_t _height;
  mapType _data;
};
