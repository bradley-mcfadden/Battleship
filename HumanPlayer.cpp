//Bradley McFaddem
//SN0370776

#include "HumanPlayer.h"
//Collect a valid move from standard in
//<param gameBoard> Reference to the board
//<param player> Number of this player
//<return> A valid Move object
Move HumanPlayer::makeMove(const Board &gameBoard, int player) {
    std::string buffer;
    std::regex pair("[A-J][1-9]|[A-J]10");
    while(true){
        std::cin.ignore(32000, '\n');
        std::cout << "Enter a move from A-J,1-10, like A10: ";
        std::getline(std::cin, buffer);
        
        if (!std::regex_match(buffer, pair))
            continue;
        Move mine;
        mine.col = buffer[0];
        mine.row = std::stoi(buffer.substr(1));

        if (gameBoard.isLegal(mine, player))
            return mine;
    } 
}

//Collect a valid position to place a piece
//from the player, and then place it.
//<param gameBoard> Reference to the board object
//<param which> Which piece is getting put down
//<param player> The number of this player
void HumanPlayer::placePiece(Board &gameBoard, PlayerPiece which, int player) {
    std::string buffer;
    //please ignore the massive regular expression for matching pairs of coordinates
    std::regex pair("[A-J][1-9],[A-J][1-9]|[A-J][1-9],[A-J]10|[A-J]10,[A-J][1-9]|[A-J]10,[A-J]10");
    while(true){
        std::cout << "Enter two positions, such as A10, seperated by a comma: ";
        std::cin.ignore(32000, '\n');
        std::getline(std::cin, buffer);

        if (!std::regex_match(buffer, pair))
            continue;
        std::stringstream ss(buffer);
        Move m1;
        Move m2;
        ss >> m1.col;
        ss >> m1.row;
        ss.ignore();
        ss >> m2.col;
        ss >> m2.row;
        
        if (gameBoard.placePiece(m1, m2, player, which))
            break;
    }
}

