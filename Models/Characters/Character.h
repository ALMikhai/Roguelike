#pragma once

#include <memory>
#include <utility>
#include <ncurses.h>
#include "../Point.h"
#include "../Settings/Settings.h"

//enum CollideResult { BAD, NEXT, WIN, DIE };

class Floor;
class Wall;
class Princess;
class Zombie;
class Knight;
class Dragon;
class Bullet;
class Aid;

class Character {
 public:
  template <typename T>
  using CharPtr = std::unique_ptr<T>;

  Character(Point& pos, int32_t hp, size_t damage, char sym, bool drawable) :
    _pos(pos), _maxHp(hp), _hp(hp), _damage(damage), _sym(sym), _isDrawable(drawable) {}
  virtual Point& GetPos() {
    return _pos;
  }
  virtual int& GetHp() {
    return _hp;
  }
  virtual const char GetSym() const {
    return _sym;
  }
  virtual int& GetDamage() {
    return _damage;
  }
  bool IsDead() {
    return (GetHp() <= 0);
  }
  bool IsDrawable() {
    return _isDrawable;
  }

  virtual void Collide(Character* character) = 0;
  virtual void Collide(Knight& knight) = 0;
  virtual void Collide(Wall& wall) = 0;
  virtual void Collide(Floor& floor) = 0;
  virtual void Collide(Zombie& zombie) = 0;
  virtual void Collide(Princess& knight) = 0;
  virtual void Collide(Dragon& dragon) = 0;
  virtual void Collide(Bullet& bullet) = 0;
  virtual void Collide(Aid& aid) = 0;

  virtual ~Character() = default;

 protected:
  Point _pos;
  int _maxHp;
  int _hp;
  int _damage;
  char _sym;
  bool _isDrawable;
};