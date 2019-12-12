#define KnightHp 100
#define KnightSym '@'

class Knight : public Character {
 public:
  explicit Knight(Point& pos) : _pos(pos), _maxHp(KnightHp), _hp(KnightHp), _sym(KnightSym) {}
  explicit Knight(Point&& pos) : Knight(pos) {}

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