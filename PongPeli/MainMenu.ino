//Functiot joita käytetään valikossa siirtymisiin ja piirtämiseen.

const int startY = 50;
int menuId;


void printMainMenu(){
  tft.fillScreen(ST7735_BLACK);  
  printTitle(40, "Valikko");
  printMenuItems();
  highlightItem(menuId,menuId);
}

void menuGoDown(){
  if(menuId == 0){
    //Top of the list, Go to bottom.    
    highlightItem(menuId, MenuItemCount-1);
  }else{    
    highlightItem(menuId, menuId-1);
  }
}

void menuGoUp(){
   if(menuId == MenuItemCount-1){
    //Top of the list, Go to bottom.    
    highlightItem(menuId, 0);
  }else{    
    highlightItem(menuId, menuId+1);
  }
}

void splashScreen(){
  
  Serial.print("Drawing splashscreen");
  tft.fillScreen(ST7735_BLACK); 
  tft.setTextColor(ST7735_WHITE);
  tft.setTextSize(3);  
  tft.setCursor(45,40);
  tft.println("PONG");
  tft.setTextSize(1);  
  tft.setCursor(45,60);
  tft.println("   _      _\n       __(.)< __(.)=\n       \\___)  \\___)");  
}

void printTitle(int xPos,char _text[]){
  tft.setTextSize(2);  
  tft.setCursor(xPos,10);
  tft.print(_text);
  tft.drawFastHLine(0,30,160, ST7735_WHITE);
}

void printMenuItems(){
  for(int i; i < MenuItemCount; i++){
       printItem(menuItemHeight(i), i);
  }
}

void printItem(int yPos, int menuID){
  tft.setCursor(40,yPos);
  tft.print(menuNames[menuID]);
}
void printItem(int xPos,int yPos, int valuetoPrint){
  tft.setCursor(xPos,yPos);
  tft.print(valuetoPrint);
}
void printItem(int xPos, int yPos, char _text[]){
  tft.setCursor(xPos,yPos);
  tft.print(_text);
}

int menuItemHeight(int menuId){
  return startY+(menuId*20);
}

void highlightItem(int oldHighlight, int newHighlight){
  
  //Unhighlight old item
  tft.setCursor(10,menuItemHeight(oldHighlight));
  tft.setTextColor(ST7735_BLACK);
  tft.print(">>");
  
  //highlight new item.
  tft.setCursor(10,menuItemHeight(newHighlight));
  tft.setTextColor(ST7735_WHITE);  
  tft.print(">>");

  menuId = newHighlight;
}

void PrintCredits(){
  tft.fillScreen(ST7735_BLACK);
  printTitle(10,"Tekijat");
  tft.setTextSize(1);
  printItem(10,menuItemHeight(0)*0.7, "Juho Vatanen");
  printItem(10,menuItemHeight(1)*0.7, "Elias Turpeenniemi");
  printItem(10,menuItemHeight(2)*0.7, "Niko Malm");
  
  tft.setTextSize(2);  
  //tft.setTextColor(ST7735_ORANGE);  
  printItem(10,menuItemHeight(3), "OAMK - 2020");  
  //tft.setTextColor(ST7735_WHITE);  
  delay(10000);
  printMainMenu();
}

void executeAction(){
  switch(menuId){
    case 0:
    StartPong();
    break;
    case 1:
    PrintCredits();
    break;
    case 2:
    asetukset();
    break;
    case 3:
    restartArduino();
    break;
  }    
  }
  void asetukset(){
    tft.fillScreen(ST7735_BLACK);
    printTitle(10,"Asetukset");
    tft.setTextSize(2);
    printItem(40,50,"Helppo");
    printItem(20,70,"Keskivaikea");
    printItem(40,90,"Vaikea");

    //if(
  }
 
