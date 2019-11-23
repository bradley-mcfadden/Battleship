//Bradley McFadden
//SN 0370776

#include "Game.h"

int main(){
    Game driver;
    driver.selectPlayers();
    driver.placePieces();
    driver.play();
    driver.announceWinner();
    return 0;
}
