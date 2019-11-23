//Bradley McFadden
//SN 0370776

#include "RandomPlayer.h"
//Grab a random move from the vector of unused moves
//<param gameBoard> Reference to the Board object
//<param player> Number of this player
//<return> Returns a valid move
Move RandomPlayer::makeMove(const Board &gameBoard, int player) {
    Move vec;
    size_t index;
    while (true){
        index = rand() % m_unused.size();
        size_t move = m_unused[index];
        vec.row = (move / 10) + 1;
        vec.col = 'A' + (move % 10);
        if (gameBoard.isLegal(vec, player))
            break;
    }
    m_unused[index] = m_unused.back();
    m_unused.pop_back();
    return vec;
}

//Place a piece on this player's board. This always results in the same output depending
//for the same PlayerPiece
//<param gameBoard> Reference to the Board object
//<param which> Which PlayerPiece will be getting placed
//<param player> Number of this player
void RandomPlayer::placePiece(Board &gameBoard, PlayerPiece which, int player) {
    switch(which){
    case PlayerPiece::PATROL_BOAT://2
        gameBoard.placePiece({'B',3}, {'C',3}, player, which);
        break;
    case PlayerPiece::SUBMARINE://3
        gameBoard.placePiece({'G',3}, {'I',3}, player, which);
        break;
    case PlayerPiece::DESTROYER://3
        gameBoard.placePiece({'B', 6}, {'B', 8}, player, which);
        break;
    case PlayerPiece::BATTLESHIP://4
        gameBoard.placePiece({'E', 6}, {'E', 9}, player, which);
        break;
    case PlayerPiece::CARRIER://5
        gameBoard.placePiece({'H', 6}, {'H', 10}, player, which);
        break;
    default:
        std::cerr << "in RandomPlayer::placePiece:" << (int)(which) << " unexpected\n";
    }
}

//Reset the RandomPlayer's list of moves
void RandomPlayer::reset(){
    m_unused.reserve(100);
    for (size_t i = 0; i < 100; ++i)
        m_unused[i] = i;
    
}
