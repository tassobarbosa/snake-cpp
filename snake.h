#include <ncurses.h>
#include <vector>

class Snake{
private:
  int pos_x;
  int pos_y;
  char snake_draw;

public:
  Snake(int s_col, int s_row){
    pos_x = s_col;
    pos_y = s_row;
    snake_draw = 'o';

    set_position(pos_y, pos_x);
  }

  void set_position(int col, int row){
    pos_x = row;
    pos_y = col;
    move(pos_y, pos_x);
    addch(snake_draw);
    refresh();
  }

  int get_snake_posx(){
    return pos_x;
  }

  int get_snake_posy(){
    return pos_y;
  }

  ~Snake(){

  }
};
