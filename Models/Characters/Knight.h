#define KnightHp 10
#define KnightDamage 3
#define KnightSym '@'

class Knight : public Character {
 public:
  explicit Knight(Point& pos) : Character(pos, KnightHp, KnightDamage, KnightSym) {}
  explicit Knight(Point&& pos) : Knight(pos) {}
};