
 
   void playercontrolls(){  
    
      bool currentState = digitalRead(UP_BUTTON); 
     // Paddle liikkuu ylös kun nappia painetaan.
        if(currentState == pressed) {
            MovePlayerUp(1);

        }

      bool currentState1 = digitalRead(DOWN_BUTTON);  
       //Paddle liikkuu alas kun nappia painetaan.
        if(currentState1 == pressed) {
            MovePlayerDown(1);

        }
        }
