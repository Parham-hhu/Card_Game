#include "Player.h"
#include <algorithm>

// --- Player Base Class Definitions ---

Player::Player(std::string n) : name(n) {}

void Player::add_card(const Card& card) {
    hand.push_back(card);
}

void Player::clear_hand() {
    hand.clear();
}

void Player::remove_card(const Card& card) {
    
    auto it = std::find_if(hand.begin(), hand.end(), [&](const Card& c) {
        return c.rank == card.rank && c.suit == card.suit;
    });
    if (it != hand.end()) {
        hand.erase(it);
    }
}

bool Player::has_cards() const {
    return !hand.empty();
}

std::string Player::get_name() const {
    return name;
}

const std::vector<Card>& Player::get_hand() const {
    return hand;
}