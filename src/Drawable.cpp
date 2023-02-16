#include <../headers/Drawable.hpp>

Drawable::Drawable()
{
    y = x = 6;
    icon = ' ';

}
Drawable::Drawable(int y, int x, char ch)
{
    this->y = y;
    this->x = x;
    this->icon = ch;
}

int Drawable::getX()
{
    return x;
}

int Drawable::getY()
{
    return y;
}

char Drawable::getIcon()
{
    return icon;
}

