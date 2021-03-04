#include "snake.h"

void Snake::print_snake(int col, int row){
    move(col, row);
    addch(snake_draw);
}
