#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "Grid.h"

class Player
{
protected:
    char marks;
    bool CPU;
public:
    Player();
    bool isCPU();
    void makeCPU();
    void setChar(char c);
    char getChar();
    int makeMoveAsCPU(Grid* grid, Player secondPlayer);
    int makeMove(Grid* grid);
};

#endif