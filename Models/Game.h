#include <map>
#include <vector>
#include <string>
#include <memory>
#include <ncurses.h>
#include <cstdlib>
#include "Characters/Character.h"
#include "Characters/Wall.h"
#include "Characters/Floor.h"
#include "Characters/Knight.h"
#include "Characters/Princess.h"
#include "Map.h"

#define mapSize 40
#define numEnemies 0
#define HpSpacing 2

enum TurnResult { BAD, NEXT, WIN, LOSE };

static std::map<size_t, Point> Sides = {
    std::make_pair(KEY_UP, Point(0, -1)),
    std::make_pair(KEY_DOWN, Point(0, 1)),
    std::make_pair(KEY_LEFT, Point(-1, 0)),
    std::make_pair(KEY_RIGHT, Point(1, 0)),
};

class Game {
  using CharacterType = std::unique_ptr<Character>;

 public:
  Game() : _map(mapSize, mapSize), _chars() {
    CreatChars();
  }

  void Start() {
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
      size_t input = 0;

      while (turnResult == BAD && input != 27) { // Wait action.
        input = getch();
        auto side = Sides.find(input);
        if (side != Sides.end())
          turnResult = KnightMove(side->second);
      }

      if (turnResult == WIN) {
        Win();
      }

      if (turnResult == LOSE) {
        // TODO lose.
      }

      if (input == 27)
        break;
    }

    endwin();
  }

 private:
  Map _map;
  std::vector<CharacterType> _chars;
  CharacterType _knight;

  TurnResult KnightMove(const Point& side) {
    Point newPos = _knight->GetPos() + side;

    if (!_map.CheckCellForStep(newPos))
      return BAD;

    auto checkPos = findChar(newPos);

    if (checkPos.first)
      return BAD; // TODO Do damage.
      
    _knight->GetPos() = newPos;
    return NEXT;
  }

  void Win() { // TODO переделать.
    clear();
    _map = Map(mapSize, mapSize);
  }

  void CharUpdate () { } // zombie, dragon, ...

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
  }

  Point findFreePosition() {
    Point result(0, 0);

    do {
      result.X = rand() % mapSize;
      result.Y = rand() % mapSize;
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
    mvaddch(mapSize + HpSpacing, 0, 'H');
    mvaddch(mapSize + HpSpacing, 1, 'P');
    size_t hp = _knight->GetHp();
    for (size_t i = 0; i < hp; ++i) {
      mvaddch(mapSize + HpSpacing, 2 + i, '-');
    }
  }
};