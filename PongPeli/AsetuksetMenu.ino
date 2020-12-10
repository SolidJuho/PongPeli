 const int startY2 = 50;
 int AsetuksetId;



void AsetuksetGoDown(){
  if(AsetuksetId== 0){
    //Top of the list, Go to bottom.    
    highlightItem2(AsetuksetId, AsetuksetItemCount-1);
  }else{    
    highlightItem2(AsetuksetId, AsetuksetId-1);
  }
}

void AsetuksetGoUp(){
   if(AsetuksetId== AsetuksetItemCount-1){
    //Top of the list, Go to bottom.    
    highlightItem2(AsetuksetId, 0);
  }else{    
    highlightItem2(AsetuksetId, AsetuksetId+1);
  }
}

int menuItemHeight2(int AsetuksetId){
  return startY2+(AsetuksetId*20);
}

 
void highlightItem2(int oldHighlight2, int newHighlight2){  
  //Unhighlight old item
  tft.setCursor(10,menuItemHeight2(oldHighlight2));
  tft.setTextColor(ST7735_BLACK);
  tft.print(">>");
  
  //highlight new item.
  tft.setCursor(10,menuItemHeight2(newHighlight2));
  tft.setTextColor(ST7735_WHITE);  
  tft.print(">>");

  AsetuksetId = newHighlight2;
}

  
  void executeAction2(){
  switch(AsetuksetId){
    case 0:
    PADDLE_RATE = 40;
    StartPong();
    break;
    case 1:
    PADDLE_RATE = 30;
    StartPong();
    break;
    case 2:
    PADDLE_RATE = 10;
    StartPong();
    break;
    case 3:
    printMainMenu();
    currentMode=0;
    break;
  }    
} 
  
  
