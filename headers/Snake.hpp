#pragma once
#include <ncurses.h>
#include "Drawable.hpp"
#include <queue>

typedef enum 
{
    UP = 1,
    DOWN = -1,
    LEFT = 2,
    RIGHT = -2
} Direction;

class SnakePiece : public Drawable
{
    private:
    public:
    SnakePiece();

    SnakePiece(int y, int x);
};


class Snake
{
    private:
    std::queue<SnakePiece> prev_pieces_;
    Direction cur_direction_;

    public:
    Snake();

    void addPiece(SnakePiece piece);
 
    void removePiece();

    SnakePiece getTail();

    SnakePiece getHead();

    Direction getDirection();

    void setDirection(Direction dir);

    SnakePiece nextHead();
};