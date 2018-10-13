#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

class Tetromino{
public:
  bool is_dead;
  char board[10][20];
  int shape_number;
  int x1;int y1;
  int x2;int y2;
  int x3;int y3;
  int x4;int y4;
  void set_point1(int x, int y);
  void set_point2(int x, int y);
  void set_point3(int x, int y);
  void set_point4(int x, int y);
  int get_x1(); int get_y1();
  int get_x2(); int get_y2();
  int get_x3(); int get_y3();
  int get_x4(); int get_y4();
  void determine_start_position();
  int get_shape_number();
  void plotCurrentShape();
  void eraseCurrentShape();
  void rotate();
  void fall();
};
