#include "Deck.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <stdexcept>

Deck::Deck() {
    // Build the full 20-card deck
    for (int s = static_cast<int>(Suit::HEARTS); s <= static_cast<int>(Suit::CLUBS); ++s) {
        for (int r = static_cast<int>(Rank::SIX); r <= static_cast<int>(Rank::TEN); ++r) {
            cards.push_back({static_cast<Rank>(r), static_cast<Suit>(s)});
        }
    }
}

void Deck::shuffle_deck() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));
}

Card Deck::deal_card() {
    if (cards.empty()) {
        throw std::runtime_error("Deck is empty!");
    }
    Card card = cards.back();
    cards.pop_back();
    return card;
}

bool Deck::is_empty() const {
    return cards.empty();
}