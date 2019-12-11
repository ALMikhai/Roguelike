#include <vector>
#include <string>

class Map {
  using mapType = std::vector<std::string>;

 public:
  Map() : _width(0), _height(0), _data() {}
  explicit Map(mapType& data) : _width(data[0].size()), _height(data.size()), _data(data) {}
  Map(size_t width, size_t height) : _width(width), _height(height), _data(height) {
    for (size_t i = 0; i < height; ++i) {
      for (size_t j = 0; j < width; ++j) {
        _data[i] += '.';
      }
    }
  }

  size_t getHeight() const {
    return _height;
  }

  size_t getWidth() const {
    return _width;
  }

  mapType getData() const {
    return _data;
  }

 private:
  size_t _width;
  size_t _height;
  mapType _data;
};
