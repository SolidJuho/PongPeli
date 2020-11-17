void playercontrolls(){  
 // Paddle liikkuu ylös kun nappia painetaan.
        if(!digitalRead(UP_BUTTON)) {
            MovePlayerUp(1);
      }
       //Paddle liikkuu alas kun nappia painetaan.
        if(!digitalRead(DOWN_BUTTON)) {
            MovePlayerDown(1);
        }
}
