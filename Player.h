//Bradley McFadden
//SN 0370776

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
class Player{
protected:
	std::string m_name;
	//Board m_mine;
public:
	Player(const std::string &name): m_name(name);
	virtual Move makeMove(const Board &gameBoard) = 0;
};
#endif
