#define PrincessHp 1
#define PrincessDamage 0
#define PrincessSym 'P'

class Princess : public Character{
 public:
  explicit Princess(Point& pos) : Character(pos, PrincessHp, PrincessDamage, PrincessSym) {}
  explicit Princess(Point&& pos) : Princess(pos) {}
};