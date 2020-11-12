void AI() {
if(time > paddle_update) {
paddle_update += PADDLE_RATE; 
// CPU paddle
const uint8_t half_paddle = PADDLE_HEIGHT >> 1;
if(playerPosY2 + half_paddle > ball_y) {
movePlayerDown(0);
}
if(playerPosY2 + half_paddle < ball_y) {
movePlayerUp(0);
}
if(playerPosY2 < 1) playerPosY2 = 1;
if(playerPosY2 + PADDLE_HEIGHT > 63) playerPosY2 = 63 - PADDLE_HEIGHT;
}
}
