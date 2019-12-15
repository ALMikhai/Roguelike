#include <cstdio>

class Point{
 public:
  int32_t X;
  int32_t Y;

  Point() = default;
  Point(int32_t x, int32_t y) : X(x), Y(y) {}
//  Point(Point& tmp) : Point(tmp.X, tmp.Y) {}

  Point operator=(const Point& point) {
    X = point.X;
    Y = point.Y;
    return *this;
  }

  Point operator+(const Point& point) const {
    return Point(X + point.X, Y + point.Y);
  }

  bool operator==(const Point& point) const {
    return X == point.X && Y == point.Y;
  }

  bool operator!=(const Point& point) const {
    return !(*this == point);
  }
};