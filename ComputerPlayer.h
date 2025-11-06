#pragma once

#include "Player.h"

class ComputerPlayer : public Player {
private:
    Card find_sacrificial_card();
    
public:
    ComputerPlayer();
    Card play_card(const Card& first_card, bool is_starter, bool just_won) override;
};