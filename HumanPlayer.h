//Bradley McFadden
//SN 0370776

#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H
#include "Player.h"
#include <regex>
#include <sstream>
class HumanPlayer: public Player{
protected:
public:
    HumanPlayer(const std::string name): Player(name){}
    Move makeMove(const Board &game, int player) override;
    void placePiece(Board &gameBoard, PlayerPiece which, int player) override;
    ~HumanPlayer() override{};
};
#endif
