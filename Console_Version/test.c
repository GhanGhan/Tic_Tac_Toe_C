#include <stdio.h>
#include <ctype.h>
#include "gameInput.h"


int main(int argc, char* argv[])
{
    ///*
    int gamesPlayed;

    for(int i = 0; i < argc; i++){
        printf("Index - %d, value: %s\n", i, argv[i]);
    }

    if (argc > 1){
        if(isdigit(argv[1][0]))
            gamesPlayed = argv[1][0] - '0';
    }
    printf("The number of games played is: %d \n", gamesPlayed);
    char test = newGame(gamesPlayed);
    //*/

    char * data = enterData(1);
    printf("The recieved data is: %s", data);

    return 0;
}