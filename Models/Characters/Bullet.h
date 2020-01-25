#pragma once

#include "Character.h"

class Bullet : public Character{
 public:
  Point Side;

  explicit Bullet(Point& pos, int& damage, Point& side) : Character(pos,
      Settings::settingsData["BulletHp"].GetInt(),
      damage,
      Settings::settingsData["BulletSym"].GetString()[0],
      false),
      Side(side) {}

  void Collide(Character* character) override {
    character->Collide(*this);
  }
  void Collide(Knight& knight) override { GetHp() = 0; }
  void Collide(Wall& wall) override { GetHp() = 0; }
  void Collide(Floor& floor) override;
  void Collide(Zombie& zombie) override { GetHp() = 0;  }
  void Collide(Princess& knight) override { GetHp() = 0; }
  void Collide(Dragon& dragon) override { GetHp() = 0; }
  void Collide(Bullet& bullet) override { GetHp() = 0; }
  void Collide(Aid& aid) override { GetHp() = 0; }

  Point& GetSide() {
    return Side;
  }
};
