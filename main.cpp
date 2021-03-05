#include "screen.h"
#include "snake.h"
#include "food.h"
#include <vector>
#include <ncurses.h>
#include <unistd.h>

void game_over(char *snake_direction){
  *snake_direction = 'q';
  clear();
  Screen screen2;
  int height = getmaxy(stdscr)/6;
  int width = getmaxx(stdscr)/6;
  move(height,width);
  printw("GAME OVER");
}

void print_score(int *score){
  move(getmaxy(stdscr)/2+1,1);
  printw("Score: ");
  printw("%d",*score);
}

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
  int score = 0;
  print_score(&score);

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
      case 'q':
         snake_direction = 'q';
      break;
    }

    //apaga da tela e deleta o ultimo corpo
    if(snake_direction!='q'){
      move( snake[ snake.size() - 1 ].get_snake_posy(), snake[ snake.size() - 1 ].get_snake_posx() );
      printw(" ");
      refresh();
      snake.pop_back();
    }


    //direciona a snake inserindo sempre na primeira posicao do vector
    if(snake_direction=='L') snake.insert(snake.begin(),Snake(snake[0].get_snake_posx()-1, snake[0].get_snake_posy()));
    if(snake_direction=='R') snake.insert(snake.begin(),Snake(snake[0].get_snake_posx()+1, snake[0].get_snake_posy()));
    if(snake_direction=='U') snake.insert(snake.begin(),Snake(snake[0].get_snake_posx(), snake[0].get_snake_posy()-1));
    if(snake_direction=='D') snake.insert(snake.begin(),Snake(snake[0].get_snake_posx(), snake[0].get_snake_posy()+1));

    //colisao parede
    if(snake[0].get_snake_posy() == screen.get_screen_top()) game_over(&snake_direction);
    if(snake[0].get_snake_posy() == screen.get_screen_bottom()) game_over(&snake_direction);
    if(snake[0].get_snake_posx() == screen.get_screen_left()) game_over(&snake_direction);
    if(snake[0].get_snake_posx() == screen.get_screen_right()) game_over(&snake_direction);

    //colisao com comida
    if(snake[0].get_snake_posx()==food.get_food_posx() && snake[0].get_snake_posy()==food.get_food_posy()){
      food.print_food();
      score+=10;
      print_score(&score);
    }



    usleep(delay);
  }

  endwin();
  return 0;
}
