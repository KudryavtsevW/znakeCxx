#include <../headers/snakeGame.hpp>

SnakeGame::SnakeGame(int height, int width) // main controller
{
    board_ = new Board(height, width);
    scoreBoard_ = ScoreBoard(width,board_->getStartRow()+ height, board_->getStartCol());
    U_initialize();
}

void SnakeGame::U_initialize()
{
    apple_ = NULL;
    board_->U_initialize(); // initialize board
    game_over_ = false;
    srand(time(NULL)); // for rand()
    score_ = 0;
    scoreBoard_.U_initialize(score_);
    snake_.setDirection(DOWN);
    handleNextPece(SnakePiece(1,1));
    handleNextPece(snake_.nextHead());
    handleNextPece(snake_.nextHead());
    snake_.setDirection(RIGHT);
    handleNextPece(snake_.nextHead());

    if (!apple_)
    {
        createApple();
    }
}
void SnakeGame::processInput()
{
    chtype input = board_->getInput();

    switch (input)
    {
    case KEY_UP:
    //case 'w':
        snake_.setDirection(UP);
        break;

    case KEY_DOWN:   
    //case 's':
        snake_.setDirection(DOWN);
        break;

    case KEY_RIGHT:
    //case 'd':
        snake_.setDirection(RIGHT);
        break;

    case KEY_LEFT:
    //case 'a':
        snake_.setDirection(LEFT);
        break;
    case 'p':
        board_->setTimeout(-1);//бесконечно ожидает ввода клавиши
        while (board_->getInput() != 'p')
        {

        }
        board_->setTimeout(TIMEOUT);
        break;
    default:
        break;
    }
}

void SnakeGame::updateState()
{

    handleNextPece(snake_.nextHead());

    if (!apple_)
    {
        createApple();
    }
}

void SnakeGame::U_redraw()
{
    board_->U_refresh();
    scoreBoard_.U_refresh();
    napms(100);
    //refresh();
}

bool SnakeGame::isOver()
{
    return game_over_;
}

void SnakeGame::createApple()
{
    int y, x;
    board_->getEmptyCoordinates(y, x); // получение участка поля с пустыми координатами
    apple_ = new Apple(y, x);
    board_->add(*apple_);
}

void SnakeGame::handleNextPece(SnakePiece next)
{
    if(apple_)
    {
        switch (board_->getCharAt(next.getY(), next.getX()))
        {
        case 'A':
            eatApple();
            break;
        case ' ':
        {
            int emptyRow = snake_.getTail().getY();
            int emptyCol = snake_.getTail().getX();
            board_->add(Empty(emptyRow, emptyCol));
            snake_.removePiece();
            break;
        }
        default:
            game_over_ = true;
            break;
        }
    }

    board_->add(next);
    snake_.addPiece(next);
}

void SnakeGame::eatApple()
{
    delete apple_;
    apple_ = NULL;
    score_+=10;
    scoreBoard_.updateScore(score_);
    
}