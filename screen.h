#include <ncurses.h>

class Screen{
private:
  int height;
  int width;

public:
  Screen(){
    initscr();
    noecho();
    nodelay(stdscr, true);
    curs_set(0);
    height = getmaxy(stdscr)/2;
    width = getmaxx(stdscr)/2;

    linha_superior();
    linha_inferior();
    linha_esquerda();
    linha_direita();
  }

    void linha_superior();
    void linha_inferior();
    void linha_esquerda();
    void linha_direita();

  ~Screen(){
    nodelay(stdscr, false);
    getch();
    endwin();
  }

};
