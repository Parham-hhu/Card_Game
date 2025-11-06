# Card_Game
Simplified Card Game (OOP Implementation)

 * Project: Simplified Card Game (OOP Implementation)
 * Author: Parham Jalali
 * Date: November 2025
 * * Description: 
 * This program implements a two-player (Human vs. Computer) card game 
 * with a simplified 20-card deck (Ranks 6-10, 4 Suits). The game is structured 
 * into two 5-round phases, adhering to rules for the computer opponent.
  
    1) cards are numbered from 6 to 10
    2) cards have 4 different „type“ Clubs, Diamonds, Hearts and Spades
    3) At the beginng the cards have to be randomly shuffled
    4) Two players are getting 5 cards each
    5) For the first player player the cards need to be printed to the screen and he can play a card 
        by selecting a number. e.g. „1“ => first card
    6) The second player is the computer with these rules:
    a) Played card must have the same type as the card already played
    b) the highest card wins 
    c) If the second player has no card of the same type, he needs to play some other card and loose
        => computer will always play the lowest card higher than the card played or the lowest card of the same type 
        or if not available choose the card based on number first and then type: Clubs > Spades > Diamonds > Hearts
    7) The winner of each round plays first in the next round until all cards are played
    8) After a win, the computer always plays the highest card available
        => Go back to 5)
