//Bradley McFadden
//SN 0370776
#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <algorithm>
struct CharInt{
	size_t row;
	char col;
};
typedef CharInt Move;

enum class EnemyPiece{
	HIT,
	MISS,
	EMPTY
};

enum class PlayerPiece{
	PATROL_BOAT,
	SUBMARINE,
	DESTROYER,
	BATTLESHIP,
	CARRIER,
	EMPTY
};

class Board{
	const static size_t BOARD_SIZE = 100;
	size_t totalMoves = 0;
	PlayerPiece m_primary1[BOARD_SIZE];
	EnemyPiece m_tracking1[BOARD_SIZE];
	PlayerPiece m_primary2[BOARD_SIZE];
	EnemyPiece m_tracking2[BOARD_SIZE];

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
	bool isLegal(const Move &move) const noexcept;
	//updates the board with a move and returns
	//state at the corresponding cell
	EnemyPiece makeMove(const Move &move);
	//returns false if piece goes off board
	//or overlaps with another piece
	bool isLegal(const Move &move, const Move &move) const noexcept;
	//place a piece on the board
	//must check if the move is legal
	PlayerPiece placePiece(const Move &move, const Move &move, PlayerPiece what) const noexcept;
};
#endif
