 String firmware_version = "V1.0";

#include "U8glib.h"
#include <EEPROM.h>
U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE);	// I2C / TWI 

// box3d logo
int width = 120;
int height = 47;
int x;
int y;
const uint8_t box3d_full_bitmap[] PROGMEM = {
0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x03, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x7F, 0xC7, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xF0,
0x07, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFE, 0x00, 0x07,
0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xC0, 0x00, 0x07, 0xFF,
0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x07, 0xFF, 0xF8,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x10, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x18, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x18, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x03, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x03, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC0,
0x00, 0x00, 0x07, 0xFF, 0xFE, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x00,
0x00, 0x07, 0xFF, 0xFE, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x00,
0x07, 0xFF, 0xFE, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x07,
0xFF, 0xFE, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x07, 0xFF,
0xFE, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE,
0x19, 0xFC, 0x01, 0xFC, 0x30, 0x1C, 0xFF, 0x07, 0xF3, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x1B,
0xDE, 0x07, 0xDF, 0x18, 0x19, 0xFF, 0x0F, 0x3B, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x1A, 0x07,
0x0E, 0x03, 0x9C, 0x30, 0x03, 0x1C, 0x0F, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x1C, 0x03, 0x8C,
0x01, 0x8C, 0x70, 0x03, 0x18, 0x07, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x1C, 0x01, 0x9C, 0x00,
0xC6, 0x60, 0x03, 0x38, 0x03, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x1C, 0x01, 0x98, 0x00, 0xC7,
0xC0, 0x03, 0x30, 0x03, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x18, 0x01, 0x98, 0x00, 0xC3, 0xC0,
0x03, 0x30, 0x03, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x18, 0x01, 0x98, 0x00, 0xC1, 0x80, 0x7F,
0x30, 0x03, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x18, 0x01, 0x98, 0x00, 0xC3, 0xC0, 0x7F, 0x30,
0x03, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x1C, 0x01, 0x98, 0x00, 0xC6, 0xE0, 0x03, 0x30, 0x03,
0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x1C, 0x01, 0x9C, 0x01, 0xCE, 0x60, 0x03, 0x38, 0x07, 0xC0,
0x00, 0x00, 0x07, 0xFF, 0xFE, 0x1C, 0x03, 0x8C, 0x01, 0x8C, 0x30, 0x03, 0x18, 0x07, 0xC0, 0x00,
0x00, 0x07, 0xFF, 0xFE, 0x1A, 0x07, 0x0E, 0x03, 0x98, 0x38, 0x03, 0x1C, 0x0F, 0xC0, 0x00, 0x00,
0x07, 0xFF, 0xFE, 0x1B, 0xFE, 0x07, 0xFF, 0x38, 0x19, 0xFF, 0x0F, 0xFB, 0xC0, 0x00, 0x00, 0x07,
0xFF, 0xFE, 0x19, 0xFC, 0x01, 0xFC, 0x70, 0x0C, 0xFF, 0x07, 0xF3, 0xC0, 0x00, 0x00, 0x07, 0xFF,
0xFE, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x07, 0xFF, 0xFE, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x07, 0xFF, 0xF8, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xC0, 0x00, 0x07, 0xFF, 0xE0, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFE, 0x00, 0x07, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xF0, 0x07, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x87, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 
};

// button 2 (up)
const int Button2Pin = 4;
int Button2State = 0;
int lastButton2State = 0;

// button 4 (down)
const int Button4Pin = 2;
int Button4State = 0;
int lastButton4State = 0;

// button 1 (menu)
const int Button1Pin = 5;
int Button1State = 0;
int lastButton1State = 0;


// button 3 (back)
const int Button3Pin = 3;
int Button3State = 0;
int lastButton3State = 0;

// Menu margins
const int MarginL = 20;
const int MarginR = 20;
const int spacing = 12;

// Menu
int MenuState = 0; // state of menu. 0 = homescreen, 1 = menu
int MenuPos = 0; // position in the menu. 0 = top row, 1 second, etc.
String MenuString[] = {"Fan min", "Fan max", "T calib", "Factory reset", "Info"};
int8_t MenuValues[] = {25, 100, 0};
String MenuUnits[]  = {"%", "%", "C"};
int CurrentValue = 0;
int MenuValuesLength = 3;
int MenuLength = 5;
int MenuPages = ceil(MenuLength/4.0);
int CurrentMenuPage = 0;
bool MenuSelection = false;

// fan/control
const int pwmpin = 9;
int FanSpeed;
int ControlMode = 0; // 0 = auto, 1 = on (max), 2 = on (min)
String ControlModeString[] = {"Auto","Max","Min"};
unsigned long LastMillis = 0;

