#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "globals.h"
//#include "gameInput.h"
//#include "gamePreProcessing.h"
#include "gameState.h"

void testStateFTS(char board[SIZE][SIZE], int row, int col);

int main(int argc, char* argv[])
{

    char index;

    if(argc != 2)
        return 1;
    else
        index = argv[1][0];

    int row = -1;
    int col = -1;
    //char board[SIZE][SIZE];

    switch (index)
    {
        case '0':

            char board0[SIZE][SIZE] = {
                {'O','X',' '},
                {' ','X',' '},              // Game should proceed
                {' ','O','X'},
            };
            turns = 4;
            row = 2; col = 2;
            testStateFTS(board0, row, col);

            break;

        case '1':

            char board1[SIZE][SIZE] = {
                {'O','X','O'},
                {'O','X','X'},              // Game Completed - STALEMATE
                {'X','O','X'},
            };
            turns = 8;
            row = 1; col = 1;
            testStateFTS(board1, row, col);

            break;

        case '2':

            char board2[SIZE][SIZE] = {
                {'X','O','X'},
                {'X','O','O'},              // One Left - STALEMATE
                {'O','X',' '},
            };

            turns = 7;
            row = 2; col = 0;
            testStateFTS(board2, row, col);

            break;

        case '3':

            char board3[SIZE][SIZE] = {
                {'X','X','O'},
                {'O','X','X'},              // One Left - STALEMATE
                {'O','O',' '},
            };
            turns = 7;
            row = 1; col = 0;
            testStateFTS(board3, row, col);

            break;

        case '4':

            char board4[SIZE][SIZE] = {
                {'O','X','X'},
                {'O','X',' '},              // Two Left - PLAYER 1 WILL WIN
                {'O',' ',' '},
            };
            turns = 5;            
            row = 1; col = 0;
            testStateFTS(board4, row, col);

            break;

        case '5':

            char board5[SIZE][SIZE] = {
                {'X','X','O'},
                {'O','O','X'},              // Two Left - STALEMATE
                {'X',' ',' '},
            };
            turns = 6;
            row = 1; col = 2;
            testStateFTS(board5, row, col);
            break;

        case '6':

            char board6[SIZE][SIZE] = {
                {'O','X','X'},
                {'O','X','O'},              // Game Completed - Player 1 wins
                {'X','O','X'},
            };
            turns = 8;
            row = 1; col = 1;
            testStateFTS(board6, row, col);

            break;

        default:

            printf("Invalid Input");
            break;

    }
}

void testStateFTS(char board[SIZE][SIZE], int row, int col)
{
    if(turns % 2 == 0)  // Currently Player 1's turn, mark = X
        printf("It is currently Player 1's turn\n");
    else //Currently Player 2's turn, marl = O
        printf("It is currently Player 2's turn\n");

    for(int i = 0; i < SIZE; i++)
    {
        printf("[%c][%c][%c]\n", board[i][0], board[i][1], board[i][2]);
    }

    if(checkWinner(board, row, col, turns))
    {
        if(turns % 2 == 0)  // Currently Player 1's turn, mark = X
            printf("Player 1 has won!! \n");
        else //Currently Player 2's turn, marl = O
            printf("Player 2 has won!! \n");
    }
    else if(checkStatemate(board))
        printf("You are both mid - THIS IS A STALEMATE");
    else
        printf("The game is still going");
}
    
    ////////////////////////////////////////
    

    
    

    ////////////////////////////////////////


    

    ////////////////////////////////////////


    

    ////////////////////////////////////////

    

    ////////////////////////////////////////

    

    ////////////////////////////////////////












