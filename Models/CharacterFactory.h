#pragma once

#include <map>
#include <string>
#include <memory>
#include "Characters/Knight.h"
#include "Characters/Zombie.h"
#include "Characters/Princess.h"
#include "Characters/Dragon.h"
#include "Characters/Wall.h"
#include "Characters/Bullet.h"
#include "Characters/Floor.h"
#include "Characters/Aid.h"

enum Characters {ZOMBIE, KNIGHT, DRAGON, PRINCESS, WALL, FLOOR, AID};

class CharacterFactory {
 public:
  using CharacterType = std::unique_ptr<Character>;
  static CharacterType Create(Characters type, Point pos) {
    switch (type) {
      case ZOMBIE:
        return CharacterType (new Zombie(pos));
      case KNIGHT:
        return CharacterType (new Knight(pos));
      case DRAGON:
        return CharacterType (new Dragon(pos));
      case PRINCESS:
        return CharacterType (new Princess(pos));
      case WALL:
        return CharacterType (new Wall(pos));
      case FLOOR:
        return CharacterType (new Floor(pos));
      case AID:
        return CharacterType (new Aid(pos));
    }
    return CharacterType (new Zombie(pos));
  }

  static CharacterType Create(Character* character, Point side) {
    auto position = character->GetPos();// + side;
    return CharacterType (new Bullet(position, character->GetDamage(), side));
  }
};
