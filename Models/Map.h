#pragma once

#include <ncursesw/ncurses.h>
#include "Characters/Wall.h"
#include "Characters/Floor.h"
#include "CharacterFactory.h"
#include "Settings/Settings.h"

#define r1_cutoff 5
#define r2_cutoff 2
#define generateIterations 4
#define extraGenerateIterations 3
#define randPercent 40

class Map {
  using mapType = std::vector<std::vector<std::unique_ptr<Character>>>;
  using mapElement = std::unique_ptr<Character>;

 public:
  const int32_t Width;
  const int32_t Height;
  const int32_t HalfWindowWidth;
  const int32_t HalfWindowHeight;

  Map() : Width(Settings::settingsData["mapWidth"].GetInt()), Height(Settings::settingsData["mapHeight"].GetInt()),
  HalfWindowWidth(Settings::settingsData["halfWindowWidth"].GetInt()), HalfWindowHeight(Settings::settingsData["halfWindowHeight"].GetInt()),
  _data(Height), _dataTmp(Height), _mapFocuse(Point(0, 0)), _floorSym(Settings::settingsData["FloorSym"].GetString()[0]){


    srand(time(nullptr));

    for (int32_t  i = 0; i < Height; ++i) {
      for (int32_t j = 0; j < Width; ++j) {
        if(i == 0 || j == 0 || i == Height - 1 || j == Width - 1)
          _data[i].push_back(CharacterFactory::Create(Characters::WALL, Point(j, i)));
        else
          if (randpick())
            _data[i].push_back(CharacterFactory::Create(Characters::WALL, Point(j, i)));
          else
            _data[i].push_back(CharacterFactory::Create(Characters::FLOOR, Point(j, i)));
        _dataTmp[i].push_back(CharacterFactory::Create(Characters::WALL, Point(j, i)));
      }
    }

    for (int i = 0; i < generateIterations; ++i) {
      generationLevel(true);
    }
    for (int i = 0; i < extraGenerateIterations; ++i) {
      generationLevel(false);
    }
  }

  void Draw() const {
    Point vector(_mapFocuse.X - HalfWindowWidth, _mapFocuse.Y - HalfWindowHeight);
    for (int i = _mapFocuse.Y - HalfWindowHeight; i < _mapFocuse.Y + HalfWindowHeight; ++i) {
      for (int j = _mapFocuse.X - HalfWindowWidth; j < _mapFocuse.X + HalfWindowWidth; ++j) {
        if (i < 0 || j < 0 || i >= Height || j >= Width)
          continue;
        if (!_data[i][j]->IsDrawable()) {
          mvaddch(i - vector.Y, j - vector.X, _data[i][j]->GetSym());
        }
        else {
          attron(COLOR_PAIR(1));
          mvaddch(i - vector.Y, j - vector.X, _data[i][j]->GetSym());
          attroff(COLOR_PAIR(1));
        }
      }
    }
  }

  void Draw(const mapElement& character) const {
    Point pos = character->GetPos();
    if (WindowContain(pos)) {
      Point vector(_mapFocuse.X - HalfWindowWidth, _mapFocuse.Y - HalfWindowHeight);

      if (!character->IsDrawable()){
        mvaddch(pos.Y - vector.Y, pos.X - vector.X, character->GetSym());
        return;
      }

      start_color();
      init_pair(1, COLOR_GREEN, COLOR_BLACK);
      attron(COLOR_PAIR(1));
      mvaddch(pos.Y - vector.Y, pos.X - vector.X, character->GetSym());
      attroff(COLOR_PAIR(1));
    }
  }

  bool WindowContain(Point point) const {
    return  (
        point.X > _mapFocuse.X - HalfWindowWidth &&
        point.X < _mapFocuse.X + HalfWindowWidth &&
        point.Y > _mapFocuse.Y - HalfWindowHeight &&
        point.Y < _mapFocuse.Y + HalfWindowHeight
        );
  }

  void SetFocuse(Point& point) {
    _mapFocuse = point;
  }

  bool CheckCellForStep (Point& pos) {
    return  _data[pos.Y][pos.X]->GetSym() == _floorSym;
  }

  Character* GetCell(Point& pos) {
    return (_data[pos.Y][pos.X]).get();
  }

 private:
  mapType _data;
  mapType _dataTmp;
  Point _mapFocuse;
  char _floorSym;

  void generationLevel(bool useSecondProperty) { // Cellular Automata Method for Generating Random Cave-Like Levels.
    for (int32_t y = 1; y < Height - 1; ++y) {
      for (int32_t x = 1; x < Width - 1; ++x) {
        int32_t floors = 0;
        int32_t walls = 0;

        for (int32_t I = -1; I <= 1; ++I) {
          for (int32_t J = -1; J <= 1; ++J) {
            if (_data[y + I][x + J]->GetSym() != _floorSym) {
              floors++;
            }
          }
        }

        for (int32_t I = y - 2; I <= y + 2; ++I) {
          for (int32_t J = x - 2; J <= x + 2; ++J) {
            if (abs(I - y) == 2 && abs(J - x) == 2)
              continue;
            if (J < 0 || I < 0 || I >= Height || J >= Width)
              continue;
            if (_data[I][J]->GetSym() != _floorSym)
              walls++;
          }
        }

        if (floors >= r1_cutoff || (useSecondProperty && walls <= r2_cutoff))
          _dataTmp[y][x] = CharacterFactory::Create(Characters::WALL, Point(x, y));
        else
          _dataTmp[y][x] = CharacterFactory::Create(Characters::FLOOR, Point(x, y));
      }
    }

    for (int32_t y = 1; y < Height - 1; ++y) {
      for (int32_t x = 1; x < Width - 1; ++x) {
        _data[y][x].swap(_dataTmp[y][x]);
      }
    }
  }

  bool randpick() {
    return rand() % 100 < randPercent;
  }
};
