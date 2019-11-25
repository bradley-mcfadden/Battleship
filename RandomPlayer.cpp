//Bradley McFadden
//SN 0370776

#include "RandomPlayer.h"
//Grab a random move from the vector of unused moves
//<param gameBoard> Reference to the Board object
//<param player> Number of this player
//<return> Returns a valid move
Move RandomPlayer::makeMove(const Board &gameBoard, int player) {
    Move vec;
    int index;
    while (true){
        //std::cout << "A random number " << (int)rand() % m_unused.size() << '\n';
        int rnum = rand();
        //std:: cout << rnum << '\n';
        int size = m_unused.size();
        //std::cout << size << '\n';
        index = rnum % size;
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
    Move m1, m2;
    switch(which){
    case PlayerPiece::PATROL_BOAT://2
        m1.row = m2.row = 3;
        m1.col = 'A';
        m2.col = 'B';
        break;
    case PlayerPiece::SUBMARINE://3
        m1.row = m2.row = 5;
        m1.col = 'D';
        m2.col = 'F';
        break;
    case PlayerPiece::DESTROYER://3
        m1.row = m2.row = 8;
        m1.col = 'A';
        m2.col = 'C';
        break;
    case PlayerPiece::BATTLESHIP://4
        m1.row = m2.row = 2;
        m1.col = 'D';
        m2.col = 'G';
        break;
    case PlayerPiece::CARRIER://5
        m1.col = m2.col = 'I';
        m1.row = 4;
        m2.row = 8;
        break;
    default:
        break;
        //std::cerr << "in RandomPlayer::placePiece:" << (int)(which) << " unexpected\n";
    }
    gameBoard.placePiece(m1, m2, player, which);
}

//Reset the RandomPlayer's list of moves
void RandomPlayer::reset(){
    m_unused.reserve(100);
    for (size_t i = 0; i < 100; ++i)
        m_unused.push_back(i);
}
