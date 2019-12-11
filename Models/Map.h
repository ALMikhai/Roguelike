#include <vector>
#include <string>

class Map {
  using mapType = std::vector<std::vector<std::string>>;

 public:
  size_t _width;
  size_t _height;
  mapType _data;

  Map() : _width(0), _height(0), _data() {}
  explicit Map(mapType& data) : _width(data[0].size()), _height(data.size()), _data(data) {}
  Map(int width, int height) : _width(width), _height(height), _data(height) {}
};