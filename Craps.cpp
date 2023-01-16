//
// Created by Luke Cunningham on 1/13/23.
//

#include "Craps.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Craps::Craps() {
    for (char & i : _diceGrid) {
        i = ' ';
    }
    _rollCount = 0;
}

Craps::~Craps() = default;

void Craps::rollDice() {
    _rollCount++;
    srand(time(nullptr));
    _diceOne = DICE_MIN + rand() % DICE_MAX;
    _diceTwo = DICE_MIN + rand() % DICE_MAX;
    cout << _diceOne << " " << _diceTwo << "\n";
    _diceSum = _diceOne + _diceTwo;

    if (_rollCount == 1) {
        _point = _diceSum;
    }
    _drawDice();
}

void Craps::_drawDice() {
    _updateDice();
    cout << "-----------   -----------\n";
    cout <<"|";
    for (int i = 0; i < DICE_DOTS; i++) {
        cout << " " << _diceGrid[i] << " ";
        if ((i + 1) % 3 == 0 && i != 0 && (i + 2) % 2 == 0) {
            cout << "|   |";
        }
        if ((i + 1) % 3 == 0 && i != 0 && (i + 2) % 2 == 1) {
            cout << "|";
        }
        if ((i + 1) % 6 == 0 && i != 0 && i != 17) {
            cout << "\n|";
        }
    }
    cout << "\n-----------   -----------\n";
}

void Craps::_updateDice() {
    for (char & i : _diceGrid) {
        i = ' ';
    }
    for (int i = 0; i < _diceOne; i++) {
        if  (_diceOne == 1) {
            _diceGrid[0] = 'O';
        }
        if  (_diceOne == 2) {
            _diceGrid[0] = 'O';
            _diceGrid[14] = 'O';
        }
        if  (_diceOne == 3) {
            _diceGrid[0] = 'O';
            _diceGrid[7] = 'O';
            _diceGrid[14] = 'O';
        }
        if  (_diceOne == 4) {
            _diceGrid[0] = 'O';
            _diceGrid[2] = 'O';
            _diceGrid[12] = 'O';
            _diceGrid[14] = 'O';
        }
        if  (_diceOne == 5) {
            _diceGrid[0] = 'O';
            _diceGrid[2] = 'O';
            _diceGrid[7] = 'O';
            _diceGrid[12] = 'O';
            _diceGrid[14] = 'O';
        }
        if  (_diceOne == 6) {
            _diceGrid[0] = 'O';
            _diceGrid[2] = 'O';
            _diceGrid[6] = 'O';
            _diceGrid[8] = 'O';
            _diceGrid[12] = 'O';
            _diceGrid[14] = 'O';
        }
    }
    for (int i = 0; i < _diceTwo; i++) {
        if  (_diceTwo == 1) {
            _diceGrid[3] = 'O';
        }
        if  (_diceTwo == 2) {
            _diceGrid[3] = 'O';
            _diceGrid[17] = 'O';
        }
        if  (_diceTwo == 3) {
            _diceGrid[3] = 'O';
            _diceGrid[10] = 'O';
            _diceGrid[17] = 'O';
        }
        if  (_diceTwo == 4) {
            _diceGrid[3] = 'O';
            _diceGrid[5] = 'O';
            _diceGrid[15] = 'O';
            _diceGrid[17] = 'O';
        }
        if  (_diceTwo == 5) {
            _diceGrid[3] = 'O';
            _diceGrid[5] = 'O';
            _diceGrid[10] = 'O';
            _diceGrid[15] = 'O';
            _diceGrid[17] = 'O';
        }
        if  (_diceTwo == 6) {
            _diceGrid[3] = 'O';
            _diceGrid[5] = 'O';
            _diceGrid[9] = 'O';
            _diceGrid[11] = 'O';
            _diceGrid[15] = 'O';
            _diceGrid[17] = 'O';
        }
    }
}

int Craps::checkWinner() {
    if (_rollCount == 1) {
        if (std::find(std::begin(_firstWinningNumbers), std::end(_firstWinningNumbers),
                      _diceSum) != std::end(_firstWinningNumbers)) {
            return PLAYER_WIN;
        }
        if (std::find(std::begin(_firstLosingNumbers), std::end(_firstLosingNumbers),
                      _diceSum) != std::end(_firstLosingNumbers)) {
            return HOUSE_WIN;
        }

    } else {
        if (_diceSum == _point) {
            return PLAYER_WIN;
        }
        if (_diceSum == 7){
            return HOUSE_WIN;
        }
    }
    return -1;
}

void Craps::resetGame() {
    _rollCount = 0;
    _point = 0;
}