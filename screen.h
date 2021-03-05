#include <ncurses.h>

class Screen{
private:
  int height;
  int width;

public:
  Screen(){
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

    void cria_tela(){
      linha_superior();
      linha_inferior();
      linha_esquerda();
      linha_direita();
    }

    int get_screen_top(){
      return 0;
    }

    int get_screen_bottom(){
      return height;
    }

    int get_screen_left(){
      return 0;
    }

    int get_screen_right(){
      return width-1;
    }

  ~Screen(){
  }

};
