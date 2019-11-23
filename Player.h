//Bradley McFadden
//SN 0370776

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Board.h"
class Player{
protected:
    std::string m_name;
public:
    Player(const std::string &name): m_name(name){}
    virtual Move makeMove(const Board &gameBoard, int player) = 0;
    virtual void placePiece(Board &gameBoard, PlayerPiece which, int player) = 0;
    const std::string& getName()const noexcept{ return m_name; }
};
#endif
