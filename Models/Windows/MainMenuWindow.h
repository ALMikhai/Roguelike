#pragma once

#include <ncurses.h>
#include <string>
#include "../Game.h"


class MainMenu {
 public:
  static void ShowStartMenu() {
    initscr();
    noecho();

    std::string choices[2] = {"New game", "Exit"};
    int highlight = 0;
    int choice = 0;

    WINDOW *mainMenu = newwin(15, 30, 1, 1);

    keypad(mainMenu, true);

    while (true) {
      clear();
      box(mainMenu, 0, 0);
      refresh();
      wrefresh(mainMenu);

      for (int i = 0; i < 2; ++i) {
        if (i == highlight)
          wattron(mainMenu, A_REVERSE);
        mvwprintw(mainMenu, i + 3, 3, choices[i].c_str());
        wattroff(mainMenu, A_REVERSE);
      }
      curs_set(0);
      choice = wgetch(mainMenu);

      switch (choice) {
        case KEY_UP:
          highlight--;
          highlight = (highlight < 0) ? 1 : highlight;
          break;
        case KEY_DOWN:
          highlight++;
          highlight %= 2;
          break;
        case 10: // Enter
          if (highlight == 0)
            Game().StartNewGame();
          break;
        default:
          break;
      }

      if (choice == 10 && highlight == 1)
        break;
    }

    endwin();
  }
};