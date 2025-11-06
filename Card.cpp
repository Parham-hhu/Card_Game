#include "Card.h"
#include <sstream>
#include <stdexcept>

// --- Helper Function Definitions ---

std::string get_rank_str(Rank r) {
    switch (r) {
        case Rank::SIX: return "6";
        case Rank::SEVEN: return "7";
        case Rank::EIGHT: return "8";
        case Rank::NINE: return "9";
        case Rank::TEN: return "10";
    }
    return "?";
}

std::string get_suit_str(Suit s) {
    switch (s) {
        case Suit::CLUBS: return "Clubs";
        case Suit::DIAMONDS: return "Diamonds";
        case Suit::HEARTS: return "Hearts";
        case Suit::SPADES: return "Spades";
    }
    return "?";
}

std::string get_card_str(const Card& c) {
    return get_rank_str(c.rank) + " of " + get_suit_str(c.suit);
}

// --- Card Comparison Definitions ---

bool Card::operator>(const Card& other) const {
    if (rank != other.rank) {
        return rank > other.rank;
    }
    return suit > other.suit;
}

bool Card::operator<(const Card& other) const {
    if (rank != other.rank) {
        return rank < other.rank;
    }
    return suit < other.suit;
}