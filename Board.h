//Bradley McFadden
//SN 0370776

#ifndef BOARD_H
#define BOARD_H

#define RED "\033[31m"
#define BLUE "\033[32m"
#define GREEN "\033[34m"
#define CYAN "\033[36m"

#define INVERT "\033[7m"
#define RESET "\033[0m"

#include <iostream>
#include <algorithm>
#include <cmath> //For std::abs
struct CharInt{
    size_t row;
    char col;
};

typedef CharInt Move;

enum class EnemyPiece{
    EMPTY = 0,
    HIT = 1, // GREEN
    MISS = 2 // BLUE
};

enum class PlayerPiece{
    EMPTY = 0,
    PATROL_BOAT = 1,//2
    SUBMARINE = 2,//3
    DESTROYER = 3,//3
    BATTLESHIP = 4,//4
    CARRIER = 5//5
};

class Board{
    const static size_t BOARD_SIZE = 100;
    PlayerPiece m_primary1[BOARD_SIZE]{};
    EnemyPiece m_tracking1[BOARD_SIZE]{};
    PlayerPiece m_primary2[BOARD_SIZE]{};
    EnemyPiece m_tracking2[BOARD_SIZE]{};
    
public:
    //set every board to EMPTY and totalMoves to 0
    Board(){ reset(); }

    //set every board to EMPTY and totalMoves to 0
    void reset() noexcept;

    //output p1 board and p2 tracking if player 1
    //else output the opposite
    void display(int player) const noexcept;

    //verify that a move's coordinates are within
    //[A-J] and [1-10] range, and also that they 
    //do not target an already attacked cell
    bool isLegal(const Move &move, int player) const noexcept;

    //updates the board with a move and returns
    //state at the corresponding cell
    EnemyPiece makeMove(const Move &move, int player);

    //place a piece on the board
    //must check if the move is legal
    bool placePiece(const Move &move1, const Move &move2, int player, PlayerPiece piece) noexcept;

    //bounds checks a move
    bool isWithinRange(const Move &move) const noexcept;
};
#endif
