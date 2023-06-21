#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Settings.h"

using namespace std;

void saveSettings() {

    ofstream file("saveSettings.cpp");

    if (file.is_open()) {

        file << my_game.cols << endl;
        file << my_game.rows << endl;
        file << my_game.turn << endl;
        file << my_game.wins << endl;
        file << my_game.disc << endl;
        file.close();
        cout << "Game Saved!" << endl;

    }
    else {
        cout << "Game could not be saved!!" << endl;
    }

}

void saveGame() {
    ofstream save("save.cpp");

    if (save.is_open()) {
        for (const auto& row : my_game.mat) {
            for (size_t i = 0; i < row.size(); ++i) {
                if (row[i] == ' ') {
                    save << "0";
                }
                else {
                    save << row[i];
                }
            }
            save << "\n";
        }
        save.close();
    }

}


void loadSettings() {
    ifstream loadS("saveSettings.cpp");
    if (!loadS) {
        cout << "File is broken!!" << endl;
    }

    vector<int> settings;
    vector<char> disc;

    int num;
    char dsc;
    int line = 0;
    while (line<5 && loadS >> num) {
        settings.push_back(num);
        line++;

        if (line == 4) {
            while (loadS >> dsc) {
                disc.push_back(dsc);
            }
        }
    }

    my_game.cols = settings[0];
    my_game.rows = settings[1];
    my_game.turn = settings[2];
    my_game.wins = settings[3];
    my_game.disc = disc[0];

    loadS.close();
}

void loadGame() {
    ifstream load("save.cpp");
    vector<vector<char>> tempvec;

    if (load.is_open()) {
        vector<char> row;
        char element;
        while (load >> element) {
            if (element == '0') {
                row.push_back(' ');
            }
            else {
                row.push_back(element);
            }
            if (load.peek() == '\n') {
                tempvec.push_back(row);
                row.clear();
            }
        }
        load.close();
    }
    my_game.mat = tempvec;

}