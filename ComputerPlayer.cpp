#include "ComputerPlayer.h"
#include <iostream>
#include <algorithm>
#include <vector>

// --- ComputerPlayer Definitions ---

ComputerPlayer::ComputerPlayer() : Player("Computer ") {}

Card ComputerPlayer::find_sacrificial_card() {
    // Helper for Rule 6c sacrifice logic: find the lowest card based on Rank/Suit priority
    Card best_sacrifice = hand[0];
    for (const auto& card : hand) {
        if (card < best_sacrifice) { 
            best_sacrifice = card;
        }
    }
    return best_sacrifice;
}


 
Card ComputerPlayer::play_card(const Card& first_card, bool is_starter, bool just_won) /* Removed 'override' here */ {
    using namespace std; 
    
    // 1. Rule 8: If computer just won, play the highest card available.
    if (just_won) {
        Card highest_card = hand[0];
        for(const auto& card : hand) {
            if (card > highest_card) {
                highest_card = card;
            }
        }
        cout << "  (Rule 8: Computer just won, playing its highest card: " << get_card_str(highest_card) << ")" << endl;
        return highest_card;
    }
    
    // 2. Starter Logic: If starting the round and didn't win last time, sacrifice the lowest card.
    if (is_starter) { 
        cout << "  (Computer starts and didn't win last round, sacrificing a low card)" << endl;
        return find_sacrificial_card();
    }
    
    // 3. Following Player Logic (Rules 6a, 6b, 6c)
    
    vector<Card> matching_suit;
    for (const auto& card : hand) {
        if (card.follows_suit(first_card)) { 
            matching_suit.push_back(card);
        }
    }
    
    // Rule 6a: Must play same type if available
    if (!matching_suit.empty()) {
        // Find lowest card higher than the played card (to win)
        Card best_winning_card = {Rank::TEN, Suit::CLUBS}; 
        bool can_win = false;

        for (const auto& card : matching_suit) {
            if (static_cast<int>(card.rank) > static_cast<int>(first_card.rank)) {
                // Rule 6b: Find the LOWEST card that can win
                if (card < best_winning_card) { 
                    best_winning_card = card;
                    can_win = true;
                }
            }
        }

        if (can_win) {
            cout << "  (Rule 6b: Computer attempts to win with the lowest card higher than leading card)" << endl;
            return best_winning_card;
        }
        
        // If it can't win, sacrifice the lowest card of the matching suit
        Card lowest_card_of_suit = matching_suit[0];
        for (const auto& card : matching_suit) {
            if (card < lowest_card_of_suit) { 
                lowest_card_of_suit = card;
            }
        }
        cout << "  (Rule 6: Computer cannot win, sacrificing its lowest card of the matching suit)" << endl;
        return lowest_card_of_suit;
    }
    
    // Rule 6c: If no card of the same type, play some other card and lose
    cout << "  (Rule 6c: Computer has no matching suit and loses by sacrificing a low card)" << endl;
    return find_sacrificial_card();
}