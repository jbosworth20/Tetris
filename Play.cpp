#include <iostream>
#include <stdlib.h>
#include<vector>
#include "Tetromino.h"
#include "Game.h"
int main(){
  Tetromino a;
  a.determine_start_position();
  //std::cout << a.get_shape_number() << std::endl;
  //int x1 = a.get_x1();
  //int y1 =  a.get_y1();
  //std::cout << "a point 1: " << "(" << x1 << "," << y1 << ")" << std::endl;
  /*std::cout << "a point 2: " << "(" << a.get_x2() << "," << a.get_y2() << ")" << std::endl;
  std::cout << "a point 3: " << "(" << a.get_x3() << "," << a.get_y3() << ")" << std::endl;
  std::cout << "a point 4: " << "(" << a.get_x4() << "," << a.get_y4() << ")" << std::endl;
  std::cout << "DROP IT" << std::endl;
   a.fall();
    std::cout << "a point 1: " << "(" << a.get_x1() <<"," << a.get_y1()<<")"<<std::endl;
  std::cout << "a point 2: " << "(" << a.get_x2() <<"," << a.get_y2()<<")"<<std::endl;
  std::cout << "a point 3: " << "(" << a.get_x3() <<"," << a.get_y3()<<")"<<std::endl;
  std::cout << "a point 4: " << "(" << a.get_x4() <<"," << a.get_y4()<<")"<<std::endl;
  std::cout<< "ROTATE IT" << std::endl;
    a.rotate();
    std::cout << "a point 1: " << "(" << a.get_x1() <<"," << a.get_y1()<<")"<<std::endl;
  std::cout << "a point 2: " << "(" << a.get_x2() <<"," << a.get_y2()<<")"<<std::endl;
  std::cout << "a point 3: " << "(" << a.get_x3() <<"," << a.get_y3()<<")"<<std::endl;
  std::cout << "a point 4: " << "(" << a.get_x4() <<"," << a.get_y4()<<")"<<std::endl;*/
  /*Game::make_new_tetronome();
  while(is_game_over == false()){
    get_first_tetris();
    while(currentTet.is_dead == false){
      currentTet.fall();
      if(/*buttons < >  are pressed){
        //currentTet.rotate();
      //}else if(/* v button is pressed
        //fall faster
      /*}
      for(int y = 0;y < 20;y++){
        if(line_is_full(y)){
          deleteLine();
        }
      }
    }
    get_next_tetris();
  }*/
  return 1;
}
