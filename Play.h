#pragma once
#include <iostream>
#include <windows.h>
#include "Menu.h"
#include "Settings.h"
#include "Board.h"
#include "Choose.h"
#include "Finish.h"

void play() {

    while (true) {
        cout << "Player " << my_game.disc << " your turn!" << endl;
        choose();
        apply_move();
        system("CLS");
        board();
        if (finish('R')) {
            printf("\033[0;31m");
            cout << "Player Red win!" << endl;
            printf("\033[0;37m");
            exit(0);
        }
        if (finish('Y')) {
            printf("\033[0;33m");
            cout << "Player Yellow win!" << endl;
            printf("\033[0;37m");
            exit(0);
        }
        if (my_game.turn == (my_game.rows * my_game.cols)) {
            printf("\033[1;34m");
            cout << "Draw!!" << endl;
            printf("\033[0;37m");
            exit(0);
        }
        my_game.turn = my_game.turn + 1;
    }
}