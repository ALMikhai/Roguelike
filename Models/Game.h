#pragma once

#include <map>
#include <vector>
#include <string>
#include <memory>
#include <ncursesw/ncurses.h>
#include <cstdlib>
#include <unistd.h>
#include <locale>
#include <chrono>

#include "Settings/Settings.h"
#include "Map.h"
#include "CharacterFactory.h"
#include "CharactersLogic.h"
#include "Windows/MessageWindow.h"
#include "Windows/PauseMenuWindow.h"

class Game {
  using CharacterType = CharacterFactory::CharacterType;
  friend CharactersLogic;
  friend PauseMenu;

 public:
  Game() : _map(), _chars(), _playerIsAlive(true), _gameIsWin(false), _charactersLogic(*this) {
    SpawnChars();
    _map.SetFocuse(_knight->GetPos());
  }

  void StartNewGame() {
    srand(time(nullptr));
    initscr();
    noecho();
    keypad(stdscr, TRUE);

    time_t MoveTime = time(nullptr);
    auto ShootTime = std::chrono::system_clock::now();

    while (_playerIsAlive && !_gameIsWin) {
      clear();
      _map.Draw(); // Draw.
      CharsDraw(); //
      DrawHpBar(); //
      curs_set(0);
      refresh();

      for (auto item = _chars.begin(); item != _chars.end();) { // Update chars.
        if (item->get()->IsDead()) {
          item = _chars.erase(item);
          continue;
        }
        _charactersLogic.Update(*item);
        if (item->get()->IsDead()) {
          item = _chars.erase(item);
          continue;
        }
        ++item;
      }

      for (auto item = _bullets.begin(); item != _bullets.end();) { // Update bullets.
        if (item->get()->IsDead()) {
          item = _bullets.erase(item);
          continue;
        }
        ++item;
      }

      if (((std::chrono::system_clock::now().time_since_epoch() / 1000000) - (ShootTime.time_since_epoch() / 1000000)).count() >= 1000 / Settings::settingsData["bulletSpeed"].GetInt()) { // Move bullets.
        ShootTime = std::chrono::system_clock::now();

        for (auto item = _bullets.begin(); item != _bullets.end(); ++item) {
          _charactersLogic.Move(*item);
        }
      }

      if (time(nullptr) - MoveTime >= Settings::settingsData["timeToNextTurn"].GetInt()) { // Move chars.
        MoveTime = time(nullptr);

        for (auto item = _chars.begin(); item != _chars.end(); ++item) {
          _charactersLogic.Move(*item);
        }
      }

      _charactersLogic.WaitAction(_knight);
      _charactersLogic.Update(_knight);

      _map.SetFocuse(_knight->GetPos());
    }

    if (!_playerIsAlive) {
      MessageWindow::ShowMessageWindow("You died.");
    }

    if (_gameIsWin) {
      MessageWindow::ShowMessageWindow("You win.");
    }

    endwin();
  }

 private:
  Map _map;
  std::vector<CharacterType> _chars;
  std::vector<CharacterType> _bullets;
  CharacterType _knight;
  bool _playerIsAlive;
  bool _gameIsWin;
  CharactersLogic _charactersLogic;

  void CharsDraw() const {
    for (const auto& item : _bullets) {
      _map.Draw(item);
    }

    _map.Draw(_knight);

    for (const auto& item : _chars) {
      _map.Draw(item);
    }
  }

  void SpawnChars() {
    _knight = CharacterFactory::Create(Characters::KNIGHT, FindFreePosition());
    _chars.push_back(CharacterFactory::Create(Characters::PRINCESS, FindFreePosition()));

    int32_t numEnemies = Settings::settingsData["numEnemies"].GetInt();
    int32_t numAids = Settings::settingsData["NumAids"].GetInt();

    for (int i = 0; i < numEnemies; ++i)
      _chars.push_back(CharacterFactory::Create(Characters::ZOMBIE, FindFreePosition()));

    for (int i = 0; i < numEnemies; ++i)
      _chars.push_back(CharacterFactory::Create(Characters::DRAGON, FindFreePosition()));

    for (int i = 0; i < numAids; ++i) {
      _chars.push_back(CharacterFactory::Create(Characters::AID, FindFreePosition()));
    }
  }

  Point FindFreePosition() {
    Point result(0, 0);

    do {
      result.X = rand() % _map.Height;
      result.Y = rand() % _map.Height;
    } while (!IsCharacterOnThisPos(result) && !_map.CheckCellForStep(result));

    return result;
  }

  bool IsCharacterOnThisPos (Point& pos) {
    for (auto& item : _chars) {
      if (item->GetPos() == pos) {
        return true;
      }
    }

    return false;
  }

  void DrawHpBar() const {
    int32_t hpSpacing = Settings::settingsData["HpSpacing"].GetInt();

    mvaddch((_map.HalfWindowHeight * 2) + hpSpacing, 0, 'H');
    mvaddch((_map.HalfWindowHeight * 2) + hpSpacing, 1, 'P');
    size_t hp = _knight->GetHp();
    for (size_t i = 0; i < hp; ++i) {
      mvaddch((_map.HalfWindowHeight * 2) + hpSpacing, 2 + i, '-');
    }
  }
};