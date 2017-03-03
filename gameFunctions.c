#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#include "gameFunctions.h"
#include "structures.h"


status** createGameBoard(int size)
{
    int* d = NULL;
    int i, j;
    status** gameBoard = malloc(sizeof(status*) * size);

    for (i = 0; i < size; i++)
    {
        gameBoard[i] = malloc(sizeof(status) * size);
        for (j = 0; j < size; j++)
            gameBoard[i][j] = DEAD;
    }
    return gameBoard;
}

//Makes a copy of the game board (or a 2D array of bools/ints)
status** copyGameBoard(status** gameBoard, int size) //DONE
{
    int i,j;

    //Makes a copy of the current game board
    status ** tempBoard = malloc(sizeof(status*) * size);
    for (i = 0; i < size; i++)
    {
        tempBoard[i] = malloc(sizeof(status) * size);
        for (j = 0; j < size; j++)
        {
            tempBoard[i][j] = gameBoard[i][j];
        }
    }

    return tempBoard;
}

void displayBoard(status** gameBoard, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
            if (gameBoard[i][j] == ALIVE)
                printw("%c", 'X');
            else
                printw("%c", '-');
        printw("\n");
    }
}

status** calculateNextIteration(status ** gameBoard, int size)  
{
    int i, j;
    status** copyBoard = copyGameBoard(gameBoard, size);
    coordinate thisCell;

    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            thisCell.x = j;
            thisCell.y = i;
            gameBoard[thisCell.x][thisCell.y] = getNewCellStatus(copyBoard, thisCell, size);
        }
    }

    for (i = 0; i < size; i++)
        free(copyBoard[i]);
    free(copyBoard);

    return gameBoard;
}

status getNewCellStatus(status** gameBoard, coordinate cell, int size) //DONE
{
    int livingNeighbors = getNumLivingNeighbors(gameBoard, cell, size);

    if (gameBoard[cell.x][cell.y] == ALIVE)
    {
        if (livingNeighbors < 2)
            return DEAD;
        else if (livingNeighbors == 2 || livingNeighbors == 3)
            return ALIVE;
        else 
            return DEAD;
    }
    else
    {
        if (livingNeighbors == 3)
            return ALIVE;
        else 
            return DEAD;
    }
}

//Gets the number of living neighbors for a particular cell in the board.
//Since it's possible that the cell is on an edge, we need to make sure that 
//we don't try to access something outside the bounds of the board.
int getNumLivingNeighbors(status** gameBoard, coordinate cell, int size) //DONE
{
    bool leftBorder = (cell.x == 0);
    bool rightBorder = (cell.x == (size-1));
    bool topBorder = (cell.y == 0);
    bool bottomBorder = (cell.y == (size-1));

    int num = 0;

    if (topBorder)
    {
        if (leftBorder) //Top left
        {
            num += gameBoard[cell.x+1][cell.y];   //1 Right
            num += gameBoard[cell.x+1][cell.y+1]; //Bottom Right
            num += gameBoard[cell.x][cell.y+1];   //1 Down            
        }
        else if (rightBorder) //Top right
        {
            num += gameBoard[cell.x-1][cell.y];   //1 Left
            num += gameBoard[cell.x-1][cell.y+1]; //Bottom left
            num += gameBoard[cell.x][cell.y+1];   //1 Down
        }
        else //Top middle
        {
            num += gameBoard[cell.x-1][cell.y];   //1 Left
            num += gameBoard[cell.x-1][cell.y+1]; //Bottom left
            num += gameBoard[cell.x][cell.y+1];   //1 Down
            num += gameBoard[cell.x+1][cell.y];   //1 Right
            num += gameBoard[cell.x+1][cell.y+1]; //Bottom Right            
        }
    }
    else if (bottomBorder)
    {
        if (leftBorder) //Bottom left
        {
            num += gameBoard[cell.x][cell.y-1];   //1 Up
            num += gameBoard[cell.x+1][cell.y];   //1 Right
            num += gameBoard[cell.x+1][cell.y-1]; //Top Right
        }
        else if (rightBorder) //Bottom Right
        {
            num += gameBoard[cell.x-1][cell.y];   //1 Left
            num += gameBoard[cell.x][cell.y-1];   //1 Up
            num += gameBoard[cell.x-1][cell.y-1]; //Top Left
        }
        else //Bottom middle
        {
            num += gameBoard[cell.x-1][cell.y];   //1 Left
            num += gameBoard[cell.x][cell.y-1];   //1 Up
            num += gameBoard[cell.x-1][cell.y-1]; //Top Left
            num += gameBoard[cell.x+1][cell.y];   //1 Right
            num += gameBoard[cell.x+1][cell.y-1]; //Top Right            
       }
    }
    else
    {
        if (leftBorder)
        {
            num += gameBoard[cell.x][cell.y-1];   //1 Up
            num += gameBoard[cell.x+1][cell.y];   //1 Right
            num += gameBoard[cell.x+1][cell.y-1]; //Top Right            
            num += gameBoard[cell.x+1][cell.y+1]; //Bottom Right            
            num += gameBoard[cell.x][cell.y+1];   //1 Down
        }
        else if (rightBorder)
        {
            num += gameBoard[cell.x-1][cell.y];   //1 Left
            num += gameBoard[cell.x][cell.y-1];   //1 Up
            num += gameBoard[cell.x-1][cell.y-1]; //Top Left
            num += gameBoard[cell.x-1][cell.y+1]; //Bottom left
            num += gameBoard[cell.x][cell.y+1];   //1 Down            
        }
        else
        {

            num += gameBoard[cell.x+1][cell.y];   //1 Right
            num += gameBoard[cell.x-1][cell.y];   //1 Left
            num += gameBoard[cell.x][cell.y-1];   //1 Up
            num += gameBoard[cell.x][cell.y+1];   //1 Down
            num += gameBoard[cell.x+1][cell.y-1]; //Top Right
            num += gameBoard[cell.x-1][cell.y-1]; //Top Left
            num += gameBoard[cell.x+1][cell.y+1]; //Bottom Right
            num += gameBoard[cell.x-1][cell.y+1]; //Bottom left
        }
    }

    return num;
}

