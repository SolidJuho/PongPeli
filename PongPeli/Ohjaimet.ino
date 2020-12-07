void mainemenucontrolls(){
// Liikkuu ylös menussa kun nappia painetaan.
  while(!digitalRead(UP_BUTTON) && currentMode==0){
    delay(300);
    menuGoUp();
    break;

  }
    
//Liikku alas menussa kun DOWN-nappia painetaan
 while(!digitalRead(DOWN_BUTTON)&& currentMode==0) {
     delay(300);
     menuGoDown();
     break;
 }     

  while(!digitalRead(SELECT_BUTTON)&& currentMode==0){
     //Toimii mainmenun valikko nappina
     delay(500);
     executeAction();
     break;
 }     
}



void playercontrolls(){  
 // Paddle liikkuu ylös kun UP-nappia painetaan.
        if(!digitalRead(UP_BUTTON) && currentMode==1) {
            MovePlayerUp(1);
      }
       //Paddle liikkuu alas kun DOWN-nappia painetaan.
        if(!digitalRead(DOWN_BUTTON)&& currentMode==1) {
            MovePlayerDown(1);
   }
}

void returnToMainMenu(){
  //Kun select-nappia painetaan pelin aikana palaa takaisin mainmenuun
while(!digitalRead(SELECT_BUTTON) && currentMode==1) {
    delay(700);
    currentMode=0;
    printMainMenu();
    break;//Poistutaan loopista
  }
}

void asetuksetcontrolls(){

 while(!digitalRead(UP_BUTTON) && asetuksetmenu==1){
    delay(300);
    AsetuksetGoUp();
    break;

  }

  //Liikku alas menussa kun DOWN-nappia painetaan
  while(!digitalRead(DOWN_BUTTON)&& asetuksetmenu==1) {
     delay(300);
     AsetuksetGoDown();
     break;
 }     

  while(!digitalRead(SELECT_BUTTON) && asetuksetmenu==1){
    delay(500);
    executeAction2();
    break;
  }
}
