#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include "globals.h"
#include "gameInput.h"
#include "gamePreProcessing.h"
#include "gameState.h"
#include "gameOutput.h"


int main()
{
    bool play = true;
    char board[SIZE][SIZE];
    //initialize board with spaces
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }

    while(play)
    {
        //Start a new game
        char key = newGame();

        if(key == 'Q')
        {
            play = false;
            break;
        }

        bool done = false, gameWon, gameTie;
        char* inputData;
        bool valid;
        char mark;
        int row, col;
        while(!done)
        {
            //Get player input - mark and cell location to mark, then enter into board
            while(true)
            {
                inputData = enterData();
                valid = validateData(board, inputData, &mark, &row, &col);
                if(valid)
                    break;
            }
            
            //Check the state of the game
            gameWon = checkWinner(board, row, col, turns);
            gameTie = checkStatemate(board);

            //Display game state
            printCurrentMetrics(gameWon, gameTie, board);

            if(gameWon || gameTie)
            {
                done = true;
                printSeriesMetrics();
                //Reset gameBoard
                for(int i = 0; i < SIZE; i++)
                {
                    for(int j = 0; j < SIZE; j++)
                    {
                        board[i][j] = ' ';
                    }
                }
                //Reset number of turns
                turns = 0;
                //deallocate inputdat
                free(inputData);
                inputData = NULL;
            }

        }

    }
    
}