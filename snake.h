#include <ncurses.h>
#include <vector>

class Snake{
private:
  int pos_x;
  int pos_y;
  char snake_draw;
  int default_size;
public:
  Snake(){
    pos_x = getmaxx(stdscr)/4;
    pos_y = getmaxy(stdscr)/4;
    snake_draw = 'o';
    default_size = 5;

    for(int i=0;i<default_size;i++){
      print_snake(pos_y, pos_x+i);
    }

  }

  void print_snake(int col, int row);

  ~Snake(){

  }
};
