#pragma once

#include "Character.h"

class Dragon : public Character{
 public:
  explicit Dragon(Point& pos) : Character(pos,
      Settings::settingsData["DragonHp"].GetInt(),
      Settings::settingsData["DragonDamage"].GetInt(),
      Settings::settingsData["DragonSym"].GetString()[0],
      true) {}
  explicit Dragon(Point&& pos) : Dragon(pos) {}

  void Collide(Character* character) override {
    character->Collide(*this);
  }
  void Collide(Knight& knight) override;
  void Collide(Wall& wall) override { }
  void Collide(Floor& floor) override;
  void Collide(Zombie& zombie) override;
  void Collide(Princess& knight) override { }
  void Collide(Dragon& dragon) override { }
  void Collide(Bullet& bullet) override;
  void Collide(Aid& aid) override { }
};