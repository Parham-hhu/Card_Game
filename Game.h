#pragma once

#include "Deck.h"
#include "Player.h"           
#include "HumanPlayer.h"      
#include "ComputerPlayer.h"   
#include <iostream>

class Game {
private:
    Deck deck;
    HumanPlayer p1;          
    ComputerPlayer p2;        
    Player* starter; 
    int p1_score = 0;
    int p2_score = 0;
    bool p2_just_won = false; 

    void deal_phase_cards();
    bool determine_round_winner(const Card& p1_card, const Card& p2_card);

public:
    Game();
    void run();
};