#include "Knight.h"
#include "Zombie.h"
#include "Floor.h"
#include "Dragon.h"
#include "Princess.h"
#include "Bullet.h"
#include "Aid.h"

void Knight::Collide(Floor &floor) {
  GetPos() = floor.GetPos();
}

void Knight::Collide(Princess &princess) {
  GetPos() = princess.GetPos();
}

void Knight::Collide(Zombie &zombie) {
  GetHp() -= zombie.GetDamage();
}

void Knight::Collide(Dragon &dragon) {
  GetHp() -= dragon.GetDamage();
}

void Knight::Collide(Bullet &bullet) {
  GetHp() -= bullet.GetDamage();
}

void Knight::Collide(Aid &aid) {
  GetHp() = _maxHp;
  GetPos() = aid.GetPos();
}