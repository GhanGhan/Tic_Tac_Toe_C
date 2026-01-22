#include <stdio.h>
#include <stdlib.h>
#include "gameInput.h"
#include "globals.h"

char newGame()
{
    char key = ' ';
    if(gamesPlayed == 0)
    {
        printf("\nWelcome to Tic-Tac-Toe!!!!!! \nPlayer 1 is \"X\", Player 2 is \"O\"! ");
        printf("Type \"G\" then press \"Enter\" when you are ready to play! \n: ");

        key = ' ';

        while(key != 'G')
        {   // the space before %c tells scan to skip over any whitespace (\n, \t etc.) before reading the char
            scanf(" %c", &key); // function oftens leaves a new line character in stdin after you press enter
            getchar(); //consume new line character in the standard input buffer (stdin)
            if(key != 'G')
                printf("Invalid input, please enter the character \"G\" \n: ");
        }

        printf("Alright, let's start the game! \n");
    }
    else
    {
        printf("The previous game has been completed. \nIf you would like to play again, press \"G\"! \n");
        printf("If you would like to quit the game, press \"Q\" \n: ");

        key = ' ';

        while(key != 'G' && key != 'Q')
        {   // the space before %c tells scan to skip over any whitespace (\n, \t etc.) before eading the char
            scanf(" %c", &key); // function oftens leaves a new line character in stdin after you press enter
            getchar(); //consume new line character in the standard input buffer (stdin)
            if(key == 'G')
                printf("Alright, we will start another game!! \n");
            else if(key == 'Q')
            {
                printf("Alright, thanks for playing! \n");
                exit(0);
            }
            else
                printf("Invalid input, please enter \"G\" to play again or \"Q\" to quit playing! \n: ");
        }
    }
    return key;

}

char* enterData()
{

    int dataSize = 10; //actually expecting 5 characters, using 10 incase user types a few more than required
    char * data = malloc(dataSize*sizeof(char));
    
    //Set all values to NULL
    for(int i = 0; i < dataSize; i++)
    {
        data[i] = '\0';
    }


    if(data == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    // placing getChar after scanf prevents fgets from reading the left-over \n character in the standard input buffer stdin
    if(turns %2 ==0)
    {
        printf("Player 1's turn, please enter your mark - \"X\", and cell location e.g. \"X 2 1\" \n: ");
        fgets(data, dataSize, stdin); // reads characters untirl reaches dataSize limit, or encounters a new/end-of line character
    }
    else
    {
        printf("Player 2's turn, please enter your mark - \"O\", and cell location e.g. \"O 2 1\" \n: ");
        fgets(data, dataSize, stdin); // reads characters untirl reaches dataSize limit, or encounters a new/end-of line character
    }

    return data;
}