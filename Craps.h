//
// Created by Luke Cunningham on 1/13/23.
//

#ifndef UNTITLED_CRAPS_H
#define UNTITLED_CRAPS_H
#include <iostream>
using namespace std;

class Craps {
public:
    Craps();
    ~Craps();

    const static int PLAYER_WIN = 1;
    const static int HOUSE_WIN = 0;

    void rollDice();
    int checkWinner();
    void resetGame();

private:
    const static int DICE_DOTS = 18;
    const static int DICE_MIN = 1;
    const static int DICE_MAX = 6;
    int _firstWinningNumbers[2] = {7, 11};
    int _firstLosingNumbers[3] = {2, 3, 12};
    char _diceGrid[DICE_DOTS]{};
    int _diceOne{};
    int _diceTwo{};
    int _rollCount;
    int _diceSum{};
    int _point{};

    void _drawDice();
    void _updateDice();
};

#endif //UNTITLED_CRAPS_H
