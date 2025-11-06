#pragma once

#include <string>

// --- Enums ---

enum class Rank : int { SIX = 6, SEVEN, EIGHT, NINE, TEN };
enum class Suit : int { HEARTS = 1, DIAMONDS, SPADES, CLUBS }; 

// --- Struct ---

struct Card {
    Rank rank;
    Suit suit;

    // Comparison operators 
    bool operator>(const Card& other) const;
    bool operator<(const Card& other) const;
    
    // Utility
    bool follows_suit(const Card& other) const {
        return suit == other.suit;
    }
};

// --- Helper Function Declarations ---

std::string get_rank_str(Rank r);
std::string get_suit_str(Suit s);
std::string get_card_str(const Card& c);