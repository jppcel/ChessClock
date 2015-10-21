// Program : Chess Clock
// Author : Joao Paulo Polles - http://github.com/jppcel
// Thanks: Arduino e Cia

#define NULL -1
#define null -1

// Include the library LedControl
#include "LedControl.h"

// Defines the pin and number of modules on the clock.
LedControl lc=LedControl(7,6,5,1);

void setup() 
{
  // Initializes the module
  lc.shutdown(0,false);
  // Adjust the display brightness
  lc.setIntensity(0,2);
  // Clear the display
  lc.clearDisplay(0);

  Serial.begin(9600);
}

/*void setWord(char Word[9], char Point[9], int num){

  
  int dig = 0;
  int local = 7;
  int Max = 7;
  int dp;
  int count = 0;
  char digit;

  
  for(int i = Max; i >= 0; i--){
    digit = Word[i];

    if(Point[i] == '.'){
      dp = 1;
    }else{
      dp = 0;
    }
       
    if(count >= num){
      dp=1;
    }
    count++;
  
    byte seg7;
    if(digit != -1 || count < num){
      switch(digit){
        case 'A':
        case 'a':
          if(dp == 1){ seg7 = B11110111; } else { seg7 = B01110111; }
          break;
        case 'B':
        case 'b':
          if(dp == 1){ seg7 = B10011111; } else { seg7 = B00011111; }
          break;
        case 'C':
        case 'c':
          if(dp == 1){ seg7 = B11001110; } else { seg7 = B01001110; }
          break;
        case 'D':
        case 'd':
          if(dp == 1){ seg7 = B10111101; } else { seg7 = B00111101; }
          break;
        case 'E':
        case 'e':
          if(dp == 1){ seg7 = B11001111; } else { seg7 = B01001111; }
          break;
        case 'F':
        case 'f':
          if(dp == 1){ seg7 = B11000111; } else { seg7 = B01000111; }
          break;
        case 'G':
        case 'g':
        case '6':
          if(dp == 1){ seg7 = B11011111; } else { seg7 = B01011111; }
          break;
        case 'H':
        case 'h':
          if(dp == 1){ seg7 = B10110111; } else { seg7 = B00110111; }
          break;
        case 'I':
        case 'i':
          if(dp == 1){ seg7 = B10010000; } else { seg7 = B00010000; }
          break;
        case 'J':
        case 'j':
          if(dp == 1){ seg7 = B10111000; } else { seg7 = B00111000; }
          break;
        case 'L':
        case 'l':
          if(dp == 1){ seg7 = B10001110; } else { seg7 = B00001110; }
          break;
      }
    }else{
      seg7 = B00000000;
    }
  
    /*byte dis = seg7;
          
    if(dp == '.'){
      lc.setRow(0,local,concatByte('B1',seg7));
    }else{
      lc.setRow(0,local,concatByte('B0',seg7));
    }
  
  
  
    lc.setRow(0, dig, seg7);
    Serial.println(dig+" - "+digit);
  }
  local--;
  dig++;
  count++;
}*/

void setDig(char Word[8], char Point[8], int num){

  
  int dig = 0;
  int local = 7;
  int Max = 7;
  int dp;
  int count = 0;
  char digit;

  
  for(int i = Max; i >= 0; i--){
    digit = Word[i];

    if(Point[i] == '.'){
      dp = 1;
    }else{
      dp = 0;
    }

    if(digit == '0'){
      if(dp == 1){ lc.setRow(0, dig, B11111110); } else { lc.setRow(0, dig, B01111110); }
    }
    if(digit == '1'){
      if(dp == 1){ lc.setRow(0, dig, B10110000); } else { lc.setRow(0, dig, B00110000); }
    }
    if(digit == '2'){
      if(dp == 1){ lc.setRow(0, dig, B11101101); } else { lc.setRow(0, dig, B01101101); }
    }
    if(digit == '3'){
      if(dp == 1){ lc.setRow(0, dig, B11111001); } else { lc.setRow(0, dig, B01111001); }
    }
    if(digit == '4'){
      if(dp == 1){ lc.setRow(0, dig, B10110011); } else { lc.setRow(0, dig, B00110011); }
    }
    if(digit == '5'){
      if(dp == 1){ lc.setRow(0, dig, B11011011); } else { lc.setRow(0, dig, B01011011); }
    }
    if(digit == '6'){
      if(dp == 1){ lc.setRow(0, dig, B11011111); } else { lc.setRow(0, dig, B01011111); }
    }
    if(digit == '7'){
      if(dp == 1){ lc.setRow(0, dig, B11110000); } else { lc.setRow(0, dig, B01110000); }
    }
    if(digit == '8'){
      if(dp == 1){ lc.setRow(0, dig, B11111111); } else { lc.setRow(0, dig, B01111111); }
    }
    if(digit == '9'){
      if(dp == 1){ lc.setRow(0, dig, B11111011); } else { lc.setRow(0, dig, B01111011); }
    }
  
    local--;
    dig++;
    count++;
  }
}

int trying = true;
void loop(){
  while(trying){
    setDig("03000300", "0.000.00", 8);
    trying = false;
  }

}