// NTC Temperature sensor
#define THERMISTORPIN A0         
#define THERMISTORNOMINAL 10000   // resistance at 25 degrees C  
#define TEMPERATURENOMINAL 25   // temp. for nominal resistance (almost always 25 C)
#define BCOEFFICIENT 3950// The beta coefficient of the thermistor (usually 3000-4000)
#define SERIESRESISTOR 10000   // the value of the 'other' resistor
int T;
int Tset = 30;

//////////////// SETUP //////////////////
void setup(void) {
  FanSpeed = (int8_t)EEPROM.read(0); // initial fan speed at Min value
  pinMode(pwmpin, OUTPUT);
  setPwmFrequency(9,1);

  // display box3d logo
    y = (64-height)/2;
    x = (128-width)/2;
  u8g.firstPage();  
  do {
    u8g.drawBitmapP( x, y, width/8, height, box3d_full_bitmap);
  } while( u8g.nextPage() );
  delay(2000);

  // Instructs the display to draw with a pixel on. 
  u8g.setColorIndex(1); 

  // push buttons
  pinMode(Button1Pin, INPUT);
  pinMode(Button2Pin, INPUT);
  pinMode(Button3Pin, INPUT);
  pinMode(Button4Pin, INPUT);


  // menu variables. Store default values in EEPROM
   for(int i=0; i<MenuValuesLength; i++){
      if((int8_t)EEPROM.read(i)==-1) EEPROM.write(i, MenuValues[i]);
   }
   // Tset 
    if((int8_t)EEPROM.read(50)==-1) EEPROM.write(50, Tset);

} ///////////// END SETUP ///////////////


////////////// LOOP ////////////////
void loop(void) {
  // temperature 
  float Tread = analogRead(THERMISTORPIN);
  float resistance = SERIESRESISTOR*(1023/Tread-1);
  T = int(round(1/(log(resistance/THERMISTORNOMINAL)/BCOEFFICIENT+1.0/(TEMPERATURENOMINAL + 273.15))-273.15+(int8_t)EEPROM.read(2)));
  
  // fan speed
  FanControl();
  analogWrite(pwmpin,byte(float(FanSpeed)/100*255));
  
  // read the pushbutton 2: (up)
  Button2State = digitalRead(Button2Pin);
  if (Button2State != lastButton2State) { // compare the buttonState to its previous state
    if (Button2State == HIGH) { // if the current state is HIGH then the button went from off to on:       
      switch (MenuState){
        case 0: if((int8_t)EEPROM.read(50)<65)  EEPROM.write(50,(int8_t)EEPROM.read(50)+1); break;
        case 1: {
          if(MenuPos>0 && MenuSelection==false) MenuPos--;          
          else if (MenuSelection==true){
              switch (MenuPos){
                case 0: 
                  if(CurrentValue<((int8_t)EEPROM.read(1)-5)) CurrentValue = CurrentValue+5; 
                  break;
                case 1: 
                  if(CurrentValue<100)                        CurrentValue = CurrentValue+5; 
                  break;
                case 2: 
                  if(CurrentValue<10)                         CurrentValue = CurrentValue+1; 
                  break;
              }
           }
        }
      }
    }       
    delay(50);// Delay a little bit to avoid bouncing
  }
  lastButton2State = Button2State; // save the current state as the last state, for next time through the loop
  
  // read the pushbutton 4: (down)
  Button4State = digitalRead(Button4Pin); 
  if (Button4State != lastButton4State) { // compare the buttonState to its previous state
    if (Button4State == HIGH) {// if the current state is HIGH then the button went from off to on:        
      switch (MenuState){
        case 0: if((int8_t)EEPROM.read(50)>0) EEPROM.write(50,(int8_t)EEPROM.read(50)-1); break;
        case 1: 
          if(MenuPos<(MenuLength-1) && MenuSelection==false) MenuPos++;        
          else if (MenuSelection==true){
              switch (MenuPos){
                case 0: 
                  if(CurrentValue>0)                  CurrentValue = CurrentValue-5; 
                  break;
                case 1: 
                  if(CurrentValue>((int8_t)EEPROM.read(0)+5)) CurrentValue = CurrentValue-5; 
                  break;
                case 2: 
                  if(CurrentValue>-10)                CurrentValue = CurrentValue-1; 
                  break;
              }
          }
      }
    }      
    delay(50);// Delay a little bit to avoid bouncing
  }   
  lastButton4State = Button4State;// save the current state as the last state, for next time through the loop
  
  // read the pushbutton 1: (Menu)
  Button1State = digitalRead(Button1Pin);  
  if (Button1State != lastButton1State) { // compare the buttonState to its previous state    
    if (Button1State == HIGH) {// if the current state is HIGH then the button went from off to on:
      // change menu state
      switch (MenuState){
        case 0: 
          MenuState = 1; 
          MenuPos = 0; 
          break;
        case 1: 
          if(MenuSelection==true)MenuSelection=false;
          else MenuState = 0; 
          break;        
        case 2: 
          MenuState = 1; 
          break;
        case 3: 
          MenuState = 1; 
          break;
      }
    } 
    delay(50);// Delay a little bit to avoid bouncing
  }
  // save the current state as the last state, for next time through the loop
  lastButton1State = Button1State;
    
  // read the pushbutton 3:
  Button3State = digitalRead(Button3Pin);
  if (Button3State != lastButton3State) {  // compare the buttonState to its previous state
    if (Button3State == HIGH) { // if the current state is HIGH then the button went from off to on:
     
      switch (MenuState){
        case 0: 
          switch(ControlMode){
            case 0: 
              ControlMode = 1; 
              break;
            case 1: 
              ControlMode = 2; 
              break;
            case 2: 
              ControlMode = 0; 
              break;
          }
          break;
        case 1: 
          if(MenuPos<MenuValuesLength){
            switch (MenuSelection){
              case false: 
                MenuSelection=true; 
                CurrentValue = (int8_t)EEPROM.read(MenuPos); 
                break;
              case true:  
                MenuSelection=false; 
                EEPROM.write(MenuPos,CurrentValue); 
                break;           
            }
          }else if(MenuPos==3)MenuState=2;
           else if(MenuPos==4)MenuState=3;             
          break;    
        case 2:
          for(int i=0; i<MenuValuesLength; i++){
            EEPROM.write(i, MenuValues[i]);
          }
          EEPROM.write(50, Tset);
          MenuState=1;
          break;
        case 3: MenuState=1;
      }
    }       
    delay(50);// Delay a little bit to avoid bouncing
  }
  // save the current state as the last state, for next time through the loop
  lastButton3State = Button3State;

  // draw on display    
  u8g.firstPage();
    do {  
      draw();
    } while( u8g.nextPage() );  
} //////////// END LOOP /////////////////////

////////////// DRAW /////////////////
void draw(){
  u8g.setDefaultForegroundColor();
  u8g.drawTriangle(122, 0, 128,6, 116,6);   // draw upper triangle
  u8g.drawTriangle(122,64, 127,59, 117,59); // draw lower triangle
  // draw menu symbols
  if (MenuState==0){
    // draw menu symbol
    u8g.drawBox(0,0,12,2);
    u8g.drawBox(0,4,12,2);
    u8g.drawBox(0,8,12,2); 
  }else if(MenuState==1 || MenuState==2 || MenuState==3){
    //draw return symbol
    u8g.drawCircle(6, 7, 4,U8G_DRAW_UPPER_RIGHT);
    u8g.drawCircle(6, 7, 4,U8G_DRAW_LOWER_RIGHT);  
    u8g.drawLine(0,3, 3,0);
    u8g.drawLine(0,3, 3,6);
    u8g.drawLine(0,3, 5,3);
    u8g.drawLine(2,11, 6,11);
    //draw ok symbol
    u8g.setFont(u8g_font_helvB08);u8g.setFontPosBaseline();
    u8g.setPrintPos(0, 64); u8g.print("ok");
  }
  // draw menu
  switch (MenuState){
    case 0: 
      u8g.setFont(u8g_font_8x13); u8g.setFontPosTop();
      u8g.setPrintPos(25, 12); u8g.print("Tair "); u8g.print(T); u8g.write(0xB0); u8g.print("C");
      u8g.setPrintPos(25, 27); u8g.print("Tset ");u8g.print((int8_t)EEPROM.read(50)); u8g.write(0xB0); u8g.print("C"); 
      u8g.setPrintPos(25, 42); u8g.print("Fan  ");u8g.print(FanSpeed); u8g.print("%");    
      // draw controlmode
      u8g.setFont(u8g_font_helvB08); u8g.setFontPosBaseline();
      u8g.setPrintPos(0, 64); u8g.print(ControlModeString[ControlMode]); 
      break;
    case 1:     
      menu();
      break;
    case 2: 
      u8g.setFont(u8g_font_6x12); u8g.setFontPosTop();// 7 pixel heigth
      u8g.setPrintPos(MarginL, 0); u8g.print("Factory reset");
      u8g.drawLine(MarginL,12,128-MarginR,12);
      u8g.setPrintPos(MarginL, 30); u8g.print("Are you sure?");
      break;
    case 3:
      u8g.setFont(u8g_font_6x12); u8g.setFontPosTop();// 7 pixel heigth
      u8g.setPrintPos(MarginL, 0); u8g.print("Info");
      u8g.drawLine(MarginL,12,128-MarginR,12);
      u8g.setPrintPos(MarginL, 15); u8g.print("Firmware "); u8g.print(firmware_version);
      u8g.setPrintPos(MarginL, 15+spacing); u8g.print("https://box3d.eu");    
  }
}
/////////////// END DRAW //////////////////

/////////////// MENU ////////////////////
void menu(){
  u8g.setFont(u8g_font_6x12); u8g.setFontPosTop();// 7 pixel heigth
  u8g.setPrintPos(MarginL+2, 0); u8g.print("Menu");
  CurrentMenuPage = floor(MenuPos/4.0);
  u8g.setPrintPos(92, 0); u8g.print(CurrentMenuPage+1); u8g.print("/"); u8g.print(MenuPages); 
  u8g.drawLine(MarginL,12,128-MarginR,12);
  for (int i=0; i<=3; i++){
    if ((i+CurrentMenuPage*4)<MenuLength){  
      if (MenuSelection==false && MenuPos==(i+CurrentMenuPage*4)){     
            u8g.drawBox(MarginL,(15+spacing*i),128-MarginL-MarginR,11);
            u8g.setDefaultBackgroundColor();
      }  
      u8g.setPrintPos(MarginL+2, 15 + spacing*i); u8g.print(MenuString[i+CurrentMenuPage*4]);
      if ((i+CurrentMenuPage*4)<MenuValuesLength){   
        if ((i+CurrentMenuPage*4==2 && (int8_t)EEPROM.read(2)!=0) || (i+CurrentMenuPage*4==1 && (int8_t)EEPROM.read(1)==100)) u8g.setPrintPos(74, 15 + spacing*i);
        else u8g.setPrintPos(80, 15 + spacing*i); 
        if (i+CurrentMenuPage*4==2){
          if ((int8_t)EEPROM.read(2)>0) u8g.print("+");
          u8g.print((int8_t)EEPROM.read(i+CurrentMenuPage*4)); 
          u8g.write(0xB0);
        }else u8g.print((int8_t)EEPROM.read(i+CurrentMenuPage*4)); 
        u8g.print(MenuUnits[i+CurrentMenuPage*4]);    
        u8g.setDefaultForegroundColor();   
        if (MenuSelection==true && MenuPos==(i+CurrentMenuPage*4)){
          u8g.drawBox(74-2,(15+spacing*i),128-MarginR-(74-2),11);
          u8g.setDefaultBackgroundColor();  
          if ((i+CurrentMenuPage*4==2 && CurrentValue!=0) || (i+CurrentMenuPage*4==1 && CurrentValue==100)) u8g.setPrintPos(74, 15 + spacing*i);
          else u8g.setPrintPos(80, 15 + spacing*i); 
          if (i+CurrentMenuPage*4==2){
            if (CurrentValue > 0) u8g.print("+");
            u8g.print(CurrentValue);
            u8g.write(0xB0);
          }else u8g.print(CurrentValue);           
          //if (i+CurrentMenuPage*4==2) u8g.write(0xB0);
          u8g.print(MenuUnits[i+CurrentMenuPage*4]);      
          u8g.setDefaultForegroundColor();
        } 
      }                        
    }
  } 
}
//////////////// END MENU /////////////////

////////////// FAN CONTROL /////////////////
void FanControl(){
  switch (ControlMode){
    case 0:
      int NewFanSpeed;     
      if (T > (int8_t)EEPROM.read(50) ) NewFanSpeed = (int8_t)EEPROM.read(1);    
      else NewFanSpeed = (int8_t)EEPROM.read(0);
      if ((millis() - LastMillis >= 30000) && (NewFanSpeed != FanSpeed)){ //only change fan speed if the last change was > 30s, and if the state is different than before
        FanSpeed = NewFanSpeed;
        LastMillis = millis();         
      }
      break;
    case 1:
      FanSpeed = (int8_t)EEPROM.read(1); 
      break;
    case 2: 
      FanSpeed = (int8_t)EEPROM.read(0); 
      break;
  }
}
///////////////// END FAN CONTROL //////////////////

///////////////// PWM FREQUENCY /////////////////////
void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x07; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}
/////////////////// END FREQUENCY ////////////////////



