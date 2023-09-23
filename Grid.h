#pragma once

#ifndef GRID_H
#define GRID_H

#include <vector>

class Grid
{
private:
    int dimension;
    std::vector<std::vector<char>> vector;
public:
    Grid();
    void setDimension(int x);
    int getDimension();
    void createVector();
    bool noRoom();
    void currentSituation();
    bool xWon();
    bool oWon();
    char checkSquare(int x);
    void setMark(char c, int x);
    int checkRow(char c1, char c2);
    int checkColumn(char c1, char c2);
    bool checkMainDiagonal(char c1, char c2);
    bool checkSecondDiagonal(char c1, char c2);
    int putCharInRow(int x);
    int putCharInColumn(int x);
    int putCharInMainDiagonal();
    int putCharInSecondDiagonal();
    bool atleastOneInRow(int x, char c);
    bool atleastOneInColumn(int x, char c);
    int checkCorner1(char c1, char c2);
    int checkCorner2(char c1, char c2);
    int checkCorner3(char c1, char c2);
    int checkCorner4(char c1, char c2);
};

#endif