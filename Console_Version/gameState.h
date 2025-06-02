#ifndef STATE_H
#define STATE_H
#include <stdbool.h>

bool checkStatemate(char board[3][3]);
bool checkWinner(char board[3][3], int row, int column);
bool checkRow(char board[3][3], char mark, int row);
bool checkColumn(char board[3][3], char mark, int column);
bool checkDiagnol(char board[3][3], char mark, int row, int column);

void findRemainingCell(char board[3][3], int* finalRow, int* finalColumn);
void unMarkCell(char board[3][3], char mark);




#endif