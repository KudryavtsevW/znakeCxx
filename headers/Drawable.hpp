#pragma once
#include <ncurses.h>

class Drawable
{
public:
    Drawable();
    Drawable(int y, int x, char ch);

    int getX();

    int getY();

    char getIcon();

protected:
    int y, x;
    char icon;
};