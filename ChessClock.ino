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

  
  pinMode(9, INPUT);//  +
  pinMode(10, INPUT);// -
  pinMode(11, INPUT);// ok
  pinMode(12, INPUT);// return
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

char ToShow[2][4];
char Toshow[8];
void setDig(char Word[8], char Point[8], int num){


  
  int dig = 0;
  int local = 7;
  int Max = 7;
  int dp;
  int count = 0;
  char digit;

  if(Word == "*ToShow*"){
    //sprintf(Word, "%s%s", ToShow[0], ToShow[1]); 
    Word = Toshow;
  }
  Serial.println(ToShow[0]);

  
  for(int i = Max; i >= 0; i--){
    digit = Word[i];

    if(Point[i] == '.'){
      dp = 1;
    }else{
      dp = 0;
    }
    if(Point[i] != '*'){
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
      if(digit == '9'){
        if(dp == 1){ lc.setRow(0, dig, B11111011); } else { lc.setRow(0, dig, B01111011); }
      }
      if(Point[i] == ','){
        lc.setRow(0, dig, B10000000);
      }
    }else{
        lc.setRow(0, dig, B00000000);
    }
  
    local--;
    dig++;
    count++;
  }
}

  int trying = true;



  int a1 = 1;
  int a2 = 1;
  int btn = 0;
  int count = 0;
  char tempString[10] = "1-SA"; //Used for sprintf
  int et2 = 0;
  int et3 = 0;

  int btn1 = 9;
  int btn2 = 10;
  int btn3 = 11;
  int btn4 = 12;

  int numStep = 1;
  int programSeconds = 0;
  int programAdd = 0;
  int programAddSeconds = 0;
  boolean Step1 = true;
  boolean Step2 = false;
  boolean Step3 = false;


  boolean Introduction = true;

void returnStep(){
  if(numStep == 3){
    Step1 = false;
    Step2 = true;
    Step3 = false;
    numStep = 2;
  }else{
    if(numStep == 2){
      Step1 = true;
      Step2 = false;
      Step3 = false;
      numStep = 1;
      btn = 1;
    }
  }
}

int toSeconds(int hours, int minutes, int seconds){
  int total = seconds;
  total = total + (minutes*60);
  total = total + (hours*60*60);
  return total;
}


void toShow(int seconds1, int seconds2){
    int hours, secHours, minutes, Seconds;
    unsigned char seconds[2];
    seconds[0] = seconds1;
    seconds[1] = seconds2;
  for(int i=0; i<2; i++){
    hours = (int)(seconds[i]/60)/60;
    secHours = hours*60*60;
    minutes = (int)(seconds1-(secHours))/60;
    Seconds = seconds[i] - secHours - (minutes*60);
    if(hours > 0){
      if(hours >= 10){
        if(minutes >= 10){
          sprintf(ToShow[i], "%d%d", hours, minutes);
        }else{
          if(minutes == 0){
            sprintf(ToShow[i], "%d%d%d", hours, 0, 0);
          }else{
            sprintf(ToShow[i], "%d%d%d", hours, 0, minutes);
          }
        }
      }else{
        if(minutes >= 10){
          sprintf(ToShow[i], "%d%d%d", 0, hours, minutes);
        }else{
          if(minutes == 0){
            sprintf(ToShow[i], "%d%d%d%d", 0, hours, 0, 0);
          }else{
            sprintf(ToShow[i], "%d%d%d%d", 0, hours, 0, minutes);
          }
        }
      }
    }else{
      if(minutes >= 10){
        if(Seconds >= 10){
          sprintf(ToShow[i], "%d%d", minutes, Seconds);
        }else{
          sprintf(ToShow[i], "%d%d%d", minutes, 0, Seconds);
        }
      }else{
        if(Seconds >= 10){
          sprintf(ToShow[i], "%d%d%d", 0, minutes, Seconds);
        }else{
          if(Seconds == 0){
            sprintf(ToShow[i], "%d%d%d%d", 0,  minutes, 0, 0);
          }else{
            sprintf(ToShow[i], "%d%d%d%d", 0,  minutes, 0, Seconds);
          }
        }
      }
    }
    sprintf(Toshow, "%s%s", ToShow[0], ToShow[1]);
  }
}

void setPers(){
  //code
}


