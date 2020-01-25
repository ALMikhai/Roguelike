#include "Zombie.h"
#include "Floor.h"
#include "Knight.h"
#include "Dragon.h"
#include "Bullet.h"

void Zombie::Collide(Floor &floor) {
  GetPos() = floor.GetPos();
}

void Zombie::Collide(Knight &knight) {
  GetHp() -= knight.GetDamage();
}

void Zombie::Collide(Dragon &dragon) {
  GetHp() -= dragon.GetDamage();
}

void Zombie::Collide(Bullet &bullet) {
  GetHp() -= bullet.GetDamage();
}