#include <Adafruit_GFX.h>    
#include <Adafruit_ST7735.h> 
#include <SPI.h>


#define TFT_CS    10
#define TFT_RST   8  
#define TFT_DC    9 

#define TFT_SCLK 13   
#define TFT_MOSI 11   

#define MenuItemCount 3

//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

const char menuNames[MenuItemCount][8] = { "Pelaa", "Tekijat", "Lopeta" };

int currentMode = 0; //0 = Main Menu, 1 = Pong
int playerSize = 42;

//PlayerLocations
int playerPos1 = 42; //Pelaaja
int playerPos2 = 42; //"Tekoäly"

void setup(void) {  
  Serial.begin(9600);
  tft.initR(INITR_BLACKTAB);  
  tft.setRotation(1);
  splashScreen();
  delay(500);  
  printMainMenu();

}




void (* resetFunc)(void) = 0;

void restartArduino(){
  resetFunc();
}



void loop() {

  if(currentMode == 0){
    //Main menu loop.
    delay(1000);
    StartPong();
  }else{
    //Game Loop.
    MovePlayerDown(1);
    MovePlayerDown(2);
    delay(33);
    MovePlayerDown(1);
    MovePlayerDown(2);
    delay(33);
    MovePlayerDown(1);
    MovePlayerDown(2);
    delay(33);
    MovePlayerDown(1);
    MovePlayerDown(2);
    delay(33);
    MovePlayerDown(1);
    MovePlayerDown(2);
    delay(33);
    MovePlayerUp(1);
    MovePlayerUp(2);
    delay(33);
    MovePlayerUp(1);
    MovePlayerUp(2);
    delay(33);
    MovePlayerUp(1);
    MovePlayerUp(2);
    delay(33);
    MovePlayerUp(1);
    MovePlayerUp(2);
    delay(33);
    MovePlayerUp(1);
    MovePlayerUp(2);
    delay(33);
  }
  delay(33); //33ms = 30FPS, 16ms = 60FPS, 41ms = 24FPS.
}

void StartPong(){
  //Draw game.
  tft.fillScreen(ST7735_BLACK);
  //Draw board.
  drawBoard();
  //Set gamemode.
  currentMode = 1;
}

void drawBoard(){
  drawPlayer(9);
  drawPlayer(150);
  //drawBall();
}

void drawPlayer(int xPos){
  //Draw 2 lines to make it 2 width.
  tft.drawFastVLine(xPos, 42, playerSize, ST7735_WHITE);
  tft.drawFastVLine(xPos+1, 42, playerSize, ST7735_WHITE);
}

//playerID 1 = Pelaaja.
void MovePlayerUp(int playerID){
  if(playerID == 1){
    //DrawNewPixels
    tft.drawPixel(9, playerPos1+43, ST7735_WHITE);
    tft.drawPixel(10, playerPos1+43 , ST7735_WHITE);

    //Undraw old ones
    tft.drawPixel(9, playerPos1, ST7735_BLACK);
    tft.drawPixel(10, playerPos1, ST7735_BLACK);
    playerPos1++;
  } else {
    //DrawNewPixels
    tft.drawPixel(150, playerPos2+43, ST7735_WHITE);
    tft.drawPixel(151, playerPos2+43 , ST7735_WHITE);

    //Undraw old ones
    tft.drawPixel(150, playerPos2, ST7735_BLACK);
    tft.drawPixel(151, playerPos2, ST7735_BLACK);
    playerPos2++;
  }
}

void MovePlayerDown(int playerID){
  if(playerID == 1){
    //DrawNewPixels
    tft.drawPixel(9, playerPos1-1, ST7735_WHITE);
    tft.drawPixel(10, playerPos1-1, ST7735_WHITE);
    
    //Undraw old ones
    tft.drawPixel(9, playerPos1+43, ST7735_BLACK);
    tft.drawPixel(10, playerPos1+43 , ST7735_BLACK);
    playerPos1--;
    } else {
    //DrawNewPixels
    tft.drawPixel(150, playerPos2-1, ST7735_WHITE);
    tft.drawPixel(151, playerPos2-1, ST7735_WHITE);
    
    //Undraw old ones
    tft.drawPixel(150, playerPos2+43, ST7735_BLACK);
    tft.drawPixel(151, playerPos2+43 , ST7735_BLACK);

    playerPos2--;
  }
}
