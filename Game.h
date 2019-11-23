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
    bool m_p1Turn = true;
    size_t m_p1Hits = 0;
    size_t m_p2Hits = 0;
public:
    Game():m_p1(nullptr), m_p2(nullptr), m_game(), m_p1Turn(true), m_p1Hits(0), m_p2Hits(0){}
    ~Game();
    void selectPlayers();
    void placePieces();
    Player* nextPlayer() const;
    void play();
    void announceWinner();
    bool isRunning();	
};
#endif