void introduction(){
  if(Introduction){
    lc.setRow(0, 7, B00000001);
    delay(100);
    lc.setRow(0, 6, B10000001);
    lc.setRow(0, 7, B10000001);
    delay(100);
    lc.setRow(0, 5, B00000001);
    lc.setRow(0, 6, B00000001);
    lc.setRow(0, 7, B00000001);
    delay(100);
    lc.setRow(0, 4, B10000001);
    lc.setRow(0, 5, B10000001);
    lc.setRow(0, 6, B10000001);
    lc.setRow(0, 7, B10000001);
    delay(100);
    lc.setRow(0, 3, B00000001);
    lc.setRow(0, 4, B00000001);
    lc.setRow(0, 5, B00000001);
    lc.setRow(0, 6, B00000001);
    lc.setRow(0, 7, B00000001);
    delay(100);
    lc.setRow(0, 2, B10000001);
    lc.setRow(0, 3, B10000001);
    lc.setRow(0, 4, B10000001);
    lc.setRow(0, 5, B10000001);
    lc.setRow(0, 6, B10000001);
    lc.setRow(0, 7, B10000001);
    delay(100);
    lc.setRow(0, 1, B00000001);
    lc.setRow(0, 2, B00000001);
    lc.setRow(0, 3, B00000001);
    lc.setRow(0, 4, B00000001);
    lc.setRow(0, 5, B00000001);
    lc.setRow(0, 6, B00000001);
    lc.setRow(0, 7, B00000001);
    delay(100);
    lc.setRow(0, 0, B10000001);
    lc.setRow(0, 1, B10000001);
    lc.setRow(0, 2, B10000001);
    lc.setRow(0, 3, B10000001);
    lc.setRow(0, 4, B10000001);
    lc.setRow(0, 5, B10000001);
    lc.setRow(0, 6, B10000001);
    lc.setRow(0, 7, B10000001);
    delay(300);
    lc.setRow(0, 0, B00000000);
    lc.setRow(0, 1, B00000000);
    lc.setRow(0, 2, B00000000);
    lc.setRow(0, 3, B00000000);
    lc.setRow(0, 4, B00000000);
    lc.setRow(0, 5, B00000000);
    lc.setRow(0, 6, B00000000);
    lc.setRow(0, 7, B00000000);
    Introduction = false;
  }
}


void step1(){
  while(Step1){
    while(trying){
      setDig("0001", "***00000", 8);
      trying = false;
    }
    if(btn == 0){
      if(digitalRead(btn1) == 1){
        if(a1 < 2){ a1++; }
        btn = 1;
      }
      if(digitalRead(btn2) == 1){
        if(a1 > 1){ a1--; }
        btn = 1;
      }
      if(digitalRead(btn3) == 1){
        Step1 = false;
        Step2 = true;
        trying = true;
        btn = 0;
        a2 = 1;
        numStep = 2; setDig("0002", "***0,,,,", 8);
      }
    }else{
      switch(a1){
        case 1:
          setDig("0001", "***0****", 8);
          break;
        case 2:
          setDig("0002", "***0,,,,", 8);
          break;
      }
      delay(100);
      btn = 0;
    }
  }
}



void step2(){
  while(Step2){
    if(a1 == 1){
      while(trying){
        setDig("00030000", "0.00....", 8);
        trying = false;
        delay(400);
        setDig("00030000", "0.000000", 8);
        programSeconds = toSeconds(0,3,0);
        programAdd = 0;
        programAddSeconds = 0;
      }
      
      if(btn == 0){
        if(digitalRead(btn1) == 1){
          if(a2 < 8){ 
            a2++;
          }
          btn = 1;
        }
        if(digitalRead(btn2) == 1){
          if(a2 > 1){ 
            a2--;
          }
          btn = 1;
        }
        
        if(digitalRead(btn3) == 1){
          if(a2 == 8){
            setPers();
            Step2 = false;
            Step3 = true;
            trying = true;
            btn = 0;
            numStep = 3;
          }else{
            Step2 = false;
            Step3 = true;
            trying = true;
            btn = 0;
            numStep = 3;
          }
        }
        if(btn == 1){
            
          switch(a2){
            case 1:  
              setDig("00030000", "0.000000", 8);
              programSeconds = toSeconds(0,3,0);
              programAdd = 0;
              programAddSeconds = 0;
              break;
            case 2:  
              setDig("00050000", "0.000000", 8);
              programSeconds = toSeconds(0,5,0);
              programAdd = 0;
              programAddSeconds = 0;
              break;
            case 3:  
              setDig("00100000", "0.000000", 8);
              programSeconds = toSeconds(0,10,0);
              programAdd = 0;
              programAddSeconds = 0;
              break;
            case 4:  
              setDig("00150000", "0.000000", 8);
              programSeconds = toSeconds(0,15,0);
              programAdd = 0;
              programAddSeconds = 0;
              break;
            case 5:  
              setDig("00200000", "0.000000", 8); 
              programSeconds = toSeconds(0,20,0);
              programAdd = 0;
              programAddSeconds = 0;
              break;
            case 6:  
              setDig("01300000", "0.000000", 8);
              programSeconds = toSeconds(1,30,0);
              programAdd = 0;
              programAddSeconds = 0;
              break;
            case 7:  
              setDig("02000000", "0.000000", 8);
              programSeconds = toSeconds(2,0,0);
              programAdd = 0;
              programAddSeconds = 0;
              break;
            case 8:  
              setCar(B01100111,B01001111,B00000101,B11011011,B00000000,B00000000,B00000000,B00000000);
              break;
          }
        }
      }else{
        delay(200);
        btn = 0;
      }
    }else{
      while(trying){
        setDig("00030002", "0.00....", 8);
        trying = false;
        delay(400);
        setDig("00030002", "0.000.00", 8);
        programSeconds = toSeconds(0,3,0);
        programAdd = 1;
        programAddSeconds = 2;
      }
      
      if(btn == 0){
        if(digitalRead(btn1) == 1){
          if(a2 < 8){ 
            a2++;
          }
          btn = 1;
        }
        if(digitalRead(btn2) == 1){
          if(a2 > 1){ 
            a2--;
          }
          btn = 1;
        }
        
        if(digitalRead(btn3) == 1){
          if(a2 == 4){
            setPers();
            Step2 = false;
            Step3 = true;
            trying = true;
            btn = 0;
            numStep = 3;
          }else{
            Step2 = false;
            Step3 = true;
            trying = true;
            btn = 0;
            numStep = 3;
          }
        }
        if(btn == 1){
            
          switch(a2){
            case 1:  
              setDig("00030002", "0.000.00", 8);
              programSeconds = toSeconds(0,3,0);
              programAdd = 1;
              programAddSeconds = 2;
              break;
            case 2:  
              setDig("00150005", "0.000.00", 8);
              programSeconds = toSeconds(0,15,0);
              programAdd = 1;
              programAddSeconds = 5;
              break;
            case 3:  
              setDig("01300030", "0.000.00", 8);
              programSeconds = toSeconds(1,30,0);
              programAdd = 1;
              programAddSeconds = 30;
              break;
            case 4:  
              setCar(B01100111,B01001111,B00000101,B11011011,B00000000,B00000000,B00000000,B00000000);
              break;
          }
        }
      }else{
        delay(200);
        btn = 0;
      }
    
    }
    
    if(digitalRead(btn4) == 1){
      returnStep();
    }
  }
}

    int time1 = programSeconds;
    int time2 = programSeconds;
    
void step3(){
  while(Step3){
    while(trying){
      time1 = programSeconds;
      time2 = programSeconds;
      trying = false;
    }
    if(a1 == 1){
      step3_sA();
    }else{
      step3_cA();
    }
  }
}

void step3_sA(){
  toShow(time1,time2);
  setDig("*ToShow*", "0.000.00", 8);
}

