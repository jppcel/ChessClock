// Program : Chess Clock
// Author : Joao Paulo Polles - http://github.com/jppcel
// Thanks: Arduino e Cia

#define NULL 0
#define null 0

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

void setCaracter(int local, char digit[1], char *dp[1]){
     int seg7;
     switch(digit[1]){
       case 'A':
       case 'a':
       seg7 = 0010000;
        break;
       
     } 
     if(*dp == "."){
        lc.setRow(0,local,B1+(byte)seg7);
     }else{
        lc.setRow(0,local,B0+(byte)seg7);
     }
}

void setCar(byte dig7, byte dig6, byte dig5, byte dig4, byte dig3, byte dig2, byte dig1, byte dig0){
  if(dig7 != null){
    lc.setRow(0,7,dig7);
  }
  if(dig6 != null){
    lc.setRow(0,6,dig6);
  }
  if(dig5 != null){
    lc.setRow(0,5,dig5);
  }
  if(dig4 != null){
    lc.setRow(0,4,dig4);
  }
  if(dig3 != null){
    lc.setRow(0,3,dig3);
  }
  if(dig2 != null){
    lc.setRow(0,2,dig2);
  }
  if(dig1 != null){
    lc.setRow(0,1,dig1);
  }
  if(dig0 != null){
    lc.setRow(0,0,dig0);
  }
}

byte concatByte(char init, int digit){
  byte returnByte = init+digit;
  return returnByte;
}

void serialWord(char Word[8]){
  Serial.print(Word[0]);
  Serial.print(Word[1]);
  Serial.print(Word[2]);
  Serial.print(Word[3]);
  Serial.print(Word[4]);
  Serial.print(Word[5]);
  Serial.print(Word[6]);
  Serial.print(Word[7]);
}

void setWord(char Word[8]){
  int dig = 0;
  int local = 7;
  int Max = 7;
  char digit;
  char dp;

  
  for(int i = Max; i >= 0; i--){

    
   digit = Word[i];
   dp = Word[i-1];
   if((int)digit >= 0 && (int)digit <= 9){
    // Set the number
    if(Word[i-1] ==  '.'){
      lc.setDigit(0,dig,(byte)digit,true);
      i--;
    }else{
      lc.setDigit(0,dig,(byte)digit,false);
    }
   }else{


      /*char seg7[8];
     switch(digit){
       case 'A':
       case 'a':
        seg7 = "0010000";
        break;
       case 'B':
       case 'b':
        seg7 = "0011111";
        break;
       case 'C':
       case 'c':
        seg7 = "1001110";
        break;
       case 'D':
       case 'd':
        seg7 = "0111101";
        break;
       case 'E':
       case 'e':
        seg7 = "1001111";
        break;
       case 'F':
       case 'f':
        seg7 = "1000111";
        break;
       case 'G':
       case 'g':
       case '6':
        seg7 = "1011111";
        break;
       case 'H':
       case 'h':
        seg7 = "0110111";
        break;
     } */

     /*byte dis = seg7;
        
     if(dp == '.'){
       lc.setRow(0,local,concatByte('B1',seg7));
     }else{
       lc.setRow(0,local,concatByte('B0',seg7));
     }*/



     lc.setChar(0, dig, digit, false);
     Serial.println(local);

    
   }
   local--; 
   dig++;
  }
}

int trying = true;
void loop(){
  while(trying){
    //setCar(B00111000,B01100111,B01100111,B01001110,B01001111,B00001110,null,null);
    //lc.setRow(0,7,B1110000);
    //lc.setChar(0,7,'a',false);
    //setWord("1111");
    /*lc.setDigit(0,0,1,false);
    lc.setDigit(0,1,2,false);
    lc.setDigit(0,2,3,true);
    lc.setDigit(0,3,4,false);
    lc.setDigit(0,4,5,false);
    lc.setDigit(0,5,6,false);
    lc.setDigit(0,6,7,true);
    lc.setDigit(0,7,8,false);*/
    setWord("arduino1");
    trying = false;
  }

}

