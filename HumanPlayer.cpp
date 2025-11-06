#include "HumanPlayer.h"
#include <iostream>
#include <limits> // Included limits for cin.ignore

HumanPlayer::HumanPlayer() : Player("You ") {}

// FIX: Removed 'override' keyword from the function definition signature
Card HumanPlayer::play_card(const Card& first_card, bool is_starter, bool just_won) /* Removed 'override' here */ {
    using namespace std; 

    cout << "\n--- " << name << "'s Hand ---" << endl;
    for (size_t i = 0; i < hand.size(); ++i) {
        cout << i + 1 << ") " << get_card_str(hand[i]) << endl;
    }
    cout << "----------------------" << endl;

    if (!is_starter) {
        cout << "The leading card is: " << get_card_str(first_card) << ". Try to follow suit (" << get_suit_str(first_card.suit) << ")." << endl;
    }
    
    int choice_index = -1;
    while (choice_index < 1 || choice_index > (int)hand.size()) {
        cout << "Select card number to play (1 to " << hand.size() << "): ";
        cin >> choice_index;
        
        if (cin.fail() || choice_index < 1 || choice_index > (int)hand.size()) {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice_index = -1;
        }
    }
    return hand[choice_index - 1];
}