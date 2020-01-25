#pragma once

#include "Character.h"

class Floor : public Character{
 public:
  explicit Floor(Point& pos) : Character(pos,
      Settings::settingsData["FloorHp"].GetInt(),
      Settings::settingsData["FloorDamage"].GetInt(),
      Settings::settingsData["FloorSym"].GetString()[0],
      false) {}
  explicit Floor(Point&& pos) : Floor(pos) {}

  void Collide(Character* character) override {
    character->Collide(*this);
  }
  void Collide(Knight& knight) override { _isDrawable = true; }
  void Collide(Wall& wall) override {  }
  void Collide(Floor& floor) override {  }
  void Collide(Zombie& zombie) override {  }
  void Collide(Princess& knight) override {  }
  void Collide(Dragon& dragon) override {  }
  void Collide(Bullet& bullet) override {  }
  void Collide(Aid& aid) override { }
};