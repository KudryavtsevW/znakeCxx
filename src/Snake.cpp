#include "../headers/Snake.hpp"

SnakePiece::SnakePiece()
{
    this->x = this->y = 0;
    this->icon = '*';
}

SnakePiece::SnakePiece(int y, int x)
{
    this->y = y;
    this->x = x;
    this->icon = '*';
}



Snake::Snake()
{
    cur_direction_ = DOWN;
}

void Snake::addPiece(SnakePiece piece)
{
    prev_pieces_.push(piece);
}

void Snake::removePiece()
{
    prev_pieces_.pop();
}

SnakePiece Snake::getTail()
{
    return prev_pieces_.front();
}

SnakePiece Snake::getHead()
{
    return prev_pieces_.back();
}

Direction Snake::getDirection()
{
    return cur_direction_;
}

void Snake::setDirection(Direction dir)
{
    if(cur_direction_ + dir != 0)
    cur_direction_ = dir;
}

SnakePiece Snake::nextHead()
{
    int row = getHead().getY();
    int col = getHead().getX();

        switch(cur_direction_)
        {
            case DOWN:
            row++;
            break;
            case UP:
            row--;
            break;
            case LEFT:
            col--;
            break;
            case RIGHT:
            col++;
            break;
        }

        return SnakePiece(row, col);
}