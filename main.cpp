#include <iostream>
#include "headers/board.hpp"
#include "headers/snakeGame.hpp"
#define BOARD_ROWS 20
#define BOARD_COLS BOARD_ROWS*2.5
int main(int argc, char **argv)
{
    initscr();
    refresh();
    noecho();
    curs_set(0); //hide cursor
    SnakeGame game(BOARD_ROWS, BOARD_COLS);
    while(!game.isOver())
    {
        //1: get input from keyboard
        game.processInput();

        //2: update game state
        game.updateState();

        //3: redraw display
        game.U_redraw();

        //4: go to 1 step or game over
    }
    

    
    endwin();
    return 0;
}