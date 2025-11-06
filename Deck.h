#pragma once

#include <vector>
#include "Card.h"  

class Deck {
private:
    std::vector<Card> cards;

public:
    Deck();
    void shuffle_deck();
    Card deal_card();
    bool is_empty() const;
};