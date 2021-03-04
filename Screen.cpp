#include "screen.h"

void Screen::linha_superior(){
  for(int i=0; i<width;i++){
    move(0,i);
    if(i==0 || i==(width-1))addch('+');
    else addch('-');
  }
}

void Screen::linha_inferior(){
  for(int i=0; i<width;i++){
    move(height,i);
    if(i==0 || i==(width-1))addch('+');
    else addch('-');
  }
}

void Screen::linha_esquerda(){
  for(int i=1; i<height;i++){
    move(i,0);
    addch('|');
  }
}

void Screen::linha_direita(){
  for(int i=1; i<height;i++){
    move(i,width-1);
    addch('|');
  }
}
