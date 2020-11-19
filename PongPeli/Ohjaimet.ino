void mainemenucontrolls(){
// Liikkuu ylös menussa kun nappia painetaan.
  if(!digitalRead(UP_BUTTON) && currentMode==0){
    delay(300);
    menuGoUp();
    
  }

//Liikku alas menussa kun nappia painetaan
  if(!digitalRead(DOWN_BUTTON)&& currentMode==0) {
     delay(300);
     menuGoDown();
  }

  if(!digitalRead(SELECT_BUTTON)&& currentMode==0){
     executeAction();
  }

}


void playercontrolls(){  
 // Paddle liikkuu ylös kun nappia painetaan.
        if(!digitalRead(UP_BUTTON) && currentMode==1) {
            MovePlayerUp(1);
      }
       //Paddle liikkuu alas kun nappia painetaan.
        if(!digitalRead(DOWN_BUTTON)&& currentMode==1) {
            MovePlayerDown(1);
   }

}
