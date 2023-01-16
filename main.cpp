#include "Craps.h"
#include <iostream>
using namespace std;

int main() {
    Craps game;
    cout << "Welcome to vegas!\n";

    bool keepPlaying = true;
    while (keepPlaying) {
        bool rollAgain = true;
        game.rollDice();

        while (rollAgain) {
            if (game.checkWinner() == Craps::PLAYER_WIN) {
                cout << "You have won!\n";
                rollAgain = false;
            }
            if (game.checkWinner() == Craps::HOUSE_WIN) {
                cout << "You have lost!\n";
                rollAgain = false;
            }

            if (rollAgain) {
                cout << "Press space bar to continue rolling (or q to quit): ";
                char response;
                cin >> response;
                while (response != 'q' || response != ' ') {
                    cout << "You entered an invalid response: " << response << ". Please press your space bar to "
                                                                               "continue playing or enter q to quit: ";
                    cin >> response;
                }
                if (response == 'q') {
                    cout << "Thanks for playing!";
                    break;
                }
                game.rollDice();
            }
        }

        cout << "Would you like to play again? Enter (y or n): ";
        char response;
        cin >> response;
        while (response != 'y' || response != 'n') {
            cout << "You entered an invalid response: " << response << ". Please enter y to play another round or"
                                                                       "n to leave the table: ";
            cin >> response;
        }
        if (response == 'n') {
            cout << "Thanks for playing!";
            break;
        }
        game.resetGame();
    }
}
