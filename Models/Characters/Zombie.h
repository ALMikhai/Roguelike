#pragma once

#include "Character.h"

class Zombie : public Character{
 public:
  explicit Zombie(Point& pos) : Character(pos,
      Settings::settingsData["ZombieHp"].GetInt(),
      Settings::settingsData["ZombieDamage"].GetInt(),
      Settings::settingsData["ZombieSym"].GetString()[0],
      true) {}
  explicit Zombie(Point&& pos) : Zombie(pos) {}

  void Collide(Character*character) override {
    return character->Collide(*this);
  }
  void Collide(Knight& knight) override;
  void Collide(Wall& wall) override {  }
  void Collide(Floor& floor) override;
  void Collide(Zombie& zombie) override {  }
  void Collide(Princess& knight) override {  }
  void Collide(Dragon& dragon) override;
  void Collide(Bullet& bullet) override;
  void Collide(Aid& aid) override { }
};