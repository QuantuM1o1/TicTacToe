#include <iostream>

#include "Grid.h"
#include "Player.h"

int main()
{
    int choice;
    char playAgain = 'n';
    do
    {
        Grid* newGrid = new Grid;
        Player* player1 = new Player;
        Player* player2 = new Player;
        bool swapped = false;
        do
        {
            std::cout << "Choose game mode: " << std::endl;
            std::cout << "    1. Player vs CPU" << std::endl;
            std::cout << "    2. Player vs Player" << std::endl;
            std::cout << "    3. CPU vs CPU" << std::endl;
            std::cout << "Your decision:" << std::endl;
            std::cin >> choice;
        } while (choice < 1 || choice > 3);
        switch (choice)
        {
        case(1):
            player2->makeCPU();
            do
            {
                std::cout << "Do you want to have first turn? " << std::endl;
                std::cout << "    1. Yes" << std::endl;
                std::cout << "    2. No" << std::endl;
                std::cout << "Your decision:" << std::endl;
                std::cin >> choice;
            } while (choice < 1 || choice > 2);
            if (choice == 2)
            {
                std::swap(player1, player2);
                swapped = true;
            }
            break;
        case(2):
            break;
        case(3):
            player1->makeCPU();
            player2->makeCPU();
            break;
        }
        do
        {
            std::cout << "Select size of a field: " << std::endl;
            std::cout << "    3. 3x3" << std::endl;
            std::cout << "    5. 5x5" << std::endl;
            std::cout << "Your decision:" << std::endl;
            std::cin >> choice;
        } while (choice != 3 && choice != 5);
        newGrid->setDimension(choice);
        do
        {
            std::cout << "Do you want to play as: " << std::endl;
            std::cout << "    1. X" << std::endl;
            std::cout << "    2. O" << std::endl;
            std::cout << "Your decision:" << std::endl;
            std::cin >> choice;
        } while (choice < 1 || choice > 2);
        if (choice == 1 && !swapped)
        {
            player1->setChar('X');
            player2->setChar('O');
        }
        else if (choice == 1 && swapped)
        {
            player1->setChar('O');
            player2->setChar('X');
        }
        else if (choice == 2 && !swapped)
        {
            player1->setChar('O');
            player2->setChar('X');
        }
        else
        {
            player1->setChar('X');
            player2->setChar('O');
        }
        newGrid->currentSituation();
        int move;
        while (!newGrid->xWon() && !newGrid->oWon())
        {
            if (player1->isCPU())
            {
                move = player1->makeMoveAsCPU(newGrid, *player2);
                newGrid->setMark(player1->getChar(), move);
                if (newGrid->noRoom())
                {
                    break;
                }
            }
            else
            {
                std::cout << "Player 1, it's your turn" << std::endl;
                move = player1->makeMove(newGrid);
                newGrid->setMark(player1->getChar(), move);
                if (newGrid->noRoom())
                {
                    break;
                }
            }
            newGrid->currentSituation();
            if (newGrid->xWon())
            {
                break;
            }
            if (newGrid->oWon())
            {
                break;
            }
            std::cout << "Next turn" << std::endl;
            if (player2->isCPU())
            {
                move = player2->makeMoveAsCPU(newGrid, *player1);
                newGrid->setMark(player2->getChar(), move);
            }
            else
            {
                std::cout << "Player 2, it's your turn" << std::endl;
                move = player2->makeMove(newGrid);
                newGrid->setMark(player2->getChar(), move);
            }
            newGrid->currentSituation();
            std::cout << "Next turn" << std::endl;
        }
        newGrid->currentSituation();
        if (newGrid->xWon())
        {
            std::cout << "X won" << std::endl;
        }
        else if (newGrid->oWon())
        {
            std::cout << "O won" << std::endl;
        }
        else
        {
            std::cout << "It's a draw" << std::endl;
        }
        do
        {
            std::cout << "Do you want to play again? " << std::endl;
            std::cout << "    y. Yes" << std::endl;
            std::cout << "    n. No" << std::endl;
            std::cout << "Your decision:" << std::endl;
            std::cin >> playAgain;
        } while (playAgain != 'y' && playAgain != 'n');
        delete newGrid;
        delete player1;
        delete player2;
    } while (playAgain == 'y');
}