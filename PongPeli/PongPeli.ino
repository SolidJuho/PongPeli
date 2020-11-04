#include <Adafruit_GFX.h>    
#include <Adafruit_ST7735.h> 
#include <SPI.h>


#define TFT_CS    10
#define TFT_RST   8  
#define TFT_DC    9 

#define TFT_SCLK 13   
#define TFT_MOSI 11   

#define MenuItemCount 3

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

const char menuNames[MenuItemCount][8] = { "Pelaa", "Tekijat", "Lopeta" };
const int startY = 50;

int menuId;

void setup(void) {  
  Serial.begin(9600);
  tft.initR(INITR_BLACKTAB);  
  tft.setRotation(1);
  splashScreen();
  delay(500);  
  
  tft.fillScreen(ST7735_BLACK);
  
  printTitle();
  printMenuItems();
  highlightItem(0,0);
}

void loop() {
  //Check if in game state.
  //If not, print menu.
  //Read input
  delay(500);

  
  //int newDebugID = random(3);
  //highlightItem(menuId, newDebugID);
  //menuGoUp();
  //menuGoDown();
}
