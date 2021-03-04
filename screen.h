#include <ncurses.h>

class Screen{
private:
  int height;
  int width;

public:

  Screen(){
    initscr();
    noecho();
    curs_set(0);
    height = getmaxx(stdscr)/2;
    width = getmaxy(stdscr)/2;
  }

  ~Screen(){
    nodelay(stdscr, false);
    getch();
    endwin();
  }

};
