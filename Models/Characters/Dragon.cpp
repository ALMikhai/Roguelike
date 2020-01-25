#include "Dragon.h"
#include "Floor.h"
#include "Knight.h"
#include "Zombie.h"
#include "Bullet.h"

void Dragon::Collide(Floor &floor) {
  GetPos() = floor.GetPos();
}

void Dragon::Collide(Knight &knight) {
  GetHp() -= knight.GetDamage();
}

void Dragon::Collide(Zombie &zombie) {
  GetHp() -= zombie.GetDamage();
}

void Dragon::Collide(Bullet &bullet) {
  GetHp() -= bullet.GetDamage();
}
