//Bradley McFadden
//SN 0370776

#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H
#include "Player.h"
class ComputerPlayer: public Player{
protected:
    static char m_letter;
public:
    ComputerPlayer():Player(std::string("Computer ") + m_letter){
        m_letter = m_letter < 'Z' ? m_letter + 1 : 'Z';
        std::cout << "Hey roboto, my name: " << m_name << "\n";
    }
};
#endif
