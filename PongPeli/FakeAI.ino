void AI() {
  
if(paddle_update && currentMode==1) {
  paddle_update += PADDLE_RATE; 

const uint8_t half_paddle = playerSize >> 1;

if(playerPosY2 + half_paddle > ballY){  
    MovePlayerDown(0);
}

if(playerPosY2 + half_paddle < ballY) {
    MovePlayerUp(0);
}

if(playerPosY2 < 1) playerPosY2 = 1;

if(playerPosY2 + playerSize > 128) playerPosY2 = 128 - playerSize;
}
}
