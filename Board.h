#pragma once
#include "Settings.h"

void fill_board() {
    //Fill the board with blanks
    vector<vector<char>> vec(my_game.rows, vector<char>(my_game.cols, ' '));
    my_game.mat = vec;
}

void board() {
    //Print the board

    vector<int> head(my_game.cols);
    for (int id = 0; id < my_game.cols; id++) {
        head[id] = id + 1;
    }
    cout << "   ";
    for (int id = 0; id < (int)head.size(); id++) {
        cout << head[id] << "   ";
    }
    cout << endl;
    for (int i = 0; i < my_game.rows; i++) {
        for (int j = 0; j < my_game.cols; j++) {
            cout << " | ";
            if (my_game.mat[i][j] == 'R') {
                printf("\033[0;31m");
                cout << my_game.mat[i][j];
                printf("\033[0;37m");
            }
            else if (my_game.mat[i][j] == 'Y') {
                printf("\033[0;33m");
                cout << my_game.mat[i][j];
                printf("\033[0;37m");
            }
            else {
                cout << my_game.mat[i][j];
            }

        }
        cout << " |" << endl;
        cout << " |";
        for (int j = 0; j < my_game.cols; j++) {

            cout << "===";
            cout << "|";
        }
        cout << endl;
    }
}