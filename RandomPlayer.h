//Bradley McFadden
//SN 0370776

#ifndef RANDOM_PLAYER_H
#define RANDOM_PLAYER_H
#include "ComputerPlayer.h"
#include <ctime>
#include <random>
#include <vector>
class RandomPlayer: public ComputerPlayer{
    std::mt19937 m_random;
    std::vector<size_t> m_unused;
public:
    RandomPlayer(): ComputerPlayer(), m_random(time(NULL)){
        reset();
    }
    Move makeMove(const Board &gameBoard, int player) override;
    void placePiece(Board &gameBoard, PlayerPiece which, int player) override;
    void reset();
    ~RandomPlayer() override{};
};
#endif
