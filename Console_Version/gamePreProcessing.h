#ifndef PRE_PROCESS
#define PRE_PROCESS
#include <stdbool.h>

bool parseData(char* playerInput, char* mark, int* row, int* col);

bool validateData(char board[3][3], char* playerInput, char* mark, int* row, int* col);






#endif