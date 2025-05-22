#include "gamePreProcessing.h"
#include "globals.h"
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>



bool parseData(char* playerInput, char* mark, int* row, int* col)
{
    int index = 0;
    //Check that the playerInput string is 5 characters long
    while(index < 10)
    { 
        if(playerInput[index] == '\n' && index != 5)
        {
            printf("The string you entered has %d characters, you must have 5 including spaces\n", index);
            return false;
        }
        else if (playerInput[index] == '\n' && index == 5)
            break;
            // playerInput has a data length of 5 characters including spaces
        index++;
    }
    if(index == 10)
    {
        printf("You enterd waaayy to many characters bub, try AGAIN\n");
        return false;
    }

    //Check that index 1 and 3 are spaces
    if(playerInput[1] != ' ' || playerInput[3] != ' ')
    {
        printf("The 2nd and 4th entries need to be spaces");
        return false;
    }

    //Check that index 2 and 4 are digits
    if(!isdigit(playerInput[2]) || !isdigit(playerInput[4]))
    {
        printf("The 3rd and 5th entries need to be numerical digits");
        return false;
    }

    *mark = playerInput[0];
    *row = playerInput[2] - '0';
    *col = playerInput[4] - '0';

    return true;
}

bool validateData(char board[3][3], char* playerInput, char* mark, int* row, int* col)
{
    bool parsed = parseData(playerInput, mark, row, col);
    if(!parsed)
        return false;

    // Validate the Player mMark
    if(turns % 2 == 0)
    {
        if(*mark != 'X')
        {
            printf("It is Player 1's turn, for input to be valid, the mark must be \"X\"");
            return false;
        }
    }
    else //if it is Player 2's turn, mark should be 'O'
    {
        if(*mark != 'O')
        {
            printf("It is Player 0's turn, for input to be valid, the mark must be \"X\"");
            return false;
        }
    }

    //Validate the row and column Part A
    if(*row < 0 || *row > 2)
    {
        printf("The row input value must be between 0 and 2 inclusive.\n");
        return false;
    }

    if(*col < 0 || *col > 2)
    {
        printf("The column input value must be between 0 and 2 inclusive.\n");
        return false;
    }

    //Validate the row and column Part B
    if(board[*row][*col] == ' ') //Location has not been filled
    {
        board[*row][*col] = *mark;
        printf("Entry has been added to the board!\n");
        return true;
    }
    else //Location has already been filled
    {
        printf("Entry has already beenn filled, pick a different one!!! \n");
        return false;
    }
    

}