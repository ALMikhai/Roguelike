#pragma once

#include "Characters/Character.h"

class Collider {
 public:
  static void Collide(Character* from, Character* to) {
    from->Collide(to);
    to->Collide(from);
  }
};