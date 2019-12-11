#include <iostream>
#include "Models/MapDraw.h"

//cd /home/alexander/Документы/CLionProjects/Roguelike/cmake-build-debug/

int main() {
  Map map(10, 10);
  MapDraw::Draw(map);
  return 0;
}