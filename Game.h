//Bradley McFadden
//SN 0370776
#ifndef GAME_H
#define GAME_H
#include "RandomPlayer.h"
#include "HumanPlayer.h"
#include "Board.h"
class Game{
	Player *m_p1 = nullptr;
	Player *m_p2 = nullptr;
	Board m_game;
public:
	Game();
	~Game();
	void selectPlayers();
	Player* nextPlayer() const;
	void play();
	void announceWinner();
	bool isRunning();	
};
#endif
