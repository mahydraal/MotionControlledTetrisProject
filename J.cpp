#include "Sprite.h"
using namespace std; 


class J : public Sprite{
  public:
  J() : Sprite(){
    CurrentPositionX  = 3;
    CurrentPositionY = 7;
    Pixel[0][0] = 0 ;
    Pixel[0][1] = 1;
    Pixel[1][0] = 1;
    Pixel[1][1] = 1;
    Pixel[2][0] = 2;
    Pixel[2][1] = 1;
  }  
  
  boolean Rotate(){
  
  }

};

