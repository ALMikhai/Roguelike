#include "Character.h"

#define WallHp 30
#define WallSym '#'

class Wall : public Character {

 public:
  explicit Wall(Point& pos) : _pos(pos), _maxHp(WallHp), _hp(WallHp), _sym(WallSym) {}
  explicit Wall(Point&& pos) : Wall(pos) {}

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