//Bradley McFadden
//SN 0370776
#ifndef RANDOM_PLAYER_H
#define RANDOM_PLAYER_H
#include "ComputerPlayer.h"
#include <ctime>
#include <random>
class RandomPlayer: public ComputerPlayer{
	mt19937_64 random;
public:
	Move makeMove(const Board &game): override;
};
#endif
