#pragma once
#include "Settings.h"
#include "SaveLoad.h"
#include <setjmp.h>

using namespace std;
jmp_buf buf;

int check_move() {
    //Check if selected column is full or not

    if (my_game.mat[0][my_game.cho] != ' ') {
        return true;
    }
    else {
        return false;
    }
}

void choose() {
    //Choose columns for drop a disc

    while (true) {
        int temp;
        cout << "Enter the '0' to open the menu." << endl;
        cout << "Player " << my_game.disc << " please choose a column: ";
        cin >> temp;
        my_game.cho = temp - 1;
        if (temp == 0) {
            int menu;
            label:
            cout << "1. Back to the main menu" << endl;
            cout << "2. Save current game" << endl;
            cout << "3. Continue current game" << endl;
            cout << "::::::";
            cin >> menu;
            if (menu == 1) {
                system("CLS");
                longjmp(buf, 1);
            }
            else if (menu == 2) {
                saveSettings();
                saveGame();
                continue;
            }
            else if (menu == 3) {
                continue;
            }
            else {
                cout << "Please enter a valid number!" << endl;
                goto label;
            }
        }
        if (my_game.cho < 0) {
            cout << "Invalid column! Please choose again." << endl;
            continue;
        }
        else if (my_game.cho >= my_game.cols) {
            cout << "Invalid column! Please choose again." << endl;
            continue;
        }
        else if (check_move()) {
            cout << "This column is full! Please choose another column." << endl;
            continue;
        }
        else {
            break;
        }
    }

}

void apply_move() {
    //Drop the disc on the selected column

    if (my_game.mat[0][my_game.cho] == ' ') {
        for (int up = my_game.rows - 1; up >= 0; up--) {
            if (my_game.mat[up][my_game.cho] == ' ') {
                my_game.mat[up][my_game.cho] = my_game.disc;
                break;
            }
        }
        if (my_game.turn % 2 == 0) {
            my_game.disc = 'Y';
        }
        else {
            my_game.disc = 'R';
        }
    }
}