//Functiot joita käytetään valikossa siirtymisiin ja piirtämiseen.

void menuGoUp(){
  if(menuId == 0){
    //Top of the list, Go to bottom.    
    highlightItem(menuId, MenuItemCount-1);
  }else{    
    highlightItem(menuId, menuId-1);
  }
}

void menuGoDown(){
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

void printTitle(){
  tft.setTextSize(2);  
  tft.setCursor(40,10);
  tft.print("Valikko");
  tft.drawFastHLine(0,30,160, ST7735_WHITE);
}

void printMenuItems(){
  for(int i; i < MenuItemCount; i++){
       printItem(menuItemHeight(i), i);
  }
}

void printItem(int yPos, int menuID){
  Serial.print(menuID);
  tft.setCursor(40,yPos);
  tft.print(menuNames[menuID]);
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
