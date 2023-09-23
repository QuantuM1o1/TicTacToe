#include <iostream>

#include "Player.h"

    Player::Player()
    {
        marks = 'O';
        CPU = false;
    }
    bool Player::isCPU()
    {
        return CPU;
    }
    void Player::makeCPU()
    {
        CPU = true;
    }
    void Player::setChar(char c)
    {
        this->marks = c;
    }
    char Player::getChar()
    {
        return marks;
    }
    int Player::makeMoveAsCPU(Grid* grid, Player secondPlayer)
    {
        int x;
        //checking central square
        if (grid->checkSquare((grid->getDimension() * grid->getDimension() + 1) / 2) == (grid->getDimension() * grid->getDimension() + 1) / 2)
        {
            return ((grid->getDimension() * grid->getDimension() + 1) / 2);
        }
        //check if can win this turn
        if (grid->checkRow(this->marks, secondPlayer.marks) != -1)
        {
            x = grid->checkRow(this->marks, secondPlayer.marks);
            return grid->putCharInRow(x);
        }
        else if (grid->checkColumn(this->marks, secondPlayer.marks) != -1)
        {
            x = grid->checkColumn(this->marks, secondPlayer.marks);
            return grid->putCharInColumn(x);
        }
        else if (grid->checkMainDiagonal(this->marks, secondPlayer.marks))
        {
            return grid->putCharInMainDiagonal();
        }
        else if (grid->checkSecondDiagonal(this->marks, secondPlayer.marks))
        {
            return grid->putCharInSecondDiagonal();
        }
        //check if we can lose this turn
        else if (grid->checkRow(secondPlayer.marks, this->marks) != -1)
        {
            x = grid->checkRow(secondPlayer.marks, this->marks);
            return grid->putCharInRow(x);
        }
        else if (grid->checkColumn(secondPlayer.marks, this->marks) != -1)
        {
            x = grid->checkColumn(secondPlayer.marks, this->marks);
            return grid->putCharInColumn(x);
        }
        else if (grid->checkMainDiagonal(secondPlayer.marks, this->marks))
        {
            return grid->putCharInMainDiagonal();
        }
        else if (grid->checkSecondDiagonal(secondPlayer.marks, this->marks))
        {
            return grid->putCharInSecondDiagonal();
        }
        //check corners
        else if (grid->checkCorner1(this->marks, secondPlayer.marks) != -1)
        {
            return grid->checkCorner1(this->marks, secondPlayer.marks);
        }
        else if (grid->checkCorner2(this->marks, secondPlayer.marks) != -1)
        {
            return grid->checkCorner2(this->marks, secondPlayer.marks);
        }
        else if (grid->checkCorner3(this->marks, secondPlayer.marks) != -1)
        {
            return grid->checkCorner3(this->marks, secondPlayer.marks);
        }
        else if (grid->checkCorner4(this->marks, secondPlayer.marks) != -1)
        {
            return grid->checkCorner4(this->marks, secondPlayer.marks);
        }
        //check possible wins
        else if (grid->checkPossibleRow(this->marks, secondPlayer.marks) != -1)
        {
            x = grid->checkPossibleRow(this->marks, secondPlayer.marks);
            return grid->putCharInRow(x);
        }
        else if (grid->checkPossibleColumn(this->marks, secondPlayer.marks) != -1)
        {
            x = grid->checkPossibleColumn(this->marks, secondPlayer.marks);
            return grid->putCharInColumn(x);
        }
        else if (grid->checkPossibleMainDiagonal(this->marks, secondPlayer.marks))
        {
            return grid->putCharInMainDiagonal();
        }
        else if (grid->checkPossibleSecondDiagonal(this->marks, secondPlayer.marks))
        {
            return grid->putCharInSecondDiagonal();
        }
        //check for an unoccupied 
        else if (grid->checkUnoccupiedRow(secondPlayer.marks) != -1)
        {
            x = grid->checkUnoccupiedRow(secondPlayer.marks);
            return grid->putCharInRow(x);
        }
        else if (grid->checkUnoccupiedColumn(secondPlayer.marks) != -1)
        {
            x = grid->checkUnoccupiedColumn(secondPlayer.marks);
            return grid->putCharInColumn(x);
        }
        else if (grid->checkUnoccupiedMainDiagonal(secondPlayer.marks))
        {
            return grid->putCharInMainDiagonal();
        }
        else if (grid->checkUnoccupiedSecondDiagonal(secondPlayer.marks))
        {
            return grid->putCharInSecondDiagonal();
        }
        else
        {
            for (int i = 1; i <= (grid->getDimension() * grid->getDimension()); i++)
            {
                if ((grid->checkSquare(i) != 'X') && (grid->checkSquare(i) != 'O'))
                {
                    return i;
                }
            }
        }
    }
    int Player::makeMove(Grid* grid)
    {
        int x;
        do
        {
            std::cin >> x;
        } while (x < 1 || x >(grid->getDimension() * grid->getDimension()) || grid->checkSquare(x) == 'X' || grid->checkSquare(x) == 'O');
        return x;
    }
