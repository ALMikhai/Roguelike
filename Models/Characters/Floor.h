#define FloorHp 0
#define FloorSym '.'

class Floor : public Character{
 public:
  explicit Floor(Point& pos) : _pos(pos), _maxHp(WallHp), _hp(FloorHp), _sym(FloorSym) {}
  explicit Floor(Point&& pos) : Floor(pos) {}

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