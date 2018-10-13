#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include "Tetromino.h"
  int shape_number;
  bool is_dead = false;
  char board[10][20];
  int x1 = 0;int y1 = 0;
  int x2 = 0;int y2 = 0;
  int x3 = 0;int y3 = 0;
  int x4 = 0;int y4 = 0;
  void Tetromino::set_point1(int x,int y){
    x1 = x;
    y1 = y;
  }
  void Tetromino::set_point2(int x,int y){
    x2 = x;
    y2 = y;
  }
  void Tetromino::set_point3(int x,int y){
    x3 = x;
    y3 = y;
  }
  void Tetromino::set_point4(int x,int y){
    x4 = x;
    y4 = y;
  }
  int Tetromino::get_x1(){
    return x1;
  }
  int Tetromino::get_y1(){
    return y1;
  }
  int Tetromino::get_x2(){
    return x2;
  }
  int Tetromino::get_y2(){
    return y2;
  }
  int Tetromino::get_x3(){
    return x3;
  }
  int Tetromino::get_y3(){
    return y3;
  }
  int Tetromino::get_x4(){
    return x4;
  }
  int Tetromino::get_y4(){
    return y4;
  }
  void Tetromino::determine_start_position(){
    srand(time(NULL));
    shape_number = (rand()%7)+1;
    switch(get_shape_number()){
    case 1: //I-block
      set_point1(4,0);
      set_point2(4,1);
      set_point3(4,2);
      set_point4(4,3);
      break;
    case 2: //J-block
      set_point1(4,0);
      set_point2(4,1);
      set_point3(5,1);
      set_point4(6,1);
      break;
    case 3://L-block
      set_point1(6,0);
      set_point2(4,1);
      set_point3(5,1);
      set_point4(6,1);
      break;
    case 4://O-block
      set_point1(4,0);
      set_point2(5,0);
      set_point3(4,1);
      set_point4(5,1);
      break;
    case 5://S-block
      set_point1(4,0);
      set_point2(5,0);
      set_point3(5,1);
      set_point4(6,1);
      break;
    case 6: //T-shape
      set_point1(5,0);
      set_point2(4,1);
      set_point3(5,1);
      set_point4(6,1);
      break;
    case 7://Z-shape
      set_point1(4,0);
      set_point2(5,0);
      set_point3(3,1);
      set_point4(4,1);
      break;
    default:
      break;
    }
  }
  int Tetromino::get_shape_number(){
    return shape_number;
  }
  void Tetromino::plotCurrentShape(){
    board[get_x1()][get_y1()] = 'x';
    board[get_x2()][get_y2()] = 'x';
    board[get_x3()][get_y3()] = 'x';
    board[get_x4()][get_y4()] = 'x';
  }
  void Tetromino::eraseCurrentShape(){
    board[get_x1()][get_y1()] = 'o';
    board[get_x2()][get_y2()] = 'o';
    board[get_x3()][get_y3()] = 'o';
    board[get_x4()][get_y4()] = 'o';
  }
  void Tetromino::rotate(){
  eraseCurrentShape();
  if(get_shape_number() == 1){
    if(get_y1() < get_y2()){
      set_point1(get_y4(),get_y4());
      set_point2(get_y3(),get_y4());
      set_point3(get_y2(),get_y4());
      set_point4(get_y1(),get_y4());
    }else{
      set_point1(get_y4(),get_x4());
      set_point2(get_y4(),get_x3());
      set_point3(get_y4(),get_x2());
      set_point4(get_y4(),get_x1());
    }
  }else if(get_shape_number() == 2){
    if(get_y1() < get_y2()){
      set_point1(get_x1()+1,get_y1()-1);
      set_point2(get_x1(),get_y2()-2);
      set_point3(get_x3()-1,get_y3()-1);
      set_point4(get_x4()+2,get_y4());
    }else if(get_x1() > get_x2()){
      set_point1(get_x1()+1,get_y1()+2);
      set_point2(get_x2()+2,get_y2()-1);
      set_point3(get_x3()+1,get_y3());
      set_point4(get_x4(),get_y4()-1);
    }else if(get_y1() > get_y2()){
      set_point1(get_x1()-1,get_y2());
      set_point2(get_x2(),get_y2()+1);
      set_point3(get_x3()+1,get_y3());
      set_point4(get_x4()+2,get_y4()-1);
    }else{
      set_point1(get_x1()-1,get_y1()-1);
      set_point2(get_x2()-2,get_y2());
      set_point3(get_x3()-1,get_y3()+1);
      set_point4(get_x4(),get_y4()+2);
    }
  }else if(get_shape_number() == 3){
    if(get_x1() > get_x4()){
      set_point1(get_x1()+1,get_y1()-1);
      set_point2(get_x2(),get_y2()+2);
      set_point3(get_x3()+1,get_y3()+1);
      set_point4(get_x4()+2,get_y4());
    }else if(get_y1() < get_y4()){
      set_point1(get_x1()-1,get_y1()-1);
      set_point2(get_x2()+2,get_y2());
      set_point3(get_x3()+1,get_y3()-1);
      set_point4(get_x3(),get_y4()-2);
    }else if(get_x1() < get_x4()){
      set_point1(get_x1()-1,get_y1()+2);
      set_point2(get_x2(),get_y2()-1);
      set_point3(get_x3()-1,get_y3());
      set_point4(get_x4()-2,get_y4()+1);
    }else{
      set_point1(get_x1()+1,get_y1());
      set_point2(get_x2()-2,get_y2()-1);
      set_point3(get_x3()-1,get_y3());
      set_point4(get_x4(),get_y4()+1);
    }
  }else if(get_shape_number() == 5){
    if(get_x1() < get_x2()){
      set_point2(get_x2()+1,get_y2()-1);
      set_point3(get_x3()-1,get_y3()-1);
      set_point4(get_x4()-2,get_y4());
    }else{
      set_point2(get_x2()-1,get_y2()-1);
      set_point3(get_x3()+1,get_y3()+1);
      set_point4(get_x4()+2,get_y4());
    }
  }else if(get_shape_number() == 6){
    if(get_y1() < get_y3()){
      set_point2(get_x2(),get_y2()-2);
      set_point3(get_x3()-1,get_y3()-1);
      set_point4(get_x4()-2,get_y4());
    }else if(get_x1() > get_x3()){
      set_point2(get_x2()+2,get_y2());
      set_point3(get_x3()+1,get_y3()-1);
      set_point4(get_y4(),get_y4()-2);
    }else if(get_y1() > get_y3()){
      set_point2(get_x2(),get_y2()+2);
      set_point3(get_x3()+1,get_x3()+1);
      set_point4(get_x4()+2,get_y4());
    }else{
      set_point2(get_x2()-2,get_y2());
      set_point3(get_x3()-1,get_y3()+1);
      set_point4(get_x4(),get_y4()+2);
    }
  }else if(get_shape_number() == 7){
    if(get_x1() < get_x2()){
      set_point2(get_x2()-1,get_y2()+1);
      set_point3(get_x3()+2,get_y3());
      set_point4(get_x4()+1,get_y4()-1);
    }else{
      set_point2(get_x2()+1,get_y2()-1);
      set_point3(get_x3()-2,get_y3());
      set_point4(get_x4()-1,get_y4()+1);
    }
}
    plotCurrentShape();
}
void Tetromino::fall(){
  while((board[get_x1()][get_y1()+1] != 'x')&&(board[get_x2()][get_y2()+1] != 'x')&&(board[get_x3()][get_y3()+1] != 'x')&&(board[get_x4()][get_y4()+1] != 'x')){
    //TODO Make some sort of timer so it falls slower
    eraseCurrentShape();
    set_point1(get_x1(),get_y1()+1);set_point2(get_x2(),get_y2()+1);set_point3(get_x3(),get_y3()+1);set_point4(get_x4(),get_y4()+1);
    plotCurrentShape();
  }
  is_dead = true;
}
int main(){
  std::cout << "It works!" << std::endl;
  return 1;
}
