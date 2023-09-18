#include <iostream>
#include <vector>
#include <iomanip>

class Grid
{
private:
    int dimension = 1;
    std::vector<std::vector<char>> vector;
public:
    void setDimension(int x)
    {
        dimension = x;
        createVector();
    }
    int getDimension()
    {
        return dimension;
    }
    void createVector()
    {
        int num = 1;
        for (int i = 0; i < dimension; i++)
        {
            std::vector<char> innerVector;
            for (int j = 0; j < dimension; j++)
            {
                innerVector.push_back(num);
                num++;
            }
            vector.push_back(innerVector);
        }
    }
    //checks if the board full
    bool noRoom()
    {
        for (int i = 0; i < dimension * dimension; i++)
        {
            if ((this->checkSquare(i + 1) == 'X') || (this->checkSquare(i + 1) == 'O'))
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    //prints a board
    void currentSituation()
    {
        for (int i = 0; i < dimension; i++)
        {
            for (int j = 0; j < dimension; j++)
            {
                std::cout << "--------";
            }
            std::cout << std::endl;
            for (int j = 0; j < dimension; j++)
            {
                if (vector[i][j] == 'X' || vector[i][j] == 'O')
                {
                    std::cout << "|  " << std::setw(2) << vector[i][j] << "  |";
                }
                else
                {
                    std::cout << "|  " << std::setw(2) << int(vector[i][j]) << "  |";
                }
            }
            std::cout << std::endl;
            for (int j = 0; j < dimension; j++)
            {
                std::cout << "--------";
            }
            std::cout << std::endl;
        }
    }
    bool xWon()
    {
        int count;
        for (int i = 0; i < dimension; i++)
        {
            count = 0;
            for (int j = 0; j < dimension; j++)
            {
                if (vector[i][j] == 'X')
                {
                    count++;
                }
            }
            if (count == dimension)
            {
                return true;
            }
        }
        for (int i = 0; i < dimension; i++)
        {
            count = 0;
            for (int j = 0; j < dimension; j++)
            {
                if (vector[j][i] == 'X')
                {
                    count++;
                }
            }
            if (count == dimension)
            {
                return true;
            }
        }
        count = 0;
        for (int i = 0; i < dimension; i++)
        {
            if (vector[i][i] == 'X')
            {
                count++;
            }
            if (count == dimension)
            {
                return true;
            }
        }
        count = 0;
        for (int i = 0; i < dimension; i++)
        {
            int j = dimension - 1 - i;
            if (vector[i][j] == 'X')
            {
                count++;
            }
            if (count == dimension)
            {
                return true;
            }
        }
        return false;
    }
    bool oWon()
    {
        int count;
        for (int i = 0; i < dimension; i++)
        {
            count = 0;
            for (int j = 0; j < dimension; j++)
            {
                if (vector[i][j] == 'O')
                {
                    count++;
                }
            }
            if (count == dimension)
            {
                return true;
            }
        }
        for (int i = 0; i < dimension; i++)
        {
            count = 0;
            for (int j = 0; j < dimension; j++)
            {
                if (vector[j][i] == 'O')
                {
                    count++;
                }
            }
            if (count == dimension)
            {
                return true;
            }
        }
        count = 0;
        for (int i = 0; i < dimension; i++)
        {
            if (vector[i][i] == 'O')
            {
                count++;
            }
            if (count == dimension)
            {
                return true;
            }
        }
        count = 0;
        for (int i = 0; i < dimension; i++)
        {
            int j = dimension - 1 - i;
            if (vector[i][j] == 'O')
            {
                count++;
            }
            if (count == dimension)
            {
                return true;
            }
        }
        return false;
    }
    char checkSquare(int x)
    {
        x--;
        return vector[x / dimension][x % dimension];
    }
    void setMark(char c, int x)
    {
        x--;
        vector[x / dimension][x % dimension] = c;
    }
    int checkRow(char c1, char c2)
    {
        int count;
        for (int i = 0; i < dimension; i++)
        {
            count = 0;
            for (int j = 0; j < dimension; j++)
            {
                if (vector[i][j] == c2)
                {
                    count--;
                }
                if (vector[i][j] == c1)
                {
                    count++;
                }
            }
            if (count == (dimension - 1))
            {
                return i;
            }
        }
        return -1;
    }
    int checkPossibleRow(char c1, char c2)
    {
        bool count;
        for (int i = 0; i < dimension; i++)
        {
            count = false;
            for (int j = 0; j < dimension; j++)
            {
                if (vector[i][j] == c2)
                {
                    count = false;
                    break;
                }
                if (vector[i][j] == c1)
                {
                    count = true;
                }
            }
            if (count)
            {
                return i;
            }
        }
        return -1;
    }
    int checkUnoccupiedRow(char c)
    {
        bool count;
        for (int i = 0; i < dimension; i++)
        {
            count = true;
            for (int j = 0; j < dimension; j++)
            {
                if (vector[i][j] == c)
                {
                    count = false;
                    break;
                }
            }
            if (count)
            {
                return i;
            }
        }
        return -1;
    }
    int checkColumn(char c1, char c2)
    {
        int count;
        for (int i = 0; i < dimension; i++)
        {
            count = 0;
            for (int j = 0; j < dimension; j++)
            {
                if (vector[j][i] == c2)
                {
                    count--;
                }
                if (vector[j][i] == c1)
                {
                    count++;
                }
            }
            if (count == (dimension - 1))
            {
                return i;
            }
        }
        return -1;
    }
    int checkPossibleColumn(char c1, char c2)
    {
        bool count;
        for (int i = 0; i < dimension; i++)
        {
            count = false;
            for (int j = 0; j < dimension; j++)
            {
                if (vector[j][i] == c2)
                {
                    count = false;
                    break;
                }
                if (vector[j][i] == c1)
                {
                    count = true;
                }
            }
            if (count)
            {
                return i;
            }
        }
        return -1;
    }
    int checkUnoccupiedColumn(char c)
    {
        bool count;
        for (int i = 0; i < dimension; i++)
        {
            count = true;
            for (int j = 0; j < dimension; j++)
            {
                if (vector[j][i] == c)
                {
                    count = false;
                    break;
                }
            }
            if (count)
            {
                return i;
            }
        }
        return -1;
    }
    bool checkMainDiagonal(char c1, char c2)
    {
        int count = 0;
        for (int i = 0; i < dimension; i++)
        {
            if (vector[i][i] == c2)
            {
                count--;
            }
            if (vector[i][i] == c1)
            {
                count++;
            }
        }
        if (count == dimension - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool checkPossibleMainDiagonal(char c1, char c2)
    {
        int count = 0;
        for (int i = 0; i < dimension; i++)
        {
            if (vector[i][i] == c2)
            {
                return false;
            }
            if (vector[i][i] == c1)
            {
                count++;
            }
        }
        if (count != 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool checkUnoccupiedMainDiagonal(char c)
    {
        bool count = true;
        for (int i = 0; i < dimension; i++)
        {
            if (vector[i][i] == c)
            {
                count = false;
                break;
            }
        }
        if (count)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool checkSecondDiagonal(char c1, char c2)
    {
        int count = 0;
        for (int i = 0; i < dimension; i++)
        {
            int j = dimension - 1 - i;
            if (vector[i][j] == c2)
            {
                count--;
            }
            if (vector[i][j] == c1)
            {
                count++;
            }
        }
        if (count == dimension - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool checkPossibleSecondDiagonal(char c1, char c2)
    {
        int count = 0;
        for (int i = 0; i < dimension; i++)
        {
            int j = dimension - 1 - i;
            if (vector[i][j] == c2)
            {
                return false;
            }
            if (vector[i][j] == c1)
            {
                count++;
            }
        }
        if (count != 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool checkUnoccupiedSecondDiagonal(char c)
    {
        bool count = true;
        for (int i = 0; i < dimension; i++)
        {
            int j = dimension - 1 - i;
            if (vector[i][j] == c)
            {
                count = false;
                break;
            }
        }
        if (count)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //puts mark in a first free square of a particular row
    int putCharInRow(int x)
    {
        for (int i = 0; i < dimension; i++)
        {
            if ((vector[x][i] != 'X') && (vector[x][i] != 'O'))
            {
                return i + 1 + x * dimension;
            }
        }
    }
    //puts mark in a first free square of a particular column
    int putCharInColumn(int x)
    {
        for (int i = 0; i < dimension; i++)
        {
            if ((vector[i][x] != 'X') && (vector[i][x] != 'O'))
            {
                return (i * dimension + x + 1);
            }
        }
    }
    //puts mark in a first free square of a main diagonal
    int putCharInMainDiagonal()
    {
        for (int i = 0; i < dimension; i++)
        {
            if ((vector[i][i] != 'X') && (vector[i][i] != 'O'))
            {
                return (i + 1 + i * dimension);
            }
        }
    }
    //puts mark in a first free square of a second diagonal
    int putCharInSecondDiagonal()
    {
        for (int i = 0; i < dimension; i++)
        {
            int j = dimension - 1 - i;
            if ((vector[i][j] != 'X') && (vector[i][j] != 'O'))
            {
                return (i * dimension + j + 1);
            }
        }
    }
    bool atleastOneInRow(int x, char c)
    {
        for (int i = 0; i < dimension; i++)
        {
            if (vector[x][i] == c)
            {
                return true;
            }
        }
        return false;
    }
    bool atleastOneInColumn(int x, char c)
    {
        for (int i = 0; i < dimension; i++)
        {
            if (vector[i][x] == c)
            {
                return true;
            }
        }
        return false;
    }
    //checks top left corner
    int checkCorner1(char c1, char c2)
    {
        if ((vector[0][0] != c1) && (vector[0][0] != c2) && !this->atleastOneInRow(0, c2) && !this->atleastOneInColumn(0, c2))
        {
            return 1;
        }
        else if ((vector[0][0] == c1) && !this->atleastOneInRow(0, c2) && (this->checkSquare(dimension) != c1))
        {
            return dimension;
        }
        else if ((vector[0][0] == c1) && !this->atleastOneInColumn(0, c2) && (this->checkSquare(dimension * dimension - dimension + 1) != c1))
        {
            return dimension * dimension - dimension + 1;
        }
        else
        {
            return -1;
        }
    }
    //checks top right corner
    int checkCorner2(char c1, char c2)
    {
        if ((vector[0][dimension - 1] != c1) && (vector[0][dimension - 1] != c2) && !this->atleastOneInRow(dimension - 1, c2) && !this->atleastOneInColumn(0, c2))
        {
            return dimension;
        }
        else if ((vector[0][dimension - 1] == c1) && !this->atleastOneInRow(0, c2) && (this->checkSquare(1) != c1))
        {
            return 1;
        }
        else if ((vector[0][dimension - 1] == c1) && !this->atleastOneInColumn(dimension - 1, c2) && (this->checkSquare(dimension * dimension) != c1))
        {
            return dimension * dimension;
        }
        else
        {
            return -1;
        }
    }
    //checks bottom left corner
    int checkCorner3(char c1, char c2)
    {
        if ((vector[dimension - 1][0] != c1) && (vector[dimension - 1][0] != c2) && !this->atleastOneInRow(0, c2) && !this->atleastOneInColumn(dimension - 1, c2))
        {
            return dimension * dimension - dimension + 1;
        }
        else if ((vector[dimension - 1][0] == c1) && !this->atleastOneInRow(dimension - 1, c2) && (this->checkSquare(dimension * dimension) != c1))
        {
            return dimension * dimension;
        }
        else if ((vector[dimension - 1][0] == c1) && !this->atleastOneInColumn(0, c2) && (this->checkSquare(1) != c1))
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    //checks bottom right corner
    int checkCorner4(char c1, char c2)
    {
        if ((vector[dimension - 1][dimension - 1] != c1) && (vector[dimension - 1][dimension - 1] != c2) && !this->atleastOneInRow(dimension - 1, c2) && !this->atleastOneInColumn(dimension - 1, c2))
        {
            return dimension * dimension;
        }
        else if ((vector[dimension - 1][dimension - 1] == c1) && !this->atleastOneInRow(dimension - 1, c2) && (this->checkSquare(dimension * dimension - dimension + 1) != c1))
        {
            return dimension * dimension - dimension + 1;
        }
        else if ((vector[dimension - 1][dimension - 1] == c1) && !this->atleastOneInColumn(dimension - 1, c2) && (this->checkSquare(dimension) != c1))
        {
            return dimension;
        }
        else
        {
            return -1;
        }
    }
};

class Player
{
protected:
    char marks = 'O';
    bool CPU = false;
public:
    bool isCPU()
    {
        return CPU;
    }
    void makeCPU()
    {
        CPU = true;
    }
    void setChar(char c)
    {
        this->marks = c;
    }
    char getChar()
    {
        return marks;
    }
    int makeMoveAsCPU(Grid grid, Player secondPlayer)
    {
        int x;
        //checking central square
        if (grid.checkSquare((grid.getDimension() * grid.getDimension() + 1) / 2) == (grid.getDimension() * grid.getDimension() + 1) / 2)
        {
            return ((grid.getDimension() * grid.getDimension() + 1) / 2);
        }
        //check if can win this turn
        else if (grid.checkRow(marks, secondPlayer.marks) != -1)
        {
            x = grid.checkRow(marks, secondPlayer.marks);
            return grid.putCharInRow(x);
        }
        else if (grid.checkColumn(marks, secondPlayer.marks) != -1)
        {
            x = grid.checkColumn(marks, secondPlayer.marks);
            return grid.putCharInColumn(x);
        }
        else if (grid.checkMainDiagonal(marks, secondPlayer.marks))
        {
            return grid.putCharInMainDiagonal();
        }
        else if (grid.checkSecondDiagonal(marks, secondPlayer.marks))
        {
            return grid.putCharInSecondDiagonal();
        }
        //check if we can lose this turn
        else if (grid.checkRow(secondPlayer.marks, marks) != -1)
        {
            x = grid.checkRow(secondPlayer.marks, marks);
            return grid.putCharInRow(x);
        }
        else if (grid.checkColumn(secondPlayer.marks, marks) != -1)
        {
            x = grid.checkColumn(secondPlayer.marks, marks);
            return grid.putCharInColumn(x);
        }
        else if (grid.checkMainDiagonal(secondPlayer.marks, marks))
        {
            return grid.putCharInMainDiagonal();
        }
        else if (grid.checkSecondDiagonal(secondPlayer.marks, marks))
        {
            return grid.putCharInSecondDiagonal();
        }
        //check corners
        else if (grid.checkCorner1(marks, secondPlayer.marks) != -1)
        {
            return grid.checkCorner1(marks, secondPlayer.marks);
        }
        else if (grid.checkCorner2(marks, secondPlayer.marks) != -1)
        {
            return grid.checkCorner2(marks, secondPlayer.marks);
        }
        else if (grid.checkCorner3(marks, secondPlayer.marks) != -1)
        {
            return grid.checkCorner3(marks, secondPlayer.marks);
        }
        else if (grid.checkCorner4(marks, secondPlayer.marks) != -1)
        {
            return grid.checkCorner4(marks, secondPlayer.marks);
        }
        //check possible wins
        else if (grid.checkPossibleRow(secondPlayer.marks, marks) != -1)
        {
            x = grid.checkPossibleRow(secondPlayer.marks, marks);
            return grid.putCharInRow(x);
        }
        else if (grid.checkPossibleColumn(secondPlayer.marks, marks) != -1)
        {
            x = grid.checkPossibleColumn(secondPlayer.marks, marks);
            return grid.putCharInColumn(x);
        }
        else if (grid.checkPossibleMainDiagonal(secondPlayer.marks, marks))
        {
            return grid.putCharInMainDiagonal();
        }
        else if (grid.checkPossibleSecondDiagonal(secondPlayer.marks, marks))
        {
            return grid.putCharInSecondDiagonal();
        }
        //check for an unoccupied 
        else if (grid.checkUnoccupiedRow(secondPlayer.marks) != -1)
        {
            x = grid.checkUnoccupiedRow(secondPlayer.marks);
            return grid.putCharInRow(x);
        }
        else if (grid.checkUnoccupiedColumn(secondPlayer.marks) != -1)
        {
            x = grid.checkUnoccupiedColumn(secondPlayer.marks);
            return grid.putCharInColumn(x);
        }
        else if (grid.checkUnoccupiedMainDiagonal(secondPlayer.marks))
        {
            return grid.putCharInMainDiagonal();
        }
        else if (grid.checkUnoccupiedSecondDiagonal(secondPlayer.marks))
        {
            return grid.putCharInSecondDiagonal();
        }
        else
        {
            for (int i = 1; i <= (grid.getDimension() * grid.getDimension()); i++)
            {
                if ((grid.checkSquare(i) != 'X') && (grid.checkSquare(i) != 'O'))
                {
                    return i;
                }
            }
        }
    }
    int makeMove(Grid grid)
    {
        int x;
        do
        {
            std::cin >> x;
        } while (x < 1 || x >(grid.getDimension() * grid.getDimension()) || grid.checkSquare(x) == 'X' || grid.checkSquare(x) == 'O');
        return x;
    }
};

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
        if (!player1->isCPU())
        {

        }
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
                move = player1->makeMoveAsCPU(*newGrid, *player2);
                newGrid->setMark(player1->getChar(), move);
                if (newGrid->noRoom())
                {
                    break;
                }
            }
            else
            {
                std::cout << "Player 1, it's your turn" << std::endl;
                move = player1->makeMove(*newGrid);
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
                move = player2->makeMoveAsCPU(*newGrid, *player1);
                newGrid->setMark(player2->getChar(), move);
            }
            else
            {
                std::cout << "Player 2, it's your turn" << std::endl;
                move = player2->makeMove(*newGrid);
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