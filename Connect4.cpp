#include <iostream>
#include <windows.h>
#include "Menu.h"
#include "Settings.h"
#include "Board.h"
#include "Choose.h"
#include "Finish.h"
#include "Play.h"

using namespace std;

int main() {

    setjmp(buf);
    menu();
    custom_col();
    custom_row();
    custom_win();
    fill_board();
    board();
    setjmp(cont);
    play();

}