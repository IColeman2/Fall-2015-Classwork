#include "gameFunctions.h"
#include "structures.h"
#include <unistd.h>
#include <ncurses.h>

//Assumes the given cell is within the array bounds
void placeBeacon(status** gameBoard, coordinate cell);
void placeToad(status** gameBoard, coordinate cell);
void placeGlider(status** gameBoard, coordinate cell);

int main(int argc, char *argv[])
{
    const int size = 50;
    int ticksPerSec = 3;
    status** board = NULL;
    board = createGameBoard(size);
    coordinate cell;

    //Initializes the board to have some living cells
    cell.x = 0;
    cell.y = 0;
    placeBeacon(board, cell);

    cell.x = 10;
    cell.y = 5;
    placeToad(board, cell);

    cell.x = 15;
    cell.y = 15;
    placeGlider(board,cell);

    //Initialize Ncurses Screen
    initscr();

    while (true)
    {
        clear();
        refresh();
        displayBoard(board, size);
        refresh();
        calculateNextIteration(board, size);
        usleep(1000000 / ticksPerSec);
    }

    //Close Ncurses Screen
    endwin();

    return 0;
}

void placeBeacon(status** gameBoard, coordinate cell)
{
    gameBoard[cell.x][cell.y] = ALIVE;
    gameBoard[cell.x+1][cell.y] = ALIVE;
    gameBoard[cell.x][cell.y+1] = ALIVE;

    gameBoard[cell.x+3][cell.y+3] = ALIVE;
    gameBoard[cell.x+3][cell.y+2] = ALIVE;
    gameBoard[cell.x+2][cell.y+3] = ALIVE;
}

void placeToad(status** gameBoard, coordinate cell)
{
    gameBoard[cell.x+1][cell.y] = ALIVE;
    gameBoard[cell.x+2][cell.y] = ALIVE;
    gameBoard[cell.x+3][cell.y] = ALIVE;

    gameBoard[cell.x][cell.y+1] = ALIVE;
    gameBoard[cell.x+1][cell.y+1] = ALIVE;
    gameBoard[cell.x+2][cell.y+1] = ALIVE;
}

void placeGlider(status** gameBoard, coordinate cell)
{
    gameBoard[cell.x][cell.y+1] = ALIVE;
    gameBoard[cell.x+1][cell.y+2] = ALIVE;
    gameBoard[cell.x+2][cell.y+2] = ALIVE;
    gameBoard[cell.x+2][cell.y+1] = ALIVE;
    gameBoard[cell.x+2][cell.y] = ALIVE;
}

