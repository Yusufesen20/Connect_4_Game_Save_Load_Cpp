#pragma once
#include "Settings.h"

int finish(char pop) {
    int r, c, t, counter;
    // Check Rows
    int row_ways = my_game.cols - my_game.wins + 1;
    for (r = 0; r < my_game.rows; ++r) {
        for (c = 0; c < row_ways; ++c) {
            counter = 0;
            for (t = 0; t < my_game.wins; ++t) {
                if (my_game.mat[r][c + t] == pop) {
                    counter++;
                }
            }
            if (counter == my_game.wins) {
                return true;
            }
        }
    }


    // Check Columns
    int col_ways = 1 + (my_game.rows - my_game.wins);
    for (c = 0; c < my_game.cols; ++c) {
        for (r = 0; r < col_ways; ++r) {
            counter = 0;
            for (t = 0; t < my_game.wins; ++t) {
                if (my_game.mat[r + t][c] == pop) {
                    counter++;
                }
            }
            if (counter == my_game.wins) {
                return true;
            }
        }
    }


    //Check positive diagonals
    vector<char> pdwin;
    for (r = my_game.rows - 1; r >= 0; r--) {
        for (c = 0; c < my_game.cols; c++) {
            for (t = 1; t < my_game.wins; t++) {
                if (r - t < 0 || c + t > my_game.cols - 1) {
                    continue;
                }
                else {
                    if (my_game.mat[r][c] == my_game.mat[r - t][c + t] && my_game.mat[r][c] == pop) {
                        pdwin.push_back(pop);
                        if (pdwin.size() >= my_game.wins - 1) {
                            return 1;
                        }
                    }
                }
            }
            pdwin.clear();
        }
    }

    //Check negative diagonals
    vector<char> ndwin;
    for (r = 0; r < my_game.rows; r++) {
        for (c = 0; c < my_game.cols; c++) {
            for (t = 1; t < my_game.wins; t++) {
                if (r + t > my_game.rows - 1 || c + t > my_game.cols - 1) {
                    continue;
                }
                else {
                    if (my_game.mat[r][c] == my_game.mat[r + t][c + t] && my_game.mat[r][c] == pop) {
                        ndwin.push_back(pop);
                        if (ndwin.size() >= my_game.wins - 1) {
                            return 1;
                        }
                    }
                }
            }
            ndwin.clear();
        }
    }
    return 0;
}
