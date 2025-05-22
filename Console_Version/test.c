#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "globals.h"
#include "gameInput.h"
#include "gamePreProcessing.h"




int main(int argc, char* argv[])
{
    ///*
    char board[SIZE][SIZE];
    //initialize board with spaces
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }
    

    for(int i = 0; i < argc; i++){
        printf("Index - %d, value: %s\n", i, argv[i]);
    }

    if (argc > 1){
        if(isdigit(argv[1][0]))
            gamesPlayed = argv[1][0] - '0';
    }
    printf("The number of games played is: %d \n", gamesPlayed);
    char test = newGame();
    //*/

    char * data = enterData();
    printf("The recieved data is: %s", data);

    for(int i = 0; i <10; i++)
        printf("Index %d, data - %d \n", i, data[i]);

    char mark;
    int row, col;

    bool good = validateData(board, data, &mark, &row, &col);
    
    if(good)
        printf("Data inputted and parsed correctly\n");
    else // !good
        printf("Data NOT inputted or parsed correclty\n");

    printf("The mark is %c, the row is %d, the column is %d. \n", mark, row, col);

    //
    for(int i = 0; i < SIZE; i++)
    {
        printf("[%c][%c][%c]\n", board[i][0], board[i][1], board[i][2]);
    }


    return 0;
}