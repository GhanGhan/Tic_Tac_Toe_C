#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include "globals.h"
#include "gameState.h"


bool checkWinner(char board[3][3], int row, int column, int turnNumber)
{
    char mark = ' ';
    if(turnNumber % 2 == 0)  // Currently Player 1's turn, mark = X
        mark = 'X';
    else //Currently Player 2's turn, marl = O
        mark = 'O';

    bool gameWon = false;

    if(checkRow(board, mark, row))
        gameWon = true;
    else if(checkColumn(board, mark, column))
        gameWon = true;
    

    if(gameWon == true)
    {
        if(mark == 'X')
            gamesWonX++;
        else //mark == 'O'
            gamesWonO++;
    }

    return gameWon;

}

bool checkRow(char board[3][3], char mark, int row)
{
    bool winner = true;
    for(int i = 0; i < SIZE; i++)
    {
        if(board[row][i] != mark)
            winner = false;
    }

    return winner;

}

bool checkColumn(char board[3][3], char mark, int column)
{
    bool winner = true;
    for(int i = 0; i < SIZE; i++)
    {
        if(board[i][column] != mark)
            winner = false;
    }

    return winner;

}

bool checkDiagnol(char board[3][3], char mark, int row, int column)
{
    bool winner = true;
    int sum = row + column;
    if(sum % 2 == 0)    //if true, mark is on a diagnol line
    {
        if(row == column)   // top left to bottom right
        {
            for(int k = 0; k < SIZE; k++)
            {
                if(board[k][k] != mark)
                    winner = false;
                if(winner)
                    return winner;
            }
        }

        if(sum == 2 || (winner == false && row == 1 && column == 1))    // bottom left to top right, and winner hasn't been declared
            winner = true;
            for(int k = 0; k < SIZE; k++)
            {
                if(board[SIZE-1-k][k] != mark)
                    winner = false;
            }
    }
    else
        winner = false;

    return winner;
}

bool checkStatemate(char board[3][3])
{
    bool staleMate = false;
    char testBoard[SIZE][SIZE];
    int finalRow = -1;
    int finalColumn = -1;
    char tempMark = 'S';
    for(int i = 0; i < SIZE; i++)
    {
        for(int j  = 0; j < SIZE; j++)
            testBoard[i][j] = board[i][j];
    }

    if(turns == 8) // in the process of completing the 9th round, if the winner isn't declared, game has to be a tie
        staleMate = true;
    if(turns == 7) // there is one cell left
    {
        char mark = 'X'; //It will always be Player 1s turn
        findRemainingCell(testBoard, &finalRow, &finalColumn);
        testBoard[finalRow][finalColumn] = mark;
        staleMate = !checkWinner(testBoard, finalRow, finalColumn, turns + 1);
    }
    if(turns == 6)  // thre are two cells left
    {
        int rowOptions[] = {-1, -1};
        int colOptions[] = {-1, -1};

        for(int i = 0; i < 2; i++)
        {
            findRemainingCell(testBoard, &rowOptions[i], &colOptions[i]);
            testBoard[rowOptions[i]][colOptions[i]] = tempMark;
        }
        unMarkCell(testBoard, tempMark );


        //Test if both combinations will lead to a stalemate
        for(int option = 0; option < 2; option++)
        {
            int staleMateList[] = {true, true, true, true};
            char mark = 'O'; // it will always be player 2's turn next
            testBoard[rowOptions[option]][colOptions[option]] = mark;
            staleMateList[option] = !checkWinner(testBoard, rowOptions[option], colOptions[option], turns + 1);
            // Afterwards it will be Player 1's turn
            mark = 'X';
            testBoard[rowOptions[1-option]][colOptions[1-option]] = mark;
            staleMateList[option + 2] = !checkWinner(testBoard, rowOptions[option], colOptions[option], turns + 2);

            if(staleMateList[0] == true && staleMateList[1] == true)
                staleMate = true;
            else if (staleMateList[0] == true && staleMateList[1] == true && staleMateList[2] == true && staleMateList[3] == true)
                staleMate = true;
        }
    }

    return staleMate;
}


void findRemainingCell(char board[3][3], int* finalRow, int* finalColumn)
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(board[i][j] == ' ')
            {
                *finalRow = i;
                *finalColumn = j;
                return;
            }
        }
    }
    return;
}

void unMarkCell(char board[3][3], char tempMark)
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if(board[i][j] == tempMark)
                board[i][j] = ' ';
        }
    }
}