#pragma once
#include <ncurses.h>
class ScoreBoard
{
    private:
    WINDOW* scoreWin_;
    public:
    ScoreBoard();


    ScoreBoard(int width, int y, int x);

    void U_initialize(int initial_score);

    void updateScore(int score);

    void U_clear();

    void U_refresh();
};