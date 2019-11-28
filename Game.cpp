//Bradley McFadden
//SN 0370776

#include "Game.h"

//Destructor
Game::~Game(){
    if (m_p1)
        delete m_p1;
    if (m_p2)
        delete m_p2;
}

//Collects the types for each player from the user
//then also collects names for human players.
//It then initializes p1 and p2.
void Game::selectPlayers(){
    size_t p1_type;
    do {
        std::cout << "Enter the type for player one"
            << "(1-human, 2-comp): ";
        std::cin >> p1_type;
        std::cin.ignore(30000, '\n');
    } while(p1_type != 1 && p1_type != 2);

    size_t p2_type;
    do {
        std::cout << "Enter the type for player two"
            << "(1-human, 2-comp): ";
        std::cin >> p2_type;
        std::cin.ignore(30000, '\n');
    } while(p2_type != 1 && p2_type != 2);

    std::string name;
    if (p1_type == 1){
        std::cout << "Enter a name for player one: ";
        std::getline(std::cin, name);
        m_p1 = new HumanPlayer(name);
    } else {
        m_p1 = new RandomPlayer();
    }

    if (p2_type == 1){
        std::cout << "Enter a name for player two: ";
        std::getline(std::cin, name);
        m_p2 = new HumanPlayer(name);
    } else {
        m_p2 = new RandomPlayer();
    }
    std::cout << '\n';
}

//Place the pieces for each player and ensure they are valid
void Game::placePieces(){
    std::cout << m_p1->getName() << " is placing a Patrol Boat(length 2).\n";
    m_p1->placePiece(m_game, PlayerPiece::PATROL_BOAT, 1);
    std::cout << m_p1->getName() << " is placing a Submarine(length 3).\n";
    m_p1->placePiece(m_game, PlayerPiece::SUBMARINE, 1);
    std::cout << m_p1->getName() << " is placing a Destroyer(length 3).\n";
    m_p1->placePiece(m_game, PlayerPiece::DESTROYER, 1);
    std::cout << m_p1->getName() << " is placing a Battleship(length 4).\n";
    m_p1->placePiece(m_game, PlayerPiece::BATTLESHIP, 1);
    std::cout << m_p1->getName() << " is placing a Carrier(length 5).\n";
    m_p1->placePiece(m_game, PlayerPiece::CARRIER, 1);

    std::cout << m_p2->getName() << " is placing a Patrol Boat(length 2).\n";
    m_p2->placePiece(m_game, PlayerPiece::PATROL_BOAT, 2);
    std::cout << m_p2->getName() << " is placing a Submarine(length 3).\n";
    m_p2->placePiece(m_game, PlayerPiece::SUBMARINE, 2);
    std::cout << m_p2->getName() << " is placing a Destroyer(length 3).\n";
    m_p2->placePiece(m_game, PlayerPiece::DESTROYER, 2);
    std::cout << m_p2->getName() << " is placing a Battkeship(length 4).\n";
    m_p2->placePiece(m_game, PlayerPiece::BATTLESHIP, 2);
    std::cout << m_p2->getName() << " is placing a Carrier(length 5).\n";
    m_p2->placePiece(m_game, PlayerPiece::CARRIER, 2);
}

//Returns a pointer to the player
//whose move it currently is
//<return> Player* of player whose turn it is
Player* Game::nextPlayer() const{
    if (m_p1Turn)
        return m_p1;
    else
        return m_p2;
}

//The main game loop, call this to play the game until
//someone has won
void Game::play(){
    while (isRunning()){
        int player = m_p1Turn == 1 ? 1 : 2;
        m_game.display(player);
        std::string name = m_p1Turn == 1 ? m_p1->getName() : m_p2->getName();
        std::cout << '\n' << "It's " << name << "'s turn.\n";
        EnemyPiece result;
        if (player == 1){
            result = m_game.makeMove(m_p1->makeMove(m_game, player), player);
        } else {

            result = m_game.makeMove(m_p2->makeMove(m_game, player), player);
        }
        if (result == EnemyPiece::HIT){
            std::cout << "That move was a hit!\n";
            player == 1 ? ++m_p1Hits : ++m_p2Hits;
        } else if (result == EnemyPiece::MISS){
            std::cout << "That move missed!\n";
        } else {
            std::cout << "Not sure what that was\n";
        }
        m_p1Turn = !m_p1Turn;
    }
}

//If there is a winner, announce them with their associated name
void Game::announceWinner(){
    std::string name;
    if (m_p1Hits == 17){
        name = m_p1->getName();
    }else if (m_p2Hits == 17){
        name = m_p2->getName();
    }else{
        std::cout << "announceWinner called without a winner.";
        return;
    }
    std::cout << "The winner is: " << name << "!\nCongratulations!\n";
}

//Returns false if either player has not got 17( 2 + 3 + 3 + 4 + 5 )
//hits on the other player's ship.
//<return> True if a player has won, else false.
bool Game::isRunning(){
    return m_p1Hits < 17 && m_p2Hits < 17;
}
