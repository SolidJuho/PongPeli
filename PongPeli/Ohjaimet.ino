void mainemenucontrolls(){
// Liikkuu ylös menussa kun nappia painetaan.
  if(!digitalRead(UP_BUTTON) && currentMode==0){
    delay(300);
    menuGoUp();
    
  }

//Liikku alas menussa kun DOWN-nappia painetaan
  if(!digitalRead(DOWN_BUTTON)&& currentMode==0) {
     delay(300);
     menuGoDown();
  }

  if(!digitalRead(SELECT_BUTTON)&& currentMode==0){
     //Toimii mainmenun valikko nappina
     delay(500);
     executeAction();
  }
}

void Asetusvalikko() {

  if(!digitalRead(UP_BUTTON)){
   
    AsetuksetGoUp();
  }
  if(!digitalRead(DOWN_BUTTON)) {
   
    AsetuksetGoDown();
    
  }
  if(!digitalRead(SELECT_BUTTON)){
    delay(500);
    executeAction2();
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
