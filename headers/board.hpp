#pragma once
#include <ncurses.h>
#include <stdlib.h>
#include "Drawable.hpp"

#define TIMEOUT 0
class Board
{
    private:
    WINDOW* board_win_;
    int height_, width_, startRow_, startCol_;

    int timeout;
    public:
    Board(int height, int width);
    void U_initialize();
    void addBorder(); //по идее очищаем окно, а границы должны остаться
    void U_clear(); //clear window
    void U_refresh();
    void add(Drawable drawable);
    void addAt(int x, int y, char ch);//Добавить символ в х у
    void getEmptyCoordinates(int &y, int &x);//Получить координаты пустого метса на поле
    void setTimeout(int timeout);
    chtype getCharAt(int y, int x); //collision
    chtype getInput();
    WINDOW* getBoard();

    int getStartRow();
    int getStartCol();



    



    
};