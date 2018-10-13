#include <iostream>
#include <stdlib.h>
#include<vector>
class Game{
public:
  void print_board();
  void make_new_tetronomes();
  void get_first_tetris();
  void get_next_tetris();
  bool is_game_over();
  bool line_is_full(int y);
  void deleteLine();
};
