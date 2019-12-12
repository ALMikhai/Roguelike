#include "Character.h"

#define maxHp 30
#define sym '#'

class Wall : public Character {

 public:
  Wall(Point& pos) : _pos(pos), _maxHp(maxHp), _hp(maxHp), _sym(sym) {}
  Wall(Point&& pos) : Wall(pos) {}
//  Wall(Wall& wall) : _pos(wall._pos), _maxHp(wall._maxHp), _hp(wall._hp), _sym(wall._sym) {}
//  Wall(Wall&& wall) : Wall(wall) {}

  Point& GetPos() override {
    return _pos;
  }

  size_t& GetHp() override {
    return _hp;
  }

  const char& GetSym() const override {
    return _sym;
  }

 private:
  Point _pos;
  size_t _maxHp;
  size_t _hp;
  char _sym;
};