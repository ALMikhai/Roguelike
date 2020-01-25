#pragma once

#include "Character.h"

class Aid : public Character{
 public:
  explicit Aid(Point& pos) : Character(pos,
   Settings::settingsData["AidHp"].GetInt(),
   Settings::settingsData["AidDamage"].GetInt(),
   Settings::settingsData["AidSym"].GetString()[0],
   true) {}
  explicit Aid(Point&& pos) : Aid(pos) {}

  void Collide(Character* character) override {
    character->Collide(*this);
  }
  void Collide(Knight& knight) override { GetHp() = 0; }
  void Collide(Wall& wall) override {  }
  void Collide(Floor& floor) override {  }
  void Collide(Zombie& zombie) override {  }
  void Collide(Princess& knight) override {  }
  void Collide(Dragon& dragon) override {  }
  void Collide(Bullet& bullet) override {  }
  void Collide(Aid& aid) override { }
};