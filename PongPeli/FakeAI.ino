void AI() {
  
if(paddle_update && currentMode==1) {
  paddle_update += PADDLE_RATE; 

const uint8_t half_paddle = playerSize >> 1;

if(playerPosY2 + half_paddle > ballY){  //Tarkistaa että onko tietokoneen mailan sijainti ylempänä mistä pallo on tulossa, jos on niin liikuttaa mailaa alaspäin.
    MovePlayerDown(0);
}

if(playerPosY2 + half_paddle < ballY) { //Tarkistaa että onko mailan sijainti alempana kuin mistä pallo on tulossa ja jos on liikuttaa mailaa ylöspäin.
    MovePlayerUp(0);
}

if(playerPosY2 < 1) playerPosY2 = 1;

if(playerPosY2 + playerSize > 128) playerPosY2 = 128 - playerSize; //128 arvoa säätelemällä voidaan määrittää kuinka alhaalla tai ylhäällä tietokoneen maila käy = Periaatteessa kuinka helposti se osuu siihen.
}
}
