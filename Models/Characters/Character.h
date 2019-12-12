#include "../Point.h"

class Character {
 public:
  virtual Point& GetPos() = 0;
  virtual size_t& GetHp() = 0;
  virtual const char& GetSym() const = 0;
  virtual ~Character() = default;
};