#include "Character.h"

#define maxHp 100
#define sym '@'

class Knight : public Character {
 public:
  explicit Knight(Point& pos) : _pos(pos), _maxHp(maxHp), _hp(maxHp), _sym(sym) {}

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