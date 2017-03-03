#ifndef __gameFunctionsh_
#define __gameFunctionsh_

#include "structures.h"

void displayBoard(status** gameBoard, int size);
status** calculateNextIteration(status ** gameBoard, int size);
status getNewCellStatus(status** gameBoard, coordinate cell, int size);
status** createGameBoard(int size);
status** copyGameBoard(status** gameBoard, int size);
int getNumLivingNeighbors(status** gameBoard, coordinate cell, int size);

#endif
