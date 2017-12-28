//SpriteObj.h is a library for defining new tetrominoe objects in the tetris game..
//Created By Michael Lynn, July 5th 2017.
//Public use allowed.

#include "Arduino.h"
#include "binary.h"
#include <inttypes.h>


class Sprite {
protected:
    int width;
    int height;
    byte CurrentPositionX;
    byte CurrentPositionY;
    char Pixel[3][2];
    

   
void init(int width, int height, int posX, int posY); 
public:



 Sprite(int width, int height, int posX, int posY);
 Sprite();
 Sprite(byte blockValue);
 boolean ShiftDown(byte Display[8][8]);
 //void Rotate();
 boolean Bump(byte Display[8][8] ,byte Posx, byte Posy);
 void Draw(byte Display[8][8]);
 void Undraw(byte Display[8][8]);
 boolean UpdateSprite(byte PosX, byte PosY, byte Display[8][8]);
 void Delete();
 boolean Rotate(byte Display[8][8]);
 void SideSlide(byte ShiftDirection, byte Display[8][8]);
 byte GetPositionY();
 boolean FAIL(byte Display[8][8]);
};

