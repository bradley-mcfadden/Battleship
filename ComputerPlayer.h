//Bradley McFadden
//SN 0370776

#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H
#include "Player.h"
class ComputerPlayer: public Player{
protected:
    const std::string NAME_PREFIX = "Computer ";
    static char m_letter;
public:
    ComputerPlayer():Player(NAME_PREFIX + m_letter){
        m_letter = m_letter < 'Z' ? m_letter + 1 : 'Z';
    }
};
#endif
