#pragma once
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <ctype.h>

using namespace std;

class Game {
    //These are the variables to be used while playing game
public:
    int cho = 0;
    int turn = 1;
    int wins = 0;
    int rows = 0;
    int cols = 0;
    char disc = 'Y';
    vector<vector<char>> mat = {};
} my_game;

int custom_col() {
    //Input how many columns in game

    int col;
    cout << " Please enter a number greater than 4 for the number of columns: " << endl;
    printf("\033[0;32m");
    cout << "Exp. |=1=|=2=|=3=|=4=|...." << endl;
    printf("\033[0;37m");
    cout << ":::::::";
    cin >> col;
    my_game.cols = col;
    if (col < 4) {
        cout << "Number of columns must be greater than 4!" << endl;
        return custom_col();
    }
    else {
        return col;
    }
}

int custom_row() {
    //Input how many rows in game
    int row = 0;
    cout << " Please enter a number greater than 4 for the number of rows: " << endl;
    printf("\033[0;32m");
    cout << "Exp." << endl;
    cout << "=1=" << endl;
    cout << "=2=" << endl;
    cout << "=3=" << endl;
    cout << "=4=" << endl;
    cout << " . " << endl;
    cout << " . " << endl;
    cout << " . " << endl;
    printf("\033[0;37m");
    cout << ":::::::";
    cin >> row;
    my_game.rows = row;
    if (row < 4) {
        cout << "Number of rows must be greater than 4!" << endl;
        return custom_row();
    }
    else {
        return row;
    }
}

int custom_win() {
    //Input how many discs must be connected for win the game
    
    int win;
    cout << "Please enter the winning condition." << endl;
    printf("\033[0;32m");
    cout << "Tips:" << endl;
    cout << "Must be greater than 4." << endl;
    cout << "Enter an integer less than or equal to the number of rows or columns." << endl;
    cout << "The number of discs cannot exceed the smallest dimension of your board." << endl;
    cout << "E.g.If your board is a 10x12 board, the maximum integer allowed is 10." << endl;
    printf("\033[0;37m");
    cout << "Number of needed connected discs: ";
    cin >> win;
    my_game.wins = win;

    if (my_game.wins < 4) {
        printf("\033[0;31m");
        cout << "Must be greater than 4!" << endl;
        printf("\033[0;37m");
        return custom_win();
    }

    else if (my_game.wins > my_game.rows || my_game.wins > my_game.cols) {
        printf("\033[0;31m");
        cout << "The number of discs cannot exceed the smallest dimension of your board!" << endl;
        cout << " " << endl;
        printf("\033[0;37m");
        return custom_win();            
    }

    else {
        return win;
    }
}

