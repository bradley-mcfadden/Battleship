#include "Board.h"
//reset board to EMPTY state
void Board::reset() noexcept{
	for (size_t idx; idx < BOARD_SIZE; ++idx){
		m_primary1[idx] = m_primary2[idx] 
		= PlayerPiece::EMPTY;
		m_tracking1[idx] = m_tracking2[idx] 
		= EnemyPiece::EMPTY;
	}
	totalMoves = 0;
}

//verify a move is withing range and not targeting an
//already attacked cell
bool Board::isLegal(const Move &move) const noexcept{
	//validate range
	if (!(move.row >= 1 && move.row <= 10))
		return false;
	if (!(move.col >= 'A' && move.col <= 'J'))
		return false;
	//convert from x,y to xy
	size_t x = (size_t)(move.col - 65);
	size_t y = (move.row - 1);
	size_t idx = x + y * 10;
	//check that player has not attacked this
	//cell before
	if (totalMoves % 2 == 0)
	{
		if (m_tracking1[idx] 
			!= EnemyPiece::EMPTY)
			return false;
	}
	else
	{
		if (m_tracking2[idx]
			!= EnemyPiece::EMPTY)
			return false;
	}
	return true;
}

//output player's board and enemy's tracking
//   A  B  C  D  E  F  G  H  I  J
//1
//2
//3
//4
//5
//6
//7
//8
//9
//10
void Board::display(int player) const noexcept{
	EnemyPiece e_tracking[BOARD_SIZE];
	PlayerPiece p_primary[BOARD_SIZE];

	if (player == 1){
		std::copy(m_tracking2, m_tracking2 +
		BOARD_SIZE, e_tracking);
		std::copy(m_primary1, m_primary1 +
		BOARD_SIZE, p_primary);
	}
	else{
		std::copy(m_tracking1, m_tracking1 +
		BOARD_SIZE, e_tracking);
		std::copy(m_primary2, m_primary2 +
		BOARD_SIZE, p_primary);
	}

	std::cout << "Player " << player << "'s "
	<< " primary board:\n";
	std::cout << '\t';
	for (char col = 'A'; col <= 'J'; ++col)
		std::cout << col << '\t';
	std::cout << '\n';

	for (size_t idx = 0; idx < BOARD_SIZE; ++idx){
		if (idx % 10 == 0)
			std::cout << (idx%10 + 1);
		std::cout << (int)p_primary[idx];
		if (idx % 10 == 9)
			std::cout << '\n';
	}

	std::cout << "Player " << (player%2 + 1) 
	<< "'s tracking board:\n";
	std::cout << '\t';
	for (char col = 'A'; col <= 'J'; ++col)
		std::cout << col << '\t';
	std::cout << '\n';

	for (size_t idx = 0; idx < BOARD_SIZE; ++idx){
		if (idx % 10 == 0)
			std::cout << (idx%10 + 1);
		std::cout << (int)e_tracking[idx];
		if (idx % 10 == 9)
			std::cout << '\n';
	}
}

//update the correct board with the corresponding move
EnemyPiece Board::makeMove(const Move &move){
	//convert x,y to xy
	size_t x = (size_t)(move.col - 65);
	size_t y = (move.row - 1);
	size_t idx = x + y * 10;
	//if player 1
	if (totalMoves % 2 == 0)
	{
		if (m_primary2[idx] 
		!= PlayerPiece::EMPTY){
			m_tracking1[idx] 
			= EnemyPiece::HIT;
		} else {
			m_tracking1[idx]
			= EnemyPiece::MISS;
		}
		return m_tracking1[idx];
	}
	//if player 2
	else
	{
		if (m_primary1[idx] 
		!= PlayerPiece::EMPTY){
			m_tracking2[idx] 
			= EnemyPiece::HIT;
		} else {
			m_tracking2[idx]
			= EnemyPiece::MISS;
		}
		return m_tracking2[idx];
	}	
}

