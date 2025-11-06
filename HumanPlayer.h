#pragma once

#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer();
    Card play_card(const Card& first_card, bool is_starter, bool just_won) override;
};