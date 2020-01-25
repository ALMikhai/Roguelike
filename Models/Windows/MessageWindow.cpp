#include <ncurses.h>
#include "MessageWindow.h"

void MessageWindow::ShowMessageWindow(const std::string &message) {
  initscr();
  noecho();

  WINDOW *mainMenu = newwin(15, 30, 1, 1);
  keypad(mainMenu, true);

  auto input = 0;

  do {
    clear();
    box(mainMenu, 0, 0);
    refresh();
    wrefresh(mainMenu);
    mvwprintw(mainMenu, 3, 3, message.c_str());
    mvwprintw(mainMenu, 5, 3, "Press Enter to continue.");
    input = getch();
  } while (input != 10); // Enter.

  endwin();
}