#define FloorHp 0
#define FloorDamage 0
#define FloorSym '.'

class Floor : public Character{
 public:
  explicit Floor(Point& pos) : Character(pos, FloorHp, FloorDamage, FloorSym) {}
  explicit Floor(Point&& pos) : Floor(pos) {}
};