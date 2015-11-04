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
  lc.setIntensity(0,14);
  // Clear the display
  lc.clearDisplay(0);

  Serial.begin(9600);

  
  pinMode(9, INPUT);//  +
  pinMode(10, INPUT);// -
  pinMode(11, INPUT);// ok
  pinMode(12, INPUT);// return
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

  
  int btnNegras = 12;

  int numStep = 1;
  long programSeconds = 0;
  int programAdd = 0;
  int programAddSeconds = 0;
  boolean Step1 = true;
  boolean Step2 = false;
  boolean Step3 = false;

  int sideTime = -1;

  int setDelay = 97;
  char points;
  char Point[9];


  boolean Introduction = true;

  // Debug on Serial
  boolean Debug_toDisplayTime = false;
    boolean Debug_toDisplayTime_others = false;
  boolean Debug = false;

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

char ToShow[2][4];
int Toshow[8];
void setDig(char Word[8], char Point[8], int num){


  
  int dig = 0;
  int local = 7;
  int Max = 7;
  int dp;
  int count = 0;
  char digit;

  //Serial.println(Word);

  
  for(int i = Max; i >= 0; i--){
    
    /*if(Word == "*ToShow*"){
      int digit = Toshow[i];
    }else{*/
      char digit = Word[i];
    //}

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

void setNum(int num){


  
  int dig = 0;
  int local = 7;
  int Max = 7;
  int dp;
  int count = 0;
  int digit;

  /*for(int j = 0; j < 8; j++){
    if(j == 7){
      Serial.println(Toshow[j]);
    }else{
      Serial.print(Toshow[j]);
    }
  }*/
  
  for(int i = Max; i >= 0; i--){
    
    int digit = Toshow[i];

    if(Point[i] == '.'){
      dp = 1;
    }else{
      dp = 0;
    }
    if(Point[i] != '*'){
      if(digit == 0){
        if(dp == 1){ lc.setRow(0, dig, B11111110); } else { lc.setRow(0, dig, B01111110); }
      }
      if(digit == 1){
        if(dp == 1){ lc.setRow(0, dig, B10110000); } else { lc.setRow(0, dig, B00110000); }
      }
      if(digit == 2){
        if(dp == 1){ lc.setRow(0, dig, B11101101); } else { lc.setRow(0, dig, B01101101); }
      }
      if(digit == 3){
        if(dp == 1){ lc.setRow(0, dig, B11111001); } else { lc.setRow(0, dig, B01111001); }
      }
      if(digit == 4){
        if(dp == 1){ lc.setRow(0, dig, B10110011); } else { lc.setRow(0, dig, B00110011); }
      }
      if(digit == 5){
        if(dp == 1){ lc.setRow(0, dig, B11011011); } else { lc.setRow(0, dig, B01011011); }
      }
      if(digit == 6){
        if(dp == 1){ lc.setRow(0, dig, B11011111); } else { lc.setRow(0, dig, B01011111); }
      }
      if(digit == 7){
        if(dp == 1){ lc.setRow(0, dig, B11110000); } else { lc.setRow(0, dig, B01110000); }
      }
      if(digit == 8){
        if(dp == 1){ lc.setRow(0, dig, B11111111); } else { lc.setRow(0, dig, B01111111); }
      }
      if(digit == 9){
        if(dp == 1){ lc.setRow(0, dig, B11111011); } else { lc.setRow(0, dig, B01111011); }
      }
      if(digit == 9){
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

long toSeconds(int hours, int minutes, int seconds){
  long total = seconds;
  total = total + (minutes*60);
  total = total + (hours*60*60);
  return total;
}

long toMiliseconds(int hours, int minutes, int seconds){
  long total = seconds;
  Serial.println(total);
  total = total + (minutes*60);
  Serial.println(total);
  total = total + (hours*60*60);
  Serial.println(total);
  return total*10;
}


void toShow(int seconds1, int seconds2){
    int hours, secHours, minutes, Seconds;
    int H[2], SH[2], M[2], S[2];
    unsigned char seconds[2];
    seconds[0] = seconds1/10;
    seconds[1] = seconds2/10;

    
  for(int i=0; i<2; i++){
    hours = (int)(seconds[i]/60)/60;
    
    //Caracters on the arrays
    if(hours == 0){
      H[0] = 0;
      H[1] = 0;
    }else{
      if(hours >= 10){
        H[0] = (int) hours/10;
        H[1] = hours-H[0];
      }else{
      H[0] = 0;
      H[1] = hours;
      }
    }
    
    secHours = hours*60*60;
    minutes = (int)(seconds1-(secHours))/60;
    
    //Caracters on the arrays
    if(minutes == 0){
      M[0] = 0;
      M[1] = 0;
    }else{
      if(minutes >= 10){
        M[0] = (int) minutes/10;
        M[1] = minutes - M[0];
      }else{
        M[0] = 0;
        M[1] = minutes;
      }
    }
    
    Seconds = seconds[i] - secHours - (minutes*60);
    
    //Caracters on the arrays
    if(seconds == 0){
      S[0] = 0;
      S[1] = 0;
    }else{
      if(Seconds >= 10){
        S[0] = (int) Seconds/10;
        S[1] = Seconds - S[0];
      }else{
        S[0] = 0;
        S[1] = Seconds;
      }
    }

    
    int add;
    if(i == 0){
      add = 0;
    }else{
      add = 4;
    }

    if(H[1] >= 1){
      Toshow[0+add] = H[0];
      Toshow[1+add] = H[1];
      Toshow[2+add] = M[0];
      Toshow[3+add] = M[1];
    }else{
      Toshow[0+add] = M[0];
      Toshow[1+add] = M[1];
      Toshow[2+add] = S[0];
      Toshow[3+add] = S[1];
    }
    
    
  }
}




void toDisplayTime(long seconds1, long seconds2){
    long hours, secHours, minutes, Seconds, seconds[2];
    int H[2], SH[2], M[2], S[2];

    seconds[0] = seconds1/10;
      if(Debug_toDisplayTime_others){
        Serial.println(seconds1);
        Serial.println(seconds[0]);
        Serial.println("------");
      }
    seconds[1] = seconds2/10;
      if(Debug_toDisplayTime_others){
        Serial.println(seconds2);
        Serial.println(seconds[0]);
        Serial.println("------");
      }

    
  for(int i=0; i<2; i++){
    hours = (int)(seconds[i]/60)/60;
      if(Debug_toDisplayTime_others){
        Serial.println(seconds[i]);
        Serial.println(seconds[i]/60);
        Serial.println((seconds[i]/60)/60);
      }
    
    //Caracters on the arrays
    if(hours == 0){
      H[0] = 0;
      H[1] = 0;
      if(Debug_toDisplayTime_others){
        Serial.println("hours == 0");
      }
    }else{
      if(hours >= 10){
        H[0] = (int) hours/10;
        H[1] = hours-(H[0]*10);
        if(Debug_toDisplayTime_others){
          Serial.println("hours >= 0");
        } 
      }else{
        H[0] = 0;
        H[1] = hours;
        if(Debug_toDisplayTime_others){
          Serial.println("!(hours >= 10) && (hours != 0)");
        }
      }
    }
    
    secHours = hours*60*60;
    minutes = (int)(seconds[i]-secHours)/60;
    
    //Caracters on the arrays
    if(minutes == 0){
      M[0] = 0;
      M[1] = 0;
      if(Debug_toDisplayTime_others){
        Serial.println("minutes == 0");
      }
    }else{
      if(minutes >= 10){
        M[0] = (int) minutes/10;
        M[1] = minutes - (M[0]*10);
        if(Debug_toDisplayTime_others){
          Serial.println("minutes >= 0");
        } 
      }else{
        M[0] = 0;
        M[1] = minutes;
        if(Debug_toDisplayTime_others){
          Serial.println("!(minutes >= 10) && (minutes != 0)");
        }
      }
    }
    
    Seconds = seconds[i] - secHours - (minutes*60);
    
    //Caracters on the arrays
    if(seconds == 0){
      S[0] = 0;
      S[1] = 0;
      if(Debug_toDisplayTime_others){
        Serial.println("seconds == 0");
      }
    }else{
      if(Seconds >= 10){
        S[0] = (int) Seconds/10;
        S[1] = Seconds - (S[0]*10);
        if(Debug_toDisplayTime_others){
          Serial.println("seconds >= 0");
        } 
      }else{
        S[0] = 0;
        S[1] = Seconds;
        if(Debug_toDisplayTime_others){
          Serial.println("!(seconds >= 10) && (seconds != 0)");
        }
      }
    }

    
    int add;
    if(i == 0){
      add = 0;
    }else{
      add = 4;
    }
    
    //Serial.println(seconds[i]);
    if(seconds[i] >= 3600){
      if(Debug_toDisplayTime){
        if(i == 0){
          Serial.print(H[0]);
          Serial.print(H[1]);
          Serial.print(M[0]);
          Serial.print(M[1]);
        }else{
          Serial.print(H[0]);
          Serial.print(H[1]);
          Serial.print(M[0]);
          Serial.println(M[1]);
        }
      }
      Toshow[0+add] = H[0];
      Toshow[1+add] = H[1];
      Toshow[2+add] = M[0];
      Toshow[3+add] = M[1];
    }else{
      if(Debug){
        if(i == 0){
          Serial.print(M[0]);
          Serial.print(M[1]);
          Serial.print(S[0]);
          Serial.print(S[1]);
        }else{
          Serial.print(M[0]);
          Serial.print(M[1]);
          Serial.print(S[0]);
          Serial.println(S[1]);
        }
      }
      Toshow[0+add] = M[0];
      Toshow[1+add] = M[1];
      Toshow[2+add] = S[0];
      Toshow[3+add] = S[1];
    }
    
    
  }
}

void setPers(){
  //code
}



void endOfTime(int side, long Time){
  // Verify if the sideTime is setted, if setted, make nothing
  if(sideTime == -1){
    // Set the var with the side of the end the time, to show with this time is out.
    if(Time <= 0){
      sideTime = side;
    }
  }
}

int modifyCounter = 0;

int player;
long time1;
long time2;
boolean start = false;
boolean started = false;

int more1Hour = 0;
void modifyPoints(){
  if(sideTime == -1){
        //0.000.00
        Point[0] = '0';
        Point[2] = '0';
        Point[3] = '0';
        Point[4] = '0';
        Point[6] = '0';
        Point[7] = '0';
        if(start){
          if(time1 > 36000 && player == 0 && started == true){
              if(more1Hour < 5){
                Point[1] = '.';
                more1Hour++;
              }else{
                if(more1Hour == 10){
                  Point[1] = '0';
                  more1Hour = 0;
                }else{
                Point[1] = '0';
                more1Hour++;
              }
              }
          }else{
            Point[1] = '.';
          }
          if(time2 > 36000 && player == 1 && started == true){
            if(more1Hour < 5){
              Point[5] = '.';
              more1Hour++;
            }else{
              if(more1Hour == 10){
                Point[5] = '0';
                more1Hour = 0;
              }else{
                Point[5] = '0';
                more1Hour++;
              }
            }
          }else{
            Point[5] = '.';
          }
        }else{
          Point[1] = '.';
          Point[5] = '.';
        }
  }else{
    if(sideTime == 0){
      if(modifyCounter == 1){
        Point[0] = '0';
        Point[1] = '0';
        Point[2] = '0';
        Point[3] = '0';
        Point[4] = '0';
        Point[5] = '.';
        Point[6] = '0';
        Point[7] = '0';
        modifyCounter = 0;
      }else{
        points = '....0.00';
        Point[0] = '.';
        Point[1] = '.';
        Point[2] = '.';
        Point[3] = '.';
        Point[4] = '0';
        Point[5] = '.';
        Point[6] = '0';
        Point[7] = '0';
        modifyCounter = 1;
      }
    }else{
      if(modifyCounter == 1){
        Point[0] = '0';
        Point[1] = '.';
        Point[2] = '0';
        Point[3] = '0';
        Point[4] = '0';
        Point[5] = '0';
        Point[6] = '0';
        Point[7] = '0';
        modifyCounter = 0;
      }else{
        Point[0] = '0';
        Point[1] = '.';
        Point[2] = '0';
        Point[3] = '0';
        Point[4] = '.';
        Point[5] = '.';
        Point[6] = '.';
        Point[7] = '.';
        modifyCounter = 1;
      }
    }
  }
}

// Here init the part of the code where shows on the display really...
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

    lc.clearDisplay(0);

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
        numStep = 2;
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
        lc.clearDisplay(0);
        setDig("00030000", "0.00....", 8);
        trying = false;
        delay(400);
        setDig("00030000", "0.000000", 8);
        programSeconds = toMiliseconds(0,3,0);
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
              programSeconds = toMiliseconds(0,3,0);
              programAdd = 0;
              programAddSeconds = 0;
              break;
            case 2:  
              setDig("00050000", "0.000000", 8);
              programSeconds = toMiliseconds(0,5,0);
              programAdd = 0;
              programAddSeconds = 0;
              break;
            case 3:  
              setDig("00100000", "0.000000", 8);
              programSeconds = toMiliseconds(0,10,0);
              programAdd = 0;
              programAddSeconds = 0;
              break;
            case 4:  
              setDig("00150000", "0.000000", 8);  
              programSeconds = toMiliseconds(0,15,0);
              programAdd = 0;
              programAddSeconds = 0;
              break;
            case 5:  
              setDig("00200000", "0.000000", 8); 
              programSeconds = toMiliseconds(0,20,0);
              programAdd = 0;
              programAddSeconds = 0;
              break;
            case 6:  
              setDig("01300000", "0.000000", 8);
              programSeconds = toMiliseconds(1,30,0);
              programAdd = 0;
              programAddSeconds = 0;
              break;
            case 7:  
              setDig("02000000", "0.000000", 8);
              programSeconds = toMiliseconds(2,0,0);
              programAdd = 0;
              programAddSeconds = 0;
              break;
            case 8:  
              setCar(B01100111,B01001111,B00000101,B11011011,B00000000,B00000000,B00000000,B00000000);
              break;
          }
          
          Serial.println(programSeconds);
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
        programSeconds = toMiliseconds(0,3,0);
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
      trying = true;
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
              programSeconds = toMiliseconds(0,3,0);
              programAdd = 1;
              programAddSeconds = 2;
              break;
            case 2:  
              setDig("00150005", "0.000.00", 8);
              programSeconds = toMiliseconds(0,15,0);
              programAdd = 1;
              programAddSeconds = 5;
              break;
            case 3:  
              setDig("01300030", "0.000.00", 8);
              programSeconds = toMiliseconds(1,30,0);
              programAdd = 1;
              programAddSeconds = 30;
              break;
            case 4:  
              setCar(B01100111,B01001111,B00000101,B11011011,B00000000,B00000000,B00000000,B00000000);
              break;
          }
          
          Serial.println(programSeconds);
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

    boolean led = false;

    boolean delayButton = true;

    int timesButton = 0;
    
void step3(){
  while(Step3){
    while(trying){
      lc.clearDisplay(0);
      time1 = programSeconds;
      time2 = programSeconds;
      if(digitalRead(btnNegras) == 1){
        player = 0;
      }else{
        player = 1;
      }
      trying = false;
    }
    if(a1 == 1){
      step3_sA();
    }else{
      step3_cA();
    }
  }
}

//Without add
void step3_sA(){
  toDisplayTime(time1,time2);
  modifyPoints();
  setNum(8);
  delay(setDelay);
  if(start){
    
    if(digitalRead(btnNegras) == 1){
       time1 = time1 - 1;
        if(player == 1){
          player = 0;
        }
    }else{
       time2 = time2 - 1;
        if(player == 0){
          player = 1;
        }
    }
    
    if(timesButton == 0){
      if(digitalRead(btn3) == 1){
         start = false;
         delayButton = true;
      }
    }else{
      timesButton--;
    }
    
    endOfTime(0, time1);
    endOfTime(1, time2);
  }else{
    if(delayButton){
      delay(300);
      delayButton = false;
    }
    if(digitalRead(btn3) == 1){
       start = true;
       started = true;
       timesButton = 3;
       if(digitalRead(btnNegras == 1)){
        player = 0;
       }else{
        player = 1;        
       }
    }
  }
}

//With add
void step3_cA(){
  toDisplayTime(time1,time2);
  modifyPoints();
  setNum(8);
  delay(setDelay);
  if(start){
    
    if(digitalRead(btnNegras) == 1){
       if(time1>0){ time1 = time1 - 1; } 
    }else{
       if(time2>0){ time2 = time2 - 1; } 
    }
    
    if(player == 1 && digitalRead(btnNegras) == 1){
      player = 0;
      if(time2>0){ time2 = time2 + toMiliseconds(0,0,programAddSeconds); }
    }
    if(player == 0 && digitalRead(btnNegras) == 0){
      player = 1;
      if(time1>0){  time1 = time1 + toMiliseconds(0,0,programAddSeconds); }
    }
    
    if(timesButton == 0){
      if(digitalRead(btn3) == 1){
         start = false;
         delayButton = true;
      }
    }else{
      timesButton--;
    }
    
    endOfTime(0, time1);
    endOfTime(1, time2);
  }else{
    if(delayButton){
      delay(300);
      delayButton = false;
    }
    if(digitalRead(btn3) == 1){
       start = true;
       started = true;
       timesButton = 3;
       if(digitalRead(btnNegras == 1) && started == 0){
        player = 0;
       }else{
        if(digitalRead(btnNegras == 0) && started == 0){
          player = 1;  
        }      
       }
    }
  }
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

