#include "screen.h"
#include "snake.h"
#include "food.h"
#include <vector>
#include <ncurses.h>
#include <unistd.h>

int main(){

  initscr();
  noecho(); //não mostrar letras na tela
  curs_set(0); //não mostrar cursor na tela
  nodelay(stdscr, true); //não parar em getch()
  keypad(stdscr,true);
  const int delay = 100000;
  char snake_direction = 'L';

  Screen screen;
  std::vector <Snake> snake;
  Food food;

  //Inicializa snake no meio da tela
  for(int i=0;i<5;i++){
    snake.push_back(Snake(getmaxx(stdscr)/4+i, getmaxy(stdscr)/4));
  }

  while(true){
    switch (getch()) {
      case KEY_LEFT:
        if(snake_direction != 'R')
         snake_direction = 'L';
      break;
      case KEY_RIGHT:
        if(snake_direction != 'L')
         snake_direction = 'R';
      break;
      case KEY_DOWN:
        if(snake_direction != 'U')
         snake_direction = 'D';
      break;
      case KEY_UP:
        if(snake_direction != 'D')
         snake_direction = 'U';
      break;
    }

    //apaga da tela e deleta o ultimo corpo
    move( snake[ snake.size() - 1 ].get_snake_posy(), snake[ snake.size() - 1 ].get_snake_posx() );
    printw(" ");
    refresh();
    snake.pop_back();


    if(snake_direction=='L') snake.insert(snake.begin(),Snake(snake[0].get_snake_posx()-1, snake[0].get_snake_posy()));
    if(snake_direction=='R') snake.insert(snake.begin(),Snake(snake[0].get_snake_posx()+1, snake[0].get_snake_posy()));
    if(snake_direction=='U') snake.insert(snake.begin(),Snake(snake[0].get_snake_posx(), snake[0].get_snake_posy()-1));
    if(snake_direction=='D') snake.insert(snake.begin(),Snake(snake[0].get_snake_posx(), snake[0].get_snake_posy()+1));




    usleep(delay);
  }

  endwin();
  return 0;
}
