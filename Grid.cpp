#include <iostream>
#include <iomanip>

#include "Grid.h"

    Grid::Grid()
    {
        dimension = 1;
    }
    void Grid::setDimension(int x)
    {
        dimension = x;
        createVector();
    }
    int Grid::getDimension()
    {
        return dimension;
    }
    void Grid::createVector()
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
    bool Grid::noRoom()
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
    void Grid::currentSituation()
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
    bool Grid::xWon()
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
    bool Grid::oWon()
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
    char Grid::checkSquare(int position)
    {
        position--;
        return vector[position / dimension][position % dimension];
    }
    void Grid::setMark(char mark, int position)
    {
        position--;
        vector[position / dimension][position % dimension] = mark;
    }
    int Grid::checkRow(char c1, char c2)
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
    int Grid::checkPossibleRow(char c1, char c2)
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
    int Grid::checkUnoccupiedRow(char c)
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
    int Grid::checkColumn(char c1, char c2)
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
    int Grid::checkPossibleColumn(char c1, char c2)
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
    int Grid::checkUnoccupiedColumn(char c)
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
    bool Grid::checkMainDiagonal(char c1, char c2)
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
    bool Grid::checkPossibleMainDiagonal(char c1, char c2)
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
    bool Grid::checkUnoccupiedMainDiagonal(char c)
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
    bool Grid::checkSecondDiagonal(char c1, char c2)
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
    bool Grid::checkPossibleSecondDiagonal(char c1, char c2)
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
    bool Grid::checkUnoccupiedSecondDiagonal(char c)
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
    int Grid::putCharInRow(int x)
    {
        for (int i = 0; i < dimension; i++)
        {
            if ((vector[x][i] != 'X') && (vector[x][i] != 'O'))
            {
                return i + 1 + x * dimension;
            }
        }
        return -1;
    }
    int Grid::putCharInColumn(int x)
    {
        for (int i = 0; i < dimension; i++)
        {
            if ((vector[i][x] != 'X') && (vector[i][x] != 'O'))
            {
                return (i * dimension + x + 1);
            }
        }
        return -1;
    }
    int Grid::putCharInMainDiagonal()
    {
        for (int i = 0; i < dimension; i++)
        {
            if ((vector[i][i] != 'X') && (vector[i][i] != 'O'))
            {
                return (i + 1 + i * dimension);
            }
        }
        return -1;
    }
    int Grid::putCharInSecondDiagonal()
    {
        for (int i = 0; i < dimension; i++)
        {
            int j = dimension - 1 - i;
            if ((vector[i][j] != 'X') && (vector[i][j] != 'O'))
            {
                return (i * dimension + j + 1);
            }
        }
        return -1;
    }
    bool Grid::atleastOneInRow(int x, char c)
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
    bool Grid::atleastOneInColumn(int x, char c)
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
    int Grid::checkCorner1(char c1, char c2)
    {
        if ((vector[0][0] != c1) 
            && (vector[0][0] != c2) 
            && !this->atleastOneInRow(0, c2) 
            && !this->atleastOneInColumn(0, c2))
        {
            return 1;
        }
        else if ((vector[0][0] == c1) 
            && !this->atleastOneInRow(0, c2) 
            && (this->checkSquare(dimension) != c1))
        {
            return dimension;
        }
        else if ((vector[0][0] == c1) 
            && !this->atleastOneInColumn(0, c2) 
            && (this->checkSquare(dimension * dimension - dimension + 1) != c1))
        {
            return dimension * dimension - dimension + 1;
        }
        else
        {
            return -1;
        }
    }
    int Grid::checkCorner2(char c1, char c2)
    {
        if ((vector[0][dimension - 1] != c1) 
            && (vector[0][dimension - 1] != c2) 
            && !this->atleastOneInRow(dimension - 1, c2) 
            && !this->atleastOneInColumn(0, c2))
        {
            return dimension;
        }
        else if ((vector[0][dimension - 1] == c1) 
            && !this->atleastOneInRow(0, c2) 
            && (this->checkSquare(1) != c1))
        {
            return 1;
        }
        else if ((vector[0][dimension - 1] == c1) 
            && !this->atleastOneInColumn(dimension - 1, c2) 
            && (this->checkSquare(dimension * dimension) != c1))
        {
            return dimension * dimension;
        }
        else
        {
            return -1;
        }
    }
    int Grid::checkCorner3(char c1, char c2)
    {
        if ((vector[dimension - 1][0] != c1) 
            && (vector[dimension - 1][0] != c2) 
            && !this->atleastOneInRow(0, c2) 
            && !this->atleastOneInColumn(dimension - 1, c2))
        {
            return dimension * dimension - dimension + 1;
        }
        else if ((vector[dimension - 1][0] == c1) 
            && !this->atleastOneInRow(dimension - 1, c2) 
            && (this->checkSquare(dimension * dimension) != c1))
        {
            return dimension * dimension;
        }
        else if ((vector[dimension - 1][0] == c1) 
            && !this->atleastOneInColumn(0, c2) 
            && (this->checkSquare(1) != c1))
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    int Grid::checkCorner4(char c1, char c2)
    {
        if ((vector[dimension - 1][dimension - 1] != c1) 
            && (vector[dimension - 1][dimension - 1] != c2) 
            && !this->atleastOneInRow(dimension - 1, c2) 
            && !this->atleastOneInColumn(dimension - 1, c2))
        {
            return dimension * dimension;
        }
        else if ((vector[dimension - 1][dimension - 1] == c1) 
            && !this->atleastOneInRow(dimension - 1, c2) 
            && (this->checkSquare(dimension * dimension - dimension + 1) != c1))
        {
            return dimension * dimension - dimension + 1;
        }
        else if ((vector[dimension - 1][dimension - 1] == c1) 
            && !this->atleastOneInColumn(dimension - 1, c2) 
            && (this->checkSquare(dimension) != c1))
        {
            return dimension;
        }
        else
        {
            return -1;
        }
    }