#include <map>
#include <vector>
#include <string>
#include <memory>
#include <ncurses.h>
#include <cstdlib>
#include <unistd.h>
#include "Characters/Character.h"
#include "Characters/Wall.h"
#include "Characters/Floor.h"
#include "Characters/Knight.h"
#include "Characters/Princess.h"
#include "Characters/Zombie.h"
#include "Map.h"

#define mapHeight 50
#define mapWidth 150
#define numEnemies 3
#define HpSpacing 2
#define TimeToNextTurn 1000

enum TurnResult { BAD, NEXT, WIN, LOSE };

static std::map<const size_t, const Point> Sides = {
    std::make_pair(KEY_UP, Point(0, -1)),
    std::make_pair(KEY_DOWN, Point(0, 1)),
    std::make_pair(KEY_LEFT, Point(-1, 0)),
    std::make_pair(KEY_RIGHT, Point(1, 0)),
};

class Game {
  using CharacterType = std::unique_ptr<Character>;

 public:
  Game() : _map(mapWidth, mapHeight), _chars() {
    CreatChars();
  }

  void Start() {
    srand(time(nullptr)); // TODO сид от времени.

    initscr();
    noecho();
    keypad(stdscr, TRUE);

    while (true) {
      clear();
      _map.Draw(); // Draw.
      CharsDraw(); //
      DrawHpBar(); //
      curs_set(0);
      refresh();

      TurnResult turnResult = BAD;
      timeout(TimeToNextTurn); // Time to wait action from player.
      size_t input = getch();
      auto side = Sides.find(input);
      if (side != Sides.end())
        turnResult = CharacterMove(*_knight, side->second);

      if (turnResult == WIN) {
        Win();
      }

      if (turnResult == LOSE) {
        // TODO lose.
      }

      if (input == 27)
        break;

      for (auto& enemy : _chars) {
        CharacterUpdate(*enemy);
      }
    }

    endwin();
  }

 private:
  Map _map;
  std::vector<CharacterType> _chars;
  CharacterType _knight;

  TurnResult CharacterMove(Character& character, const Point& side) {
    Point newPos = character.GetPos() + side;

    if (!_map.CheckCellForStep(newPos))
      return BAD;

    auto checkPos = findChar(newPos);

    if (checkPos.first)
      return BAD; // TODO Do damage.

    character.GetPos() = newPos;
    return NEXT;
  }

  void Win() { // TODO переделать.
    clear();
    _map = Map(mapWidth, mapHeight);
  }

  void CharacterUpdate (Character& character) { // TODO придумать способ прокидывать чара, а здесь уже понимать что это за чар.
    TurnResult result = BAD;
    while (result == BAD) {
      result = CharacterMove(character, ChooseRandomSide());
    }
  } // zombie, dragon, ...

  void CharsDraw() const {
    mvaddch(_knight->GetPos().Y, _knight->GetPos().X, _knight->GetSym());

    for (const auto& item : _chars) {
      mvaddch(item->GetPos().Y, item->GetPos().X, item->GetSym());
    }
  }

  void CreatChars() {
    Point knightPos = findFreePosition();
    _knight = CharacterType (new Knight(knightPos));

    Point princessPos = findFreePosition();
    _chars.push_back(CharacterType (new Princess(princessPos)));

    for (int i = 0; i < numEnemies; ++i) {
      Point enemyPos = findFreePosition();
      _chars.push_back(CharacterType (new Zombie(enemyPos)));
    }
  }

  Point findFreePosition() {
    Point result(0, 0);

    do {
      result.X = rand() % mapWidth;
      result.Y = rand() % mapHeight;
    } while (!findChar(result).first && !_map.CheckCellForStep(result));

    return result;
  }

  std::pair<bool, Character> findChar (Point& pos) {
    for (auto& item : _chars) {
      if (item->GetPos() == pos) {
        return std::make_pair(true, *item);
      }
    }

    return std::make_pair(false, Floor(Point(0, 0)));
  }

  void DrawHpBar() const {
    mvaddch(mapHeight + HpSpacing, 0, 'H');
    mvaddch(mapHeight + HpSpacing, 1, 'P');
    size_t hp = _knight->GetHp();
    for (size_t i = 0; i < hp; ++i) {
      mvaddch(mapHeight + HpSpacing, 2 + i, '-');
    }
  }

  static const Point& ChooseRandomSide () {
    return Sides[(rand() % 4 + KEY_DOWN)];
  }
};
