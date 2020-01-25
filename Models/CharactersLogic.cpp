#include <iostream>
#include <queue>
#include "CharactersLogic.h"
#include "Characters/Character.h"
#include "Characters/Knight.h"
#include "Characters/Bullet.h"
#include "Game.h"
#include "Collider.h"
#include "Windows/PauseMenuWindow.h"

#define ButtonPauseGame 27
#define DistanceToPursuit 20

CharactersLogic::CharactersLogic(Game &game): _game(game) {}

void CharactersLogic::Update(CharacterType &character) {
  if (Settings::settingsData["ZombieSym"].GetString()[0] == character->GetSym()) {
    UpdateZombie(reinterpret_cast<Zombie*>(character.get()));
    return;
  }

  if (Settings::settingsData["PrincessSym"].GetString()[0] == character->GetSym()) {
    UpdatePrincess(reinterpret_cast<Princess*>(character.get()));
    return;
  }

  if (Settings::settingsData["DragonSym"].GetString()[0] == character->GetSym()) {
    UpdateDragon(reinterpret_cast<Dragon*>(character.get()));
    return;
  }

  if (Settings::settingsData["KnightSym"].GetString()[0] == character->GetSym()) {
    UpdateKnight(reinterpret_cast<Knight*>(character.get()));
    return;
  }

  if (Settings::settingsData["BulletSym"].GetString()[0] == character->GetSym()) {
    UpdateBullet(reinterpret_cast<Bullet*>(character.get()));
    return;
  }
}

void CharactersLogic::Move(CharacterType &character) {
  if (Settings::settingsData["ZombieSym"].GetString()[0] == character->GetSym()) {
    MoveZombie(reinterpret_cast<Zombie*>(character.get()));
    return;
  }

  if (Settings::settingsData["PrincessSym"].GetString()[0] == character->GetSym()) {
    MovePrincess(reinterpret_cast<Princess*>(character.get()));
    return;
  }

  if (Settings::settingsData["DragonSym"].GetString()[0] == character->GetSym()) {
    MoveDragon(reinterpret_cast<Dragon*>(character.get()));
    return;
  }

  if (Settings::settingsData["BulletSym"].GetString()[0] == character->GetSym()) {
    MoveBullet(reinterpret_cast<Bullet*>(character.get()));
    return;
  }
}

Character * CharactersLogic::findCharOnPos(Point &pos) {
  if (_game._knight->GetPos() == pos)
  return _game._knight.get();

  for (auto& item : _game._chars) {
    if (item != nullptr && item->GetPos() == pos) {
      return item.get();
    }
  }

  return _game._map.GetCell(pos);
}

void CharactersLogic::CharacterMove(Character *character, const Point &side) {
  Point newPos = character->GetPos() + side;
  Collider::Collide(character, findCharOnPos(newPos));
}

Point& CharactersLogic::ChooseRandomSide() {
  return MoveSides[(rand() % 4 + KEY_DOWN)];
}

void CharactersLogic::Shoot(Character* character, Point& side) {
  _game._bullets.push_back(CharacterFactory::Create(character, side));
}

void CharactersLogic::WaitAction(CharacterType &character) {
  timeout(Settings::settingsData["WaitingDelay"].GetInt()); // Time to wait action from player.
  size_t input = getch();
  if (input == ButtonPauseGame)
    PauseMenu::ShowPauseMenu(_game);

  auto moveSide = MoveSides.find(input);
  if (moveSide != MoveSides.end()) {
    MoveKnight(reinterpret_cast<Knight*>(character.get()), moveSide->second);
    return;
  }

  auto shootSide = ShootSides.find(input);
  if (shootSide != ShootSides.end()) {
    Shoot(character.get(), shootSide->second);
    return;
  }
}

bool CharactersLogic::KnightIsClose(Character *character) {
  auto x = abs(_game._knight->GetPos().X - character->GetPos().X);
  auto y = abs(_game._knight->GetPos().Y - character->GetPos().Y);
  return (x <= DistanceToPursuit && y <= DistanceToPursuit);
}

Point CharactersLogic::BFS(Point &start) {
  std::queue<Point> q;
  q.push(start);
  int d[_game._map.Height][_game._map.Width];
  int mark[_game._map.Height][_game._map.Width];
  Point p[_game._map.Height][_game._map.Width];

  for (int i = 0; i < _game._map.Height; ++i)
    for (int j = 0; j < _game._map.Width; ++j)
      mark[i][j] = 0;

  d[start.Y][start.X] = 0;
  mark[start.Y][start.X] = 1;
  p[start.Y][start.X] = Point(-1, -1);

  char floorSym = Settings::settingsData["FloorSym"].GetString()[0];

  while(!q.empty()) {
    auto point = q.front();
    q.pop();

    for (int i = -1; i < 2; ++i) {
      for (int j = -1; j < 2; ++j) {
        if (abs(i) == abs(j))
          continue;

        auto x = point.X + j;
        auto y = point.Y + i;

        if (x < 0 || y < 0 || x >= _game._map.Width || y >= _game._map.Height)
          continue;

        Point pos(x, y);
        auto charOnPos = findCharOnPos(pos);
        if (mark[y][x] == 0 && (charOnPos->GetSym() == floorSym || charOnPos->GetSym() == _game._knight->GetSym())) {
          d[y][x] = d[point.Y][point.X] + 1;
          p[y][x] = point;
          mark[y][x] = 1;
          q.push(pos);
        }
      }
    }
  }

  Point to = _game._knight->GetPos();

  if (mark[to.Y][to.X] == 0)
    return ChooseRandomSide();

  Point result(0, 0);
  for (Point x = to; p[x.Y][x.X] != Point(-1, -1); x = p[x.Y][x.X] )
    result = x;

  return Point(result.X - start.X, result.Y - start.Y);
}

void CharactersLogic::UpdateKnight(Knight *knight) {
  if (knight->IsDead())
    _game._playerIsAlive = false;
}

void CharactersLogic::MoveKnight(Knight *knight, Point side) {
  CharacterMove((Character *) knight, side);
}

void CharactersLogic::MoveDragon(Dragon *dragon) {
  if (rand() % 100 < 33)
    Shoot(dragon, ChooseRandomSide());
  else
    CharacterMove(dragon, ChooseRandomSide());
}

void CharactersLogic::UpdateDragon(Dragon *dragon) {}

void CharactersLogic::MoveZombie(Zombie *zombie) {
  if (KnightIsClose(zombie))
    CharacterMove(zombie, BFS(zombie->GetPos()));
  else
    CharacterMove(zombie, ChooseRandomSide());
}

void CharactersLogic::UpdateZombie(Zombie *zombie) {}

void CharactersLogic::UpdatePrincess(Princess *princess) {
  if (princess->GetPos() == _game._knight->GetPos())
    _game._gameIsWin = true;
}

void CharactersLogic::MovePrincess(Princess *princess) {}

void CharactersLogic::MoveBullet(Bullet *bullet) {
  CharacterMove(bullet, bullet->GetSide());
  //CharacterMove(bullet, Point(0, 0));
}

void CharactersLogic::UpdateBullet(Bullet *bullet) {}