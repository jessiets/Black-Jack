# The Game of Black Jack
### _Let's play Black Jack with the computer!_
This program is a virtual stimulation of the game - Twenty One. 
<br>
<br>
<br>
## About
<li>The game allows one player to play against the dealer (computer). <br>
<li>Normal black jack rules apply. <br>
<li>The program will print out the game result along with the final scores. 

## Rules
<li> Goal: <br> Player should aim to have their cards total more than the dealer's without going over 21, 
                which is called a "bust". The value of each card corresponds to its number value, whereas Jacks, Queens, 
                and Kings have a value of 10. Aces are special cards, it can either have a value of 1 or 11, the value 
                depending on whether the total card value would still be within 21 after the addition of ace. In other 
                words, if ace with a value of 11 will cause the player's hand to "bust," ace will automatically be 
                counted as a value of 1.
<li> Setup:<br> 
                This program uses one deck of playing cards (52 cards). The player and dealer will each 
                randomly get 2 cards. All of the player's cards will be visible on the screen, but the dealer will only
                reveal one card and keep the other one hidden from the player.
<li> How to Play:   <br>
                The player has two options in each round: to "stand" or to "hit." Stand is equivalent
                to passing the current round, not asking for another card. Hit is to ask for another card. As stated, the 
                goal of the player is to get closer to 21 but not over 21. Once the player chooses to "stand," the dealer
                starts to play. The dealer's hidden card is now revealed. The dealer must continue to take a card until 
                the total is 17 or more, at which point the dealer must "stand." Now, this is the point where whoever has
                the highest score wins.
               
<li> How does the game end: <br>
If player goes bust, the game immediately ends and the dealer wins. <br>
If dealer goes bust, the game immediately ends and the player wins. <br>
If both the player and the dealer called to "stand" and both are still under value of 21, compare the points and the person with
the higher total point value is the winner.


## Implementation
<li> for loops and while loops
<li> conditional statements
<li> function prototypes, function definitions, function calls, passing parameters
<li> array, array search
<li> clear, table formatted output