void step3_cA(){
  toShow(time1,time2);
  setDig("*ToShow*", "0.000.00", 8);
}

  
void loop(){



//execute the introduction

    introduction();

//execute the first step - select the first menu

    step1();

//execute the second step - select the time of game

    step2();
    
//execute the third step - the time

    step3();










/*

if(et2 == 0){// Etapa 1
    if(btn == 0){
      if(digitalRead(btn1) == 1){
       if(a1 < 2){ a1++;  setDig("0002", "***0....", 8); }
       btn = 1;
       count=20;
      }
      if(digitalRead(btn2) == 1){
       if(a1 >1){ a1--; setDig("0001", "***00000", 8); }
       btn = 1;
       count = 20;
      }
    }
    
    //sprintf(tempString, "00%02d", a1);
    //strcat(tempString,a1);
    //display7seg.DisplayString(tempString, 3);
    if(count > 0){
     count--; 
    }else{
       if(count == 0 && btn == 1){
         btn = 0;
       } 
    }
    if(digitalRead(32) ==1){
       et2 = 1; 
       btn = 0;
       count = 0;
       if(a1 == 1){sprintf(tempString, "%s", "0003");}else{sprintf(tempString, "%s", "0003");}
       //display7seg.DisplayString(tempString, 3);
    }
  }else{ // Fim etapa 1
    if(et3 == 0){// Etapa 2
      if(a1 == 1){
          
        if(btn == 0){
          if(digitalRead(30) == 1){
           if(a2 < 8){ 
             a2++;
             switch(a2){
                case 1:  
                  sprintf(tempString, "%s", "0003"); 
                  break;
                case 2:  
                  sprintf(tempString, "%s", "0005"); 
                  break;
                case 3:  
                  sprintf(tempString, "%s", "0010"); 
                  break;
                case 4:  
                  sprintf(tempString, "%s", "0015"); 
                  break;
                case 5:  
                  sprintf(tempString, "%s", "0020"); 
                  break;
                case 6:  
                  sprintf(tempString, "%s", "0130"); 
                  break;
                case 7:  
                  sprintf(tempString, "%s", "0200"); 
                  break;
                case 8:  
                  sprintf(tempString, "%s", "PERS"); 
                  break;
             }
           }
           btn = 1;
           count=20;
          }
          if(digitalRead(31) == 1){
           if(a2 > 1){ 
          
             a2--;
             switch(a2){
                case 1:  
                  sprintf(tempString, "%s", "0003"); 
                  break;
                case 2:  
                  sprintf(tempString, "%s", "0005"); 
                  break;
                case 3:  
                  sprintf(tempString, "%s", "0010"); 
                  break;
                case 4:  
                  sprintf(tempString, "%s", "0015"); 
                  break;
                case 5:  
                  sprintf(tempString, "%s", "0020"); 
                  break;
                case 6:  
                  sprintf(tempString, "%s", "0130"); 
                  break;
                case 7:  
                  sprintf(tempString, "%s", "0200"); 
                  break;
                case 8:  
                  sprintf(tempString, "%s", "PERS"); 
                  break;
             }
           }
           btn = 1;
           count = 20;
          }
        }
        
        //sprintf(tempString, "00%02d", a1);
        //strcat(tempString,a1);
        //display7seg.DisplayString(tempString, 3);
        if(count > 0){
         count--; 
        }else{
           if(count == 0 && btn == 1){
             btn = 0;
           } 
        }
      }else{
          
        if(btn == 0){
          if(digitalRead(30) == 1){
           if(a2 < 8){ 
             a2++;
             switch(a2){
                case 1:  
                  sprintf(tempString, "%s", "0003"); 
                  break;
                case 2:  
                  sprintf(tempString, "%s", "0015"); 
                  break;
                case 3:  
                  sprintf(tempString, "%s", "0130"); 
                  break;
                case 4:  
                  sprintf(tempString, "%s", "PERS"); 
                  break;
             }
           }
           btn = 1;
           count=20;
          }
          if(digitalRead(31) == 1){
           if(a2 > 1){ 
          
             a2--;
             switch(a2){
                case 1:  
                  sprintf(tempString, "%s", "0003"); 
                  break;
                case 2:  
                  sprintf(tempString, "%s", "0015"); 
                  break;
                case 3:  
                  sprintf(tempString, "%s", "0130"); 
                  break;
                case 4:  
                  sprintf(tempString, "%s", "PERS"); 
                  break;
             }
           }
           btn = 1;
           count = 20;
          }
        }
        
        //sprintf(tempString, "00%02d", a1);
        //strcat(tempString,a1);
        //display7seg.DisplayString(tempString, 3);
        if(count > 0){
         count--; 
        }else{
           if(count == 0 && btn == 1){
             btn = 0;
           } 
        }
      }
      if(digitalRead(32) == 1){
         et3 = 1; 
         btn = 0;
         count = 0;
      }
    }else{// fim etapa 3
        strcat(tempString,"Cert");
        //display7seg.DisplayString(tempString, 3);
    }
  }*/































  

}

