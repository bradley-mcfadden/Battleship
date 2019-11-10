//Bradley McFadden
//SN 0370776

#include "Board.h"
//Reset all boards to EMPTY pieces
void Board::reset() noexcept{
	for (size_t idx; idx < BOARD_SIZE; ++idx){
		m_primary1[idx] = m_primary2[idx] = PlayerPiece::EMPTY;
		m_tracking1[idx] = m_tracking2[idx] = EnemyPiece::EMPTY;
	}
	totalMoves = 0;
}

//Verify that a move issued during regular turns is within
//bounds and not attacking a HIT/MISS cell
//<param move>Move to verify
//<return>Is the move indeed legal?
bool Board::isLegal(const Move &move) const noexcept{
	//validate range
	if (!isWithinRange(move))
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

//Output player's board and enemy's tracking board 
//to std::out
//<param player> The player whose primary to print
//<notes> the display of each piece is done using
//an integer cast from enumerated types.
//The following pieces correspond the the numbers
//in the second column:
//EnemyPiece::EMPTY		0
//EnemyPiece::HIT		1
//EnemyPiece::MISS		2
//PlayerPiece::EMPTY		0
//PlayerPiece::PATROL_BOAT	1
//PlayerPiece::SUBMARINE	2
//PlayerPiece::DESTROYER	3
//PlayerPiece::BATTLESHIP	4
//PlayerPiece::CARRIER		5
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

//Updates tracking and primary boards after a move
//<param move> What move to update the board with
//<return>The EnemyPiece at the corresponding index
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

//Take in two moves as the start and end point of a piece you wanna place on the board
//<param move1> Start of the piece
//<param move2> End of the piece
//<param player> Which player is placing the piece?
//<param piece> What piece does the player want to place?
//<return> True if successful, false if not
bool Board::placePiece(const Move &move1, const Move& move2, int player, PlayerPiece piece) 
noexcept{
	//bounds check player and move parameters
	if (player > 2 || player < 1)
		return false;
	if (!(isWithinRange(move1) && isWithinRange(move2)))
		return false;
		
	//convert moves into integers, then to index
	size_t x1 = (size_t)(move1.col - 65);
	size_t y1 = (move1.row - 1);
	size_t idx1 = x1 + y1 * 10;

	size_t x2 = (size_t)(move2.col - 65);
	size_t y2 = (move2.row - 1);
	size_t idx2 = x2 + y2 * 10;
	
	//determine the distance between both points
	//and the size of the boat to place
	size_t euclideanDist = x1 - x2 + y1 - y2;
	size_t boatSize;
	switch(piece){
	case PlayerPiece::PATROL_BOAT:
		boatSize = 2;
		break;
	case PlayerPiece::SUBMARINE:
		boatSize = 3;
		break;
	case PlayerPiece::DESTROYER:
		boatSize = 3;
		break;
	case PlayerPiece::BATTLESHIP:
		boatSize = 4;
		break;
	case PlayerPiece::CARRIER:
		boatSize = 5;
		break;
	default:
		return false;
	}
	if (euclideanDist != boatSize)
		return false;

	PlayerPiece *temp;
	temp = (player == 1 ? m_primary1 : m_primary2);

	//figure out whether to move up, down, right or left
	//across the grid when assigning elements
	int step = 0;
	if (idx1 == idx2){
		return false;
	} else if (x1 == x2){
		step = (x1 < x2 ? 10 : -10);
	} else if (y1 == y2){
		step = (y1 < y2 ? 1 : -1);
	} else {
		return false;
	}

	//update each grid cell with new piece
	for (size_t i=idx1; i<idx2; i+=step){
		if (temp[i] != PlayerPiece::EMPTY)
			return false;
		temp[i] = piece;
	}
	return true;
}

//Checks if a Move object is within the bounds
//of the board
//<param move>The move to check
//<return>True if within bounds
bool Board::isWithinRange(const Move &move)
const noexcept{
	if (!(move.row >= 1 && move.row <= 10))
		return false;
	if (!(move.col >= 'A' && move.col <= 'J'))
		return false;
	return true;
}
