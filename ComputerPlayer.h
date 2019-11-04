//Bradley McFadden
//SN 0370776

#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H
#include "Player.h"
class ComputerPlayer: public Player{
protected:
	final std::string NAME_PREFIX = "Computer ";
	static char m_letter = 'A';
public:
	ComputerPlayer()
			:Player(NAME_PREFIX+std::string(m_letter));
};
#endif
