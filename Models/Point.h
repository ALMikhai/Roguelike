#include <cstdio>

class Point{
 public:
  int32_t X;
  int32_t Y;
  Point(int32_t x, int32_t y) : X(x), Y(y) {}

  Point operator+(const Point& point) const {
    return Point(X + point.X, Y + point.Y);
  }
};