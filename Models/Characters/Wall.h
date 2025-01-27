#pragma once

#include "Character.h"

class Wall : public Character {

 public:
  explicit Wall(Point& pos) : Character(pos,
      Settings::settingsData["WallHp"].GetInt(),
      Settings::settingsData["WallDamage"].GetInt(),
      Settings::settingsData["WallSym"].GetString()[0],
      false) {}
  explicit Wall(Point&& pos) : Wall(pos) {}

  void Collide(Character* character) override {
    character->Collide(*this);
  }
  void Collide(Knight& knight) override {  }
  void Collide(Wall& wall) override {  }
  void Collide(Floor& floor) override {  }
  void Collide(Zombie& zombie) override {  }
  void Collide(Princess& knight) override {  }
  void Collide(Dragon& dragon) override {  }
  void Collide(Bullet& bullet) override {  }
  void Collide(Aid& aid) override { }
};