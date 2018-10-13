#include <iostream>
#include <stdlib.h>
#include<vector>
#include "Game.h"
#include "Tetromino.h"
  std::vector<Tetromino> tetrominos;
  Tetromino currentTet;
  Tetromino nextTet;
  char board[10][20] = {{'o'}};
  int score = 0;
  void Game::make_new_tetronomes(){
    for(int i = 0;i<1000000;i++){
        Tetromino* new_one = new Tetromino;
        tetrominos.push_back(*new_one);
    }
  }
  void Game::get_first_tetris(){
    currentTet = tetrominos.front();
    //currentTet.determine_start_position();
    //currentTet.plotCurrentShape();
  }
  void Game::get_next_tetris(){
    if(currentTet.is_dead == true){
      tetrominos.erase(tetrominos.begin());
      get_first_tetris();
    }
  }
  void Game::print_board(){
    std::cout << "Score : "<< score << std::endl;
    std::cout << "Next Tetronome:" << std::endl;
    make_new_tetronomes();
    nextTet = tetrominos.at(1);
    //nextTet.determine_start_position();
    int current_shape = 1;//nextTet.get_shape_number();
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
  bool Game::is_game_over(){
    if(/*board[currentTet.get_x1()][currentTet.get_y1()+1] = 'x'*/ 1 == 1){
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
