#include "PauseMenuWindow.h"

#include "../Game.h"
#include <ncurses.h>

void PauseMenu::ShowPauseMenu(Game &game) {
  initscr();
  noecho();

  std::string choices[2] = {"Continue", "Exit"};
  int highlight = 0;
  int choice = 0;

  WINDOW *mainMenu = newwin(15, 30, 1, 1);
  box(mainMenu, 0, 0);
  refresh();
  wrefresh(mainMenu);

  keypad(mainMenu, true);

  while (true) {
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
      default:break;
    }

    if (choice == 10) {
      switch (highlight) {
        case 1 :
          game._playerIsAlive = false;
          break;
        default:
          break;
      }
      break;
    }
  }

  endwin();
}