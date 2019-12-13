#define WallHp 30
#define WallDamage 0
#define WallSym '#'

class Wall : public Character {

 public:
  explicit Wall(Point& pos) : Character(pos, WallHp, WallDamage, WallSym) {}
  explicit Wall(Point&& pos) : Wall(pos) {}
};