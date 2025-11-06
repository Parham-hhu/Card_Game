#pragma once

#include <vector>
#include <string>
#include "Card.h" 

class Player {
protected:
    std::vector<Card> hand;
    std::string name;
    
public:
    Player(std::string n);
    virtual ~Player() = default;

    void add_card(const Card& card);
    void clear_hand();
    void remove_card(const Card& card);

    virtual Card play_card(const Card& first_card, bool is_starter, bool just_won) = 0;

    bool has_cards() const;
    std::string get_name() const;
    const std::vector<Card>& get_hand() const;
};