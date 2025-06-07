#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "gameOutput.h"
#include "globals.h"


void printSeriesMetrics()
{
    printf("A total of %d games of Tic-Tac Toe, including this one, have been played!\n");
    printf("Player 1 (X) has one %d games.  Player 2 (O) has won %d games.\n", gamesWonX, gamesWonO);
}


void printCurrentMetrics(bool gameWon, bool gameStaleMate, char board[3][3])
{
    printf("GAMEBOARD\n");
    for(int i = 0; i < SIZE; i++)
    {
        printf("[%c][%c][%c]\n", board[i][0], board[i][1], board[i][2]);
    }

    printf("%d turns have been played!\n", turns + 1);

    if(gameWon)
    {
        gamesPlayed++;
        printf("This current game of Tic-Tac-Toe has come to an end\n");

        if(turns % 2 == 0)  // Currently Player 1's turn, mark = X
            printf("PLAYER 1 (X) HAS WON THE GAME\n");
        else //Currently Player 2's turn, marl = O
            printf("PLAYER 2 (0) HAS WON THE GAME\n");
    }

    else if (gameStaleMate)
    {
        gamesPlayed++;
        printf("The current game of Tic-Tac-Toe ihas ended in a STALEMATE - You guys are both MID!!!!!!\n");
    }

    turns++;
}