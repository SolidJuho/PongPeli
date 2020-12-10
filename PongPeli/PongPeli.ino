#include <Adafruit_GFX.h>    
#include <Adafruit_ST7735.h> 
#include <SPI.h>


#define TFT_CS    10
#define TFT_RST   8  
#define TFT_DC    9 

#define TFT_SCLK 13   
#define TFT_MOSI 11   

#define AsetuksetItemCount 4
#define MenuItemCount 4
//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);




const char menuNames[MenuItemCount][10] = { "Pelaa", "Tekijat", "Asetukset", "Lopeta"};
int PADDLE_RATE = 25;
double paddle_update;
int currentMode = 0; //0 = Main Menu, 1 = Pong, 2 = asetuksetvalikko
int playerSize = 42;
//PlayerLocations
const int PlayerPosX1 = 9;
const int PlayerPosX2 = 150;
int playerPosY1 = 42; //Pelaaja
int playerPosY2 = 42; //"Tekoäly"

const char SELECT_BUTTON = 4; //Valitse nappi
const char DOWN_BUTTON = 3; //Alas nappi
const char UP_BUTTON = 2;//Ylös nappi



///Ball data
int ballX;
int ballY;
int ballDirX;
int ballDirY;

void setup(void) { 
  Serial.begin(9600);
  tft.initR(INITR_BLACKTAB);  
  tft.setRotation(1);
  splashScreen();
  delay(500);  
  printMainMenu();
  
  
   pinMode(UP_BUTTON, INPUT_PULLUP); // Inputataan ylös nappi ylösvetovastukseen
   pinMode(DOWN_BUTTON, INPUT_PULLUP); // Inputataan alas nappi ylösvetovastukseen
   pinMode(SELECT_BUTTON, INPUT_PULLUP); // Inputataan valitse nappi ylösvetovastukseen
   paddle_update=millis();

}




void (* resetFunc)(void) = 0;

void restartArduino(){
  resetFunc();
}



void loop() {

  returnToMainMenu(); //Kutsutaan void returnToMainMenu toisesta tabistä looppiin
  asetuksetcontrolls(); //Kutsutan void asetuksetcontrolls toisesta tabistä looppiin
  
  if(currentMode == 0){
    mainemenucontrolls(); //kutsutaan void mainmenucontrolls toisesta tabistä looppiin
    //Main menu loop.
  }
   
  if(currentMode == 1){
    ballUpdate();
    AI();
    playercontrolls(); //kutsutaan void playercontrolls toisesta tabistä looppiin  

  }
  delay(16); //33ms = 30FPS, 16ms = 60FPS, 41ms = 24FPS. 
}

void ballUpdate(){
  int new_x = ballX + ballDirX;
  int new_y = ballY + ballDirY;
  //Check hits.
  if(new_x==0){
    //AI Maali
    return setupBall(ballX, ballY);
  }else if(new_x+1==160){
    //Pelaaja maali.
    return setupBall(ballX, ballY);
  }

  //Check floor/ceiling
  if(new_y == 0 || new_y == 128){
    ballDirY = -ballDirY;    
    new_y = ballY + ballDirY;
  }

  if((new_x == PlayerPosX1+3 && new_y > playerPosY1 && new_y < playerPosY1+playerSize )|| new_x == PlayerPosX2-2 && new_y > playerPosY2 && new_y < playerPosY2+playerSize){
    //Hit from P1   
    ballDirX = -ballDirX;
  }
  
  //undrawOldBall
  tft.fillCircle(ballX, ballY, 1, ST7735_BLACK);

  //Calculate ball pos
  ballX = new_x;
  ballY = new_y;
  
  //drawNewBall
  tft.fillCircle(ballX, ballY, 1, ST7735_WHITE);
}


void StartPong(){
  //Draw game.
  tft.fillScreen(ST7735_BLACK);
  //Draw board.
  drawBoard();
  //Set gamemode.
  currentMode = 1;
  //Create ball at middle with random posY and dir.
  setupBall();

}

void setupBall(){
  ballY = random(40,84);  
  ballX = 84;
  ballDirX = randomDir();
  ballDirY = randomDir();
  
}

void setupBall(int oldX, int oldY){
  tft.fillCircle(oldX, oldY, 1, ST7735_BLACK);
  ballY = random(20,104);  
  ballX = 84;
  ballDirX = randomDir();
  ballDirY = randomDir();

}

void drawBoard(){
  drawPlayer(9);
  drawPlayer(150);
  //drawBall();

}

int randomDir(){
  int i = random(0,2);
  if(i == 0)
    i = -1;
  return i;
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
    tft.drawPixel(PlayerPosX1, playerPosY1+43, ST7735_WHITE);
    tft.drawPixel(PlayerPosX1+1, playerPosY1+43 , ST7735_WHITE);

    //Undraw old ones
    tft.drawPixel(PlayerPosX1, playerPosY1, ST7735_BLACK);
    tft.drawPixel(PlayerPosX1+1, playerPosY1, ST7735_BLACK);
    playerPosY1++;
  } else {
    //DrawNewPixels
    tft.drawPixel(PlayerPosX2, playerPosY2+43, ST7735_WHITE);
    tft.drawPixel(PlayerPosX2+1, playerPosY2+43 , ST7735_WHITE);

    //Undraw old ones
    tft.drawPixel(PlayerPosX2, playerPosY2, ST7735_BLACK);
    tft.drawPixel(PlayerPosX2+1, playerPosY2, ST7735_BLACK);
    playerPosY2++;
  }
}

void MovePlayerDown(int playerID){
  if(playerID == 1){
    //DrawNewPixels
    tft.drawPixel(PlayerPosX1, playerPosY1-1, ST7735_WHITE);
    tft.drawPixel(PlayerPosX1+1, playerPosY1-1, ST7735_WHITE);
    
    //Undraw old ones
    tft.drawPixel(PlayerPosX1, playerPosY1+43, ST7735_BLACK);
    tft.drawPixel(PlayerPosX1+1, playerPosY1+43 , ST7735_BLACK);
    playerPosY1--;
    } else {
    //DrawNewPixels
    tft.drawPixel(PlayerPosX2, playerPosY2-1, ST7735_WHITE);
    tft.drawPixel(PlayerPosX2+1, playerPosY2-1, ST7735_WHITE);
    
    //Undraw old ones
    tft.drawPixel(PlayerPosX2, playerPosY2+43, ST7735_BLACK);
    tft.drawPixel(PlayerPosX2+1, playerPosY2+43 , ST7735_BLACK);

    playerPosY2--;
  }
}
