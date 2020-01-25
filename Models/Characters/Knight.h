#pragma once

#include "Character.h"

class Knight : public Character {
 public:
  explicit Knight(Point& pos) : Character(pos,
      Settings::settingsData["KnightHp"].GetInt(),
      Settings::settingsData["KnightDamage"].GetInt(),
      Settings::settingsData["KnightSym"].GetString()[0],
      true) {}
  explicit Knight(Point&& pos) : Knight(pos) {}

  void Collide(Character* character) override {
    return character->Collide(*this);
  }
  void Collide(Knight& knight) override { }
  void Collide(Wall& wall) override { }
  void Collide(Floor& floor) override;
  void Collide(Zombie& zombie) override;
  void Collide(Princess& knight) override;
  void Collide(Dragon& dragon) override;
  void Collide(Bullet& bullet) override;
  void Collide(Aid& aid) override;
};