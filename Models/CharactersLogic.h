#pragma once

#include <map>
#include <ncurses.h>
#include "Characters/Character.h"

class Knight;
class Zombie;
class Dragon;
class Princess;
class Game;

static std::map<const size_t, Point> MoveSides = {
    std::make_pair(KEY_UP, Point(0, -1)),
    std::make_pair(KEY_DOWN, Point(0, 1)),
    std::make_pair(KEY_LEFT, Point(-1, 0)),
    std::make_pair(KEY_RIGHT, Point(1, 0)),
};

static std::map<const size_t, Point> ShootSides = {
    std::make_pair(119, Point(0, -1)),
    std::make_pair(115, Point(0, 1)),
    std::make_pair(97, Point(-1, 0)),
    std::make_pair(100, Point(1, 0)),
};

class CharactersLogic {
 public:
  using CharacterType = std::unique_ptr<Character>;

  explicit CharactersLogic(Game& game);
  void Update(CharacterType& character);
  void Move(CharacterType& character);
  void WaitAction(CharacterType &character);
  bool KnightIsClose( Character* character);
  Point BFS(Point& start);

 private:
  Game& _game;
  void UpdateKnight(Knight* knight);
  void MoveKnight(Knight* knight, Point side);

  void UpdateZombie(Zombie* zombie);
  void MoveZombie(Zombie* zombie);

  void UpdateDragon(Dragon* knight);
  void MoveDragon(Dragon* knight);

  void UpdatePrincess(Princess* knight);
  void MovePrincess(Princess* knight);

  void UpdateBullet(Bullet* bullet);
  void MoveBullet(Bullet* bullet);

  void Shoot(Character* character, Point& side);
  void CharacterMove(Character* character, const Point& side);
  Character* findCharOnPos (Point& pos);
  static Point& ChooseRandomSide ();
};