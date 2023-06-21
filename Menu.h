#pragma once
#include <iostream>
#include <setjmp.h>
#include "Board.h"
#include "SaveLoad.h"
#include "Play.h"

using namespace std;
jmp_buf cont;

void menu() {
    char game;
    cout << " @@@@@    @@@@@    @@    @   @@    @   @@@@@@    @@@@@   @@@@@@@       @" << endl;
    cout << "@        @     @   @ @   @   @ @   @   @        @           @         @@" << endl;
    cout << "@        @     @   @  @  @   @  @  @   @@@@@@   @           @        @ @" << endl;
    cout << "@        @     @   @   @ @   @   @ @   @        @           @       @@@@@" << endl;
    cout << " @@@@@    @@@@@    @    @@   @    @@   @@@@@@    @@@@@      @          @" << endl;
    cout << "Welcome CONNECT 4 Game!!" << endl;
    cout << "Please enter 'P' for play game!" << endl;
    cout << "Please enter 'Q' for quit!" << endl;
    cout << "::::";
    cin >> game;

    while (true) {
        
        if (game == 'P' || game == 'p') {
        empty:
            int sl;
            cout << "1. Continue Game" << endl;
            cout << "2. New Game" << endl;
            cout << "3. Load Game" << endl;
            cout << "0. Quit" << endl;
            cout << "::::::";
            cin >> sl;

            if (sl == 1) {
                if (my_game.turn == 1) {
                    cout << "There is no game!" << endl;
                    cout << "Choose again!" << endl;
                    goto empty;
                }
                else {
                    board();
                    longjmp(cont, 1);
                }

            }

            else if (sl == 2) {
                break;
            }

            else if (sl == 3) {
                system("CLS");
                loadGame();
                loadSettings();
                board();
                play();
            }

            else if (sl == 0) {
                exit(0);
            }

            else {
                cout << "Invalid input! Please enter an acceptable number!" << endl;
                goto empty;
            }
        }
        else if (game == 'Q' || game == 'q') {
            exit(0);
        }
        else {
            cout << "Invalid input! Please enter an acceptable character!" << endl;
        }
    }
}
