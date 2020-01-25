#include "Bullet.h"
#include "Floor.h"

void Bullet::Collide(Floor &floor) {
  GetPos() = floor.GetPos();
}