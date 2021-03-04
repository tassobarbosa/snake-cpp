#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>


class Food{
private:
  int pos_x;
  int pos_y;
  char food_draw;

public:
  Food(){
    srand(time(NULL));
    pos_x = rand() % getmaxx(stdscr)/3;
    pos_y = rand() % getmaxy(stdscr)/3;
    food_draw = 'X';

    print_food();
  }

  void print_food(){
    move(pos_y, pos_x);
    addch(food_draw);
    refresh();
  }

  int get_food_posx(){
    return pos_x;
  }

  int get_food_posy(){
    return pos_y;
  }

  ~Food(){

  }
};
