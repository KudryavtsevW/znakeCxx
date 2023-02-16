#include "../headers/ScoreBoard.hpp"

ScoreBoard::ScoreBoard()
{

}

ScoreBoard::ScoreBoard(int width, int y, int x)
{
    scoreWin_ = newwin(1, width, y, x);
}

void ScoreBoard::U_initialize(int initial_score)
{
    U_clear();
    mvwprintw(scoreWin_, 0, 0, "Score: ");
    updateScore(initial_score);
    U_refresh();
}

void ScoreBoard::updateScore(int score)
{
    mvwprintw(scoreWin_, 0, scoreWin_->_maxx - 10, "%11d", score); // печатаестя справа налево
    //mvwprintw(scoreWin_, 0, scoreWin_->_maxx - 10, "%d", score); будет печататься слева направо 
}

void ScoreBoard::U_clear()
{
    wclear(scoreWin_);
}

void ScoreBoard::U_refresh()
{
    wrefresh(scoreWin_);
}