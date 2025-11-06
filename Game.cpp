#include "Game.h"
#include <iostream>

Game::Game() : starter(&p1) {}

void Game::deal_phase_cards() {
    p1.clear_hand();
    p2.clear_hand();
    // Deal 5 cards from the deck
    for (int i = 0; i < 5; ++i) {
        p1.add_card(deck.deal_card());
        p2.add_card(deck.deal_card());
    }
}

bool Game::determine_round_winner(const Card& p1_card, const Card& p2_card) {
    const Card& first_card = (starter == &p1) ? p1_card : p2_card;
    const Card& second_card = (starter == &p1) ? p2_card : p1_card;

    // Rule 6c: If the second player has no card of the same type, he needs to play some other card and lose
    if (!second_card.follows_suit(first_card)) {
        std::cout << "  Rule 6c applied: The second player (" << get_suit_str(second_card.suit) 
             << ") did not follow the suit (" << get_suit_str(first_card.suit) << ") and loses." << std::endl;
        return starter == &p1; 
    }

    // Rule 6b: The highest card wins (if suits match)
    return p1_card > p2_card;
}

void Game::run() {
    std::cout << "--- Card Game Started! ---" << std::endl;
    
    deck.shuffle_deck(); 

    for (int phase = 1; phase <= 2; ++phase) {
        std::cout << "\n\n<<< --- PHASE " << phase << " STARTS (5 ROUNDS) --- >>>" << std::endl;
        
        deal_phase_cards();
        
        int round_in_phase = 1;
        
        while (p1.has_cards() && p2.has_cards()) {
            std::cout << "\n===================================" << std::endl;
            std::cout << "            Round " << (phase - 1) * 5 + round_in_phase << std::endl;
            std::cout << "===================================" << std::endl;

            Card card1, card2;
            Player* winner = nullptr;
            Card dummy_card = {Rank::SIX, Suit::HEARTS}; // Dummy for starter check
            
            if (starter == &p1) {
                card1 = p1.play_card(dummy_card, true, false);
                p1.remove_card(card1);
                card2 = p2.play_card(card1, false, p2_just_won);
                p2.remove_card(card2);
            } else {
                card2 = p2.play_card(dummy_card, true, p2_just_won);
                p2.remove_card(card2);
                card1 = p1.play_card(card2, false, false);
                p1.remove_card(card1);
            }

            // Display cards played
            std::cout << "> " << p1.get_name() << " played: " << get_card_str(card1) << std::endl;
            std::cout << "> " << p2.get_name() << " played: " << get_card_str(card2) << std::endl;

            if (determine_round_winner(card1, card2)) {
                winner = &p1;
            } else {
                winner = &p2;
            }
            
            std::cout << std::endl;
            if (winner == &p1) {
                std::cout << "+++ " << p1.get_name() << " won this round! +++" << std::endl;
                p1_score++;
                starter = &p1;      
                p2_just_won = false;
            } else {
                std::cout << "--- " << p2.get_name() << " won this round! ---" << std::endl;
                p2_score++;
                starter = &p2;      
                p2_just_won = true; 
            }
            
            std::cout << "Current Score: " << p1.get_name() << " (" << p1_score << ") - " << p2.get_name() << " (" << p2_score << ")" << std::endl;
            round_in_phase++;
        }

        std::cout << "\n<<< --- PHASE " << phase << " ENDS --- >>>" << std::endl;
    }

    // --- Game Summary ---
    std::cout << "\n===================================" << std::endl;
    std::cout << "           ** GAME OVER **" << std::endl;
    std::cout << "Final Score: " << p1.get_name() << " (" << p1_score << ") - " << p2.get_name() << " (" << p2_score << ")" << std::endl;

    if (p1_score > p2_score) {
        std::cout << "*** Congratulations! You are the ultimate winner! ***" << std::endl;
    } else if (p2_score > p1_score) {
        std::cout << "*** The computer is the ultimate winner! ***" << std::endl;
    } else {
        std::cout << "*** It's a tie game! ***" << std::endl;
    }
}