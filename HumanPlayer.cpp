//Bradley McFaddem
//SN0370776

#include "HumanPlayer.h"
//Collect a valid move from standard in
//<param gameBoard> Reference to the board
//<param player> Number of this player
//<return> A valid Move object
Move HumanPlayer::makeMove(const Board &gameBoard, int player) {
    Move mine;
    std::cout << "Enter a move in the form: A2:";
    std::cin >> mine.col >> mine.row;
    while (!gameBoard.isLegal(mine, player)){
    	std::cout << "Make your move(char int:"
	    << "pair such as A2:";
	std::cin >> mine.col >> mine.row;
    }
    return mine;
}

//Collect a valid position to place a piece
//from the player, and then place it.
//<param gameBoard> Reference to the board object
//<param which> Which piece is getting put down
//<param player> The number of this player
void HumanPlayer::placePiece(Board &gameBoard, PlayerPiece which, int player) {
    Move start;
    Move end;
    std::cout << "Now placing " << (int)which << "st/nd/rd/th"
	<< " piece.\n" 
        << "Enter two coords seperated by a comma(A10,B10): ";
    char temp;
    std::cin >> start.col >> start.row >> temp
	>> end.col >> end.row;
    while(!gameBoard.placePiece(start, end, player, which))
    {
	std::cout << "Now placing " << (int)which << "st/nd/rd/th"
	    << " piece.\n Enter two coords seperated by a comma:";
	std::cin >> start.col >> start.row >> temp
	    >> end.col >> end.row;
    }
}
