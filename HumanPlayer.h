//Bradley McFadden
//SN 0370776

#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H
#include "Player.h"
class HumanPlayer: public Player{
protected:
public:
	HumanPlayer(std::string name): Player(name);
	Move makeMove(const Board &game) override;
}
#endif
