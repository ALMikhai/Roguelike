#define ZombieHp 3
#define ZombieDamage 2
#define ZombieSym 'Z'

class Zombie : public Character{
 public:
  explicit Zombie(Point& pos) : Character(pos, ZombieHp, ZombieDamage, ZombieSym) {}
  explicit Zombie(Point&& pos) : Zombie(pos) {}
};