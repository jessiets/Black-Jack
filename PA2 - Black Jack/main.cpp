//
//  main.cpp
//  PA2 - Black Jack
//
//  Created by Jessie Tsai on 2/16/20.
//  Copyright © 2020 Jessie Tsai. All rights reserved.
//

/*******************************************************************************
 * CS 103 Twenty-One (Blackjack) PA
 * Name: Jessie Tsai
 * USC email: jessiets@usc.edu
 * Comments (you want us to know):
 *
 *
 ******************************************************************************/


/******************************************************************************
 * PSEUDOCODE *
 I. About: Twenty-One Card Game (Black Jack)
    This program will only be one player vs. dealer, no betting.
    Only playing with one deck of cards
 
    Rules: non face-cards (2-10) have the same value
           J, Q, K have a value of 10
           A has default value of 11, but can also be 1
 II.
 
 III. Set up
    1. shuffle cards
    2. deal cards
        * two cards each
        * first card to player, second to dealer, third-player, fourth-dealer
        * dealer's first card is hidden, second is visible
    3. start game
        * player decides to "stand" or "hit"
        * if player "bust," GAME OVER
        * if player "stand," dealer reveal first card
          if total >= 17, dealer must stand
          if total <= 16, dealer must hit
 ******************************************************************************/

// Add other #includes if you need
#include <iostream>
#include <cstdlib>

using namespace std;

/* Prototypes */
void shuffle(int cards[]);
void printCard(int id);
int cardValue(int id);
void printHand(int hand[], int numCards);
int getBestScore(int hand[], int numCards);


const int NUM_CARDS = 52;

/**
 * Global arrays to be used as look-up tables, if desired.
 * It is up to you if and how you want to use these
 */
const char suit[4] = {'H','S','D','C'};
const char* type[13] =
{"2","3","4","5","6","7",
    "8","9","10","J","Q","K","A"};
const int value[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

/**
 * Should permute the deck of cards, effectively shuffling it.
 * You must use the Fisher-Yates / Durstenfeld shuffle algorithm
 * described in the assignment writeup.
 */
void shuffle(int cards[])
{
    /******** You complete ****************/
    int i,j, temp;
    
    //initializing deck to 0-51
    for (i=0; i<52; i++)
        cards[i] = i;
    
    //shuffling cards using Fisher-Yates/Durstenfeld algorithm
    for (i=51; i>0; i--){
        j = rand() % (i+1);
        temp = cards[j];
        cards[j] = cards[i];
        cards[i] = temp;
    }
    
}

/**
 * Prints the card in a "pretty" format:   "type-suit"
 *  Examples:  K-C  (King of clubs), 2-H (2 of hearts)
 *  Valid Types are: 2,3,4,5,6,7,8,9,10,J,Q,K,A
 *  Valid Suits are: H, D, C, S
 */
void printCard(int id)
{
    /******** You complete ****************/
    int num, pattern;
    
    //find correct index for the type
    num = id % 13;
    
    //find correct index for the suit
    if (id >= 0 && id <= 12)
        pattern = 0;
    else
        if (id >= 13 && id <= 25)
            pattern = 1;
        else
            if (id >= 26 && id <= 38)
                pattern = 2;
            else
                if (id >= 39 && id <= 51)
                    pattern = 3;
    
    cout << type[num] << "-" << suit[pattern];
}

/**
 * Returns the numeric value of the card.
 *  Should return 11 for an ACE and can then
 *  be adjusted externally based on the sum of the score.
 */
int cardValue(int id)
{
    /******** You complete ****************/
    //find correct index for the type
    int num;
    num = id % 13;
    
    //return integer card value
    return(value[num]);
}

/**
 * Should print out each card in the hand separated by a space and
 * then print a newline at the end.
 * Should use printCard() to print out each card.
 */
void printHand(int hand[], int numCards)
{
    /******** You complete ****************/
    if(numCards == 1){
        cout << "? ";
        printCard(hand[1]);
        cout << endl;
    }
    
    else{
        for(int i=0; i<numCards; i++){
            printCard(hand[i]);
            cout << " ";
        }
        cout << endl;
    }
}

/**
 * Should return the total score of the provided hand.
 * ACES should be treated as 11s to make the highest possible hand
 *  and only being reduced to 1s as needed to avoid busting.
 */
int getBestScore(int hand[], int numCards)
{
    /******** You complete ****************/
    int score = 0;
    
    for(int i=0; i<numCards; i++){
        score += cardValue(hand[i]);
    }
    
    //if the score is over 21,
    //see if there's an ACE card
    int j = 0;
    while(score>21 && j<numCards){
        if (cardValue(hand[j]) == 11){
            score -= 10;
        }
        j++;
    }
    
    return (score);
    
}


/**
 * Main program logic for the game of 21
 */
int main(int argc, char* argv[])
{
    //---------------------------------------
    // Do not change this code -- Begin
    //---------------------------------------
    if(argc < 2){
        cout << "Error - Please provide the seed value." << endl;
        return 1;
    }
    int seed = atoi(argv[1]);
    srand(seed);
    
    int cards[52];
    int dhand[9];
    int phand[9];
    //---------------------------------------
    // Do not change this code -- End
    //---------------------------------------
    
    /******** You complete ****************/
    char repeat = 'y';
    char user;       //record player response to "hit" or "stand"
    int nextCard;    //stores the position of the next card in deck
    int num_card_p, num_card_d;    //keeps track of the number of hand cards
    int pScore, dScore;
    
    
    while(repeat == 'y'){
        shuffle(cards);        //shuffle deck
        
        /******testing shuffle function******
         for (int i=0; i<52; i++)
         cout << cards[i] << " ";
         *************************************/
        
        /******testing printCard and cardValue functions*****
         int input;
         cout << "Enter id: ";
         cin >> input;
         printCard(input);
         cout << "Value: " << cardValue(input) << endl;
         ****************************************************/
        
        //deal cards (2 cards each)
        for(int c=0, i=0; c<2; c++, i+=2){
            phand[c] = cards[i];
            dhand[c] = cards[i+1];
        }
        nextCard = 4;    //next card in deck is in position 4
        num_card_p = 2;    //player has 2 cards initially
        num_card_d = 2;    //dealer has 2 cards initially
        
        //display initial hand
        cout << "Dealer: ";
        printHand(dhand, 1);
        cout << "Player: ";
        printHand(phand, num_card_p);
        
        //calculate initial scores
        pScore = getBestScore(phand, num_card_p);
        dScore = getBestScore(dhand, num_card_d);
        
        
        //prompt user to start game
        while(pScore < 21){
            cout << "Type 'h' to hit and 's' to stay: " << endl;
            cin >> user;
            
            //if player enters 'h'
            //deal another card and display all cards in hand
            if(user == 'h'){
                phand[num_card_p] = cards[nextCard];
                num_card_p++;
                nextCard++;
                
                cout << "Player: ";
                printHand(phand, num_card_p);
                //cout << endl;
                
                //calculate score of player's hand cards
                pScore = getBestScore(phand, num_card_p);
            }
            //if player enters anyting else, break out of loop
            else
                break;
        };
        
        //if player busts, display "Player busts"
        //else, dealer starts playing
        if (pScore > 21){
            cout << "Player busts" << endl;
            cout << "Lose ";
        }
        else
        {
            while(dScore < 17){
                dhand[num_card_d] = cards[nextCard];
                nextCard++;
                num_card_d++;
                
                dScore = getBestScore(dhand, num_card_d);
            }
            
            
            //display dealer hand
            cout << "Dealer: ";
            printHand(dhand, num_card_d);
            //cout << endl;
            
            //determine if dealer busts
            if(dScore > 21){
                cout << "Dealer busts" << endl;
                cout << "Win ";
            }
            
            //if dealer doesn't bust, determine winner
            else{
                if(pScore > dScore)
                    cout << "Win ";
                else
                    if(pScore < dScore)
                        cout << "Lose ";
                    else
                        cout << "Tie ";
            }
        }
        
        //display final scores
        cout << pScore << " " << dScore << endl;
        
        cout << "\nPlay again? [y/n]" << endl;
        cin >> repeat;
    }
    
    return 0;
}
