#include "../Point.h"

class Character {
 public:
  Character(Point& pos, size_t hp, size_t damage, char sym) :
    _pos(pos), _maxHp(hp), _hp(hp), _damage(damage), _sym(sym) {}
  virtual Point& GetPos() {
    return _pos;
  }
  virtual size_t& GetHp() {
    return _hp;
  }
  virtual const char& GetSym() const {
    return _sym;
  }
  virtual const size_t& GetDamage() {
    return _damage;
  }

  virtual ~Character() = default;

 private:
  Point _pos;
  size_t _maxHp;
  size_t _hp;
  size_t _damage;
  char _sym;
};