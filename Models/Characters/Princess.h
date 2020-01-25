#pragma once

#include "Character.h"

class Princess : public Character{
 public:
  explicit Princess(Point& pos) : Character(pos,
      Settings::settingsData["PrincessHp"].GetInt(),
      Settings::settingsData["PrincessDamage"].GetInt(),
      Settings::settingsData["PrincessSym"].GetString()[0],
      true) {}
  explicit Princess(Point&& pos) : Princess(pos) {}

  void Collide(Character* character) override {
    character->Collide(*this);
  }
  void Collide(Knight& knight) override {  }
  void Collide(Wall& wall) override {  }
  void Collide(Floor& floor) override {  }
  void Collide(Zombie& zombie) override {  }
  void Collide(Princess& knight) override {  }
  void Collide(Dragon &dragon) override {  }
  void Collide(Bullet& bullet) override {  }
  void Collide(Aid& aid) override { }
};