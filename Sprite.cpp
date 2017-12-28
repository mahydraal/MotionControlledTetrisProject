//SpriteObj.cpp is a library for defining new tetrominoe objects in the tetris game..
//Created By Michael Lynn, July 5th 2017.
//Public use allowed.

#define PixelX 0
#define PixelY 1
#define Pixel0 0
#define Pixel1 1
#define Pixel2 2





#include "Arduino.h"
#include "Sprite.h"

using namespace std; 


Sprite::Sprite(int height, int width, int posX, int posY)
{
  //this.height = height;
  //this.width = width;
  
}
Sprite::Sprite(){
    CurrentPositionX  = 3;
    CurrentPositionY = 7;
    Pixel[0][0] = 0 ;
Pixel[0][1] = 1;
Pixel[1][0] = 1;
Pixel[1][1] = 1;
Pixel[2][0] = 2;
Pixel[2][1] = 1;

}
//Pixel array is defined as the set of pixels realtive to the home pixel.
//CurrentPosition variables are the position of the home pixel relative to the larger display array.
//Pixel0, Pixel1, Pixel2, are the other 3 pixels in the tetramino other than the home pixel.
//PixelX and PixelY are the x and y positions of those pixels relative to the home pixel.
//Thus, we have each line in the below cases defined as Pixel[zeroth pixel][x/y] = #, which means that for the current position of the home pixel, the number to the right
//of the equals is added to the current position x and y to find the x y position of the pixel of interest in the display.

//TLDR;current position x and y are home positions, pixel zero, pixel one and pixel two are in relation to current position by the value posted to the right of the equals sign.

Sprite::Sprite(byte blockValue){
  switch(blockValue){
    case 1:                            // I
      CurrentPositionX = 3;
      CurrentPositionY = 8;
      Pixel[Pixel0][PixelX] = -1;
      Pixel[Pixel0][PixelY] = 0;
      Pixel[Pixel1][PixelX] = 1;
      Pixel[Pixel1][PixelY] = 0;
      Pixel[Pixel2][PixelX] = 2;
      Pixel[Pixel2][PixelY] = 0;
   
      break;
    case 2:                            //L
      CurrentPositionX  = 3;
      CurrentPositionY = 6;
      Pixel[Pixel0][PixelX] = 0 ;
      Pixel[Pixel0][PixelY] = -1;
      Pixel[Pixel1][PixelX] = 1;
      Pixel[Pixel1][PixelY] = 0;
      Pixel[Pixel2][PixelX] = 2;
      Pixel[Pixel2][PixelY] = 0;
      break;
    case 3:                                  //O tetrominoe
      CurrentPositionX  = 3;
      CurrentPositionY = 6;
      Pixel[Pixel0][PixelX] = 1 ;
      Pixel[Pixel0][PixelY] = 1;
      Pixel[Pixel1][PixelX] = 1;
      Pixel[Pixel1][PixelY] = 0;
      Pixel[Pixel2][PixelX] = 0;
      Pixel[Pixel2][PixelY] = 1;
      break;
    case 4:                            //J, Jacob's tetramino
      CurrentPositionX  = 3;
      CurrentPositionY = 6;
      Pixel[Pixel0][PixelX] = 1 ;
      Pixel[Pixel0][PixelY] = 0;
      Pixel[Pixel1][PixelX] = 2;
      Pixel[Pixel1][PixelY] = 0;
      Pixel[Pixel2][PixelX] = 0;
      Pixel[Pixel2][PixelY] = 1;
      break;
    case 5:                          //S 
      CurrentPositionX  = 3;
      CurrentPositionY = 6;
      Pixel[Pixel0][PixelX] = -1;
      Pixel[Pixel0][PixelY] = 0;
      Pixel[Pixel1][PixelX] = 0;
      Pixel[Pixel1][PixelY] = 1;
      Pixel[Pixel2][PixelX] = 1;
      Pixel[Pixel2][PixelY] = 1;
      break;
    case 6:                          //T
      CurrentPositionX  = 3;
      CurrentPositionY = 7;
      Pixel[Pixel0][PixelX] = -1;
      Pixel[Pixel0][PixelY] = 0;
      Pixel[Pixel1][PixelX] = 1;
      Pixel[Pixel1][PixelY] = 0;
      Pixel[Pixel2][PixelX] = 0;
      Pixel[Pixel2][PixelY] = -1;
      break;
    default:                        //Z
      CurrentPositionX  = 3;
      CurrentPositionY = 6;
      Pixel[Pixel0][PixelX] = -1;
      Pixel[Pixel0][PixelY] = 0;
      Pixel[Pixel1][PixelX] = 0;
      Pixel[Pixel1][PixelY] = -1;
      Pixel[Pixel2][PixelX] = 1;
      Pixel[Pixel2][PixelY] = -1;
      break;
  }
}
boolean Sprite::ShiftDown(byte Display[8][8]){
   
  return UpdateSprite(CurrentPositionX, CurrentPositionY-1, Display);  
        
}

//void Rotate(){

//}
//the following detects collisions between sprites and facilitates the stopping of falling tetrominoes upon contact with the pile or the edges of the display.
boolean Sprite::Bump(byte Display[8][8], byte Posx, byte Posy){ 

  boolean bumped = false;//every tetrominoe is not bumped, until it contacts another tetrominoe, the pile or the base of the screen.
  
  //this loop handles when the tetrominoe might go out of bounds of the display.
  
  for(int i = 0; i<3; i++){
      if (Posx+Pixel[i][0] < 0 || Posy+Pixel[i][1] < 0 || Posx+Pixel[i][0] > 7 || Posy+Pixel[i][1] > 7){
        bumped = true;	                                                                                              //the tetrominoe bumped the edges of the display...	
      }      
  }
   if(Display[Posx][Posy] == 0){
       bumped = true;                                                                                                 //this bump event is triggered when a tetrominoe meets another LED that is on.
     }
  for(int i = 0; i<3; i++){
     if(Display[Posx+Pixel[i][0]][Posy+Pixel[i][1]] == 0){
       bumped = true;                                                                                                 //this event is triggered when the next position the tetrominoe is trying to occupy is already occupied.
     }
  }   
  return bumped;

}
void Sprite::Draw(byte Display[8][8]){
	Display[CurrentPositionX][CurrentPositionY]= 0;
	Display[CurrentPositionX+Pixel[0][0]][CurrentPositionY+Pixel[0][1]] = 0;
	Display[CurrentPositionX+Pixel[1][0]][CurrentPositionY+Pixel[1][1]] = 0;
	Display[CurrentPositionX+Pixel[2][0]][CurrentPositionY+Pixel[2][1]] = 0;

}
void Sprite::Undraw(byte Display[8][8]){
        Display[CurrentPositionX][CurrentPositionY] = 1;
        Display[CurrentPositionX+Pixel[0][0]][CurrentPositionY+Pixel[0][1]] = 1;
        Display[CurrentPositionX+Pixel[1][0]][CurrentPositionY+Pixel[1][1]] = 1;
	Display[CurrentPositionX+Pixel[2][0]][CurrentPositionY+Pixel[2][1]] = 1;

}
boolean Sprite::UpdateSprite(byte PosX, byte PosY, byte Display[8][8]){
  boolean updated = false;
  Undraw(Display);
  if(!Bump(Display, PosX, PosY)){

      CurrentPositionX = PosX;
      CurrentPositionY = PosY;

      updated = true;
  }
        Draw(Display);
  return updated;
}
void Sprite::Delete(){

}

boolean Sprite::Rotate( byte Display[8][8]){
 Undraw(Display);

    for(int i = 0; i<3; i++){                                                                      //Rotates when valid position is available
      char A = Pixel[i][0] * -1;
      Pixel[i][0] = Pixel[i][1];
      Pixel[i][1] = A;
    }
    
    if (Bump(Display, CurrentPositionX, CurrentPositionY)){
                                                                                                   //unrotate for invalid position
       for(int i = 0; i<3; i++){
      char A = Pixel[i][1] * -1;
      Pixel[i][1] = Pixel[i][0];
      Pixel[i][0] = A;
       }
     }
  Draw(Display);
}

  void Sprite::SideSlide(byte ShiftDirection, byte Display[8][8]){
   
   UpdateSprite(CurrentPositionX+ShiftDirection, CurrentPositionY, Display);
}


  byte Sprite::GetPositionY(){
  
     return CurrentPositionY;
}

  boolean Sprite::FAIL(byte Display[8][8]){
    return Bump(Display,CurrentPositionX,CurrentPositionY);
    }
