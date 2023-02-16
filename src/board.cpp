#include "../headers/board.hpp"
#include "../headers/Drawable.hpp"
    Board::Board(int height, int width)
    {
        int xMax, yMax;
        yMax = getmaxy(stdscr);
        xMax = getmaxx(stdscr);
        this->height_ = height;
        this->width_ = width;

        startRow_ = (yMax/2) - (height/2);//for ScoreBoard
        startCol_ = (xMax/2) - (width/2);//for ScoreBoard

        board_win_ = newwin(height, width, startRow_, startCol_);

        //timeout
        wtimeout(board_win_, TIMEOUT);
        //keyboard
        keypad(board_win_, true);//захват клавиш со стрелками и не только
    }

    void Board::addBorder()
    {
        box(board_win_, 0, 0);
    }

    void Board::U_initialize()
    {
        U_clear();
        U_refresh();
    }

    void Board::getEmptyCoordinates(int &y, int &x)
    {
        while(mvwinch(board_win_, y = rand() % height_, x = rand() % width_) != ' ');
    }

    void Board::U_clear()
    {
        wclear(board_win_);
        addBorder();
    }

    void Board::U_refresh()
    {
        // addBorder();
        wrefresh(board_win_);
        
    }

    void Board::add(Drawable drawable)
    {
        addAt(drawable.getY(), drawable.getX(), drawable.getIcon());
    }

    void Board::addAt(int y, int x, char ch)
    {
        mvwaddch(board_win_, y, x, ch);
    }

    chtype Board::getInput()
    {
        return wgetch(board_win_);
    }

    WINDOW* Board::getBoard()
    {
        return board_win_;
    }

    void Board::setTimeout(int timeout)
    {
        wtimeout(board_win_, timeout);
    }

    chtype Board::getCharAt(int y, int x)//collision
    {
        return mvwinch(board_win_, y, x);
    }

    int Board::getStartCol()
    {
        return startCol_;
    }
    int Board::getStartRow()
    {
        return startRow_;
    }