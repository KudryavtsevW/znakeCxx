#pragma once

#include <time.h>
#include <stdlib.h>

#include "board.hpp"
#include "Apple.hpp"
#include "Empty.hpp"
#include "Snake.hpp"
#include "ScoreBoard.hpp"

class SnakeGame
{
    private:
    Board* board_;
    bool game_over_;
    Apple* apple_;
    Snake snake_;
    ScoreBoard scoreBoard_;
    int score_;
    void createApple();

    void handleNextPece(SnakePiece next);//логика для следующего шага
    //передвижение головы

    void eatApple();
    public:
    SnakeGame(int height, int width);

    void U_initialize();

    void processInput();

    void updateState();

    void U_redraw();

    bool isOver();


};