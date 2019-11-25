//Bradley McFadden
//SN 0370776

#include "Game.h"

int main(){
    char answer;
    do {
        std::cout << "This is Battleship, do you want to play?(y/n): ";
        std::string buffer;
        std::cin >> answer;
        std::getline(std::cin, buffer);
        while (answer != 'y' && answer != 'n'){
            std::cout << "Please enter y or n: ";
            std::cin >> answer;
            std::getline(std::cin, buffer);
        }
        if (answer == 'n'){
            std::cout << "Thanks for playing!" << '\n';
            return 0;
        }
        Game driver;
        driver.selectPlayers();
        driver.placePieces();
        driver.play();
        driver.announceWinner();
    } while (true);
    return 0;
}
