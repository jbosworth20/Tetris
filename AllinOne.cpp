
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "Tetromino.h"
  int shape_number;
  bool is_dead = false;
  char board[10][20];
  int x1 = 0;int y1 = 0;
  int x2 = 0;int y2 = 0;
  int x3 = 0;int y3 = 0;
  int x4 = 0;int y4 = 0;
  int get_shape_number(){
    return shape_number;
  }
  void set_point1(int x,int y){
    x1 = x;
    y1 = y;
  }
  void set_point2(int x,int y){
    x2 = x;
    y2 = y;
  }
  void set_point3(int x,int y){
    x3 = x;
    y3 = y;
  }
  void set_point4(int x,int y){
    x4 = x;
    y4 = y;
  }
  int get_x1(){
    return x1;
  }
  int get_y1(){
    return y1;
  }
  int get_x2(){
    return x2;
  }
  int get_y2(){
    return y2;
  }
  int get_x3(){
    return x3;
  }
  int get_y3(){
    return y3;
  }
  int get_x4(){
    return x4;
  }
  int get_y4(){
    return y4;
  }
  void determine_start_position(){
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
  void plotCurrentShape(){
    board[get_x1()][get_y1()] = 'x';
    board[get_x2()][get_y2()] = 'x';
    board[get_x3()][get_y3()] = 'x';
    board[get_x4()][get_y4()] = 'x';
  }
  void eraseCurrentShape(){
    board[get_x1()][get_y1()] = 'o';
    board[get_x2()][get_y2()] = 'o';
    board[get_x3()][get_y3()] = 'o';
    board[get_x4()][get_y4()] = 'o';
  }
  void rotate(){
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
  void fall(){
  while((board[get_x1()][get_y1()+1] != 'x')&&(board[get_x2()][get_y2()+1] != 'x')&&(board[get_x3()][get_y3()+1] != 'x')&&(board[get_x4()][get_y4()+1] != 'x')){
    //TODO Make some sort of timer so it falls slower
    eraseCurrentShape();
    set_point1(get_x1(),get_y1()+1);set_point2(get_x2(),get_y2()+1);set_point3(get_x3(),get_y3()+1);set_point4(get_x4(),get_y4()+1);
    plotCurrentShape();
  }
  is_dead = true;
}
#include <iostream>
#include <stdlib.h>
#include<vector>
#include "Game.h"
  std::vector<Tetromino> tetrominos;
  Tetromino currentTet;

  char board[10][20] = {{'o'}};
  int score = 0;
  void Game::print_board(){
    std::cout << "Score : "<< score << std::endl;
    std::cout << "Next Tetronome:" << std::endl;
    make_new_tetronome();
    Tetromino nextTet = tetrominos.at(1);
    nextTet.determine_start_position();
    int current_shape = nextTet.get_shape_number();
    switch (current_shape){
      case 1:
        std::cout << "xxxx" << std::endl;
        break;
      case 2:
        std::cout << "x" << std::endl;
        std::cout << "xxx" << std::endl;
        break;
      case 3:
        std::cout << "  x" << std::endl;
        std::cout << "xxx" << std::endl;
        break;
      case 4:
        std::cout << "xx" << std::endl;
        std::cout << "xx" << std::endl;
        break;
      case 5:
        std::cout << "xx" << std::endl;
        std::cout << " xx" << std::endl;
        break;
      case 6:
        std::cout << " x " << std::endl;
        std::cout << "xxx" << std::endl;
        break;
      case 7:
        std::cout << " xx" << std::endl;
        std::cout << "xx" << std::endl;
        break;
      default:
        break;
        std::cout << "_________" << std::endl;
      }
    for(int x = 0;x < 20;x++){
      for(int y = 0;y < 10;y++){
        std::cout << board[x][y] << std::endl;
      }
    }
  }
  void Game::make_new_tetronome(){
    for(int i = 0;i<1000000;i++){
        Tetromino* new_one = new Tetromino;
        tetrominos.push_back(*new_one);
    }
  }
  void Game::get_first_tetris(){
    currentTet = tetrominos.front();
    currentTet.determine_start_position();
    currentTet.plotCurrentShape();
  }
  void Game::get_next_tetris(){
    if(currentTet.is_dead == true){
      tetrominos.erase(tetrominos.begin());
      get_first_tetris();
    }
  }
  bool Game::is_game_over(){
    if(board[currentTet.get_x1()][currentTet.get_y1()+1] = 'x'){
      return true;
    }else{
      return false;
    }
  }
  bool Game::line_is_full(int y){
    for(int x = 0;x < 10;x++){
      if(board[x][y] != 'x'){
        return false;
      }
    }
    return true;
  }
  void Game::deleteLine(){
    for(int y = 0;y < 20;y++){
      for(int x = 0;x < 10;x++){
        if(line_is_full(y)){
          while(y > 0){
            board[x][y] = board[x][y-1];
          }
        }
      }
    }
    score=+100;
  }
};

int main(){
  Tetromino a;
  a.determine_start_position();
  std::cout << a.get_shape_number() << std::endl;
  std::cout << "a point 1: " << "(" << a.get_x1() <<"," << a.get_y1()<<")"<<std::endl;
  std::cout << "a point 2: " << "(" << a.get_x2() <<"," << a.get_y2()<<")"<<std::endl;
  std::cout << "a point 3: " << "(" << a.get_x3() <<"," << a.get_y3()<<")"<<std::endl;
  std::cout << "a point 4: " << "(" << a.get_x4() <<"," << a.get_y4()<<")"<<std::endl;
  return 1;
}
