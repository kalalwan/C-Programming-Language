#include    <stdio.h>
#include    <stdlib.h>
#include    <stdbool.h>
#include    <string.h>

char oppositeColour(char colour){
    if (colour == 'B')
    {
        return 'W';
    }
    if (colour == 'W')
    {
        return 'B';
    }
}

bool positionInBounds(int size, int row, int col){
    bool inBounds;
    if ((row > size || col > size) || (row < 0 || col < 0))
    {
        inBounds = false;
    }
    if ((row <= size && col <= size)&&(row >= 0 && col >= 0))
    {
        inBounds = true;
    }
    return inBounds;
}

bool checkLegalInDirectionC(char colour, char board[26][26], int size, int row, int col, int deltaRow, int deltaCol){
    bool flag = false;
    int k = 1;
    while (flag == false)
    {
        if (positionInBounds(size, row + ((k)*deltaRow), col + ((k)*deltaCol)))
        {
            if (board[row + (k*deltaRow)][col + (k*deltaCol)] == oppositeColour(colour))
            {
                if (positionInBounds(size, row + ((k+1)*deltaRow), col + ((k+1)*deltaCol)) == false)
                {
                    flag = true;
                    return false;
                    break;
                }
                if (board[row + ((k+1)*deltaRow)][col + ((k+1)*deltaCol)] == 'U')
                {
                    flag = true;
                    return false;
                    break;
                }
                if (board[row + ((k+1)*deltaRow)][col + ((k+1)*deltaCol)] == colour)
                {
                    flag = true;
                    return true;
                    break;
                }
                k++;
            }
            else
            {
                flag = true;
                return false;
                break;
            }
        }
        else
        {
            flag = true;
            return false;
            break;
        }
    }
}

bool checkValid(char colour, int size, char board[26][26], int row, int col){
    bool validMove = false;
    for (int rowDir = -1; (rowDir < 2); rowDir++)
    {
        for (int colDir = -1; (colDir < 2); colDir++)
        {
            if (board[row][col] == 'U')
            {
                if (checkLegalInDirectionC(colour, board, size, row, col, rowDir, colDir) == true)
                {
                    validMove = true;
                    break;
                }
            }
        }
    }
    return validMove;
}

void printMoves(char board[26][26], int size){
    printf("Available moves for W:\n");
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (checkValid('W', size, board, i, j) == true)
            {
                printf("%c%c\n", 'a' + i, 'a' + j);
            }
        }
    }
    printf("Available moves for B:\n");
    for (int h = 0; h < size; h++)
    {
        for (int p = 0; p < size; p++)
        {
            if (checkValid('B', size, board, h, p) == true)
            {
                printf("%c%c\n", 'a' + h, 'a' + p);
            } 
        }
    }
    return;
}

void configureBoard(char *s, char board[26][26]){
    int row = s[1] - 'a';
    int col = s[2] - 'a';

    board[row][col] = s[0];

    return;
}

void enterConfiguration(char board[26][26]){
    bool flag = true;
    printf("Enter board configuration:\n");
    while(flag == true)
    {
        char config[4];
        scanf("%s", config);
        configureBoard(config, board);
        if (config[0] == '!')
        {
            flag = false;
        }
    }
    return;
}

void setupBoard(int size, char board[26][26]){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if ((i == ((size/2)-1)) && (j == ((size/2)-1)))
            {
                board[i][j] = 'W';
            }
            else if ((i == ((size/2)-1)) && (j == (size/2)))
            {
                board[i][j] = 'B';
            }
            else if ((i == size/2) && (j == size/2))
            {
                board[i][j] = 'W';
            }
            else if ((i == size/2) && (j == (size/2)-1))
            {
                board[i][j] = 'B';
            }
            else
            {
                board[i][j] = 'U';
            }
        }
    }
    return;
}

void printBoard(char board[26][26], int size){   
    printf("  ");
    for (char k = 'a'; k < 'a' + size; k++)
    {
        printf("%c", k);
    }
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        char c = 'a';
        printf("%c ", c + i);
        for (int j = 0; j < size; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    return;
}

void flipTiles(char colour, char board[][26], int size, int row, int col){
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (checkLegalInDirectionC(colour, board, size, row, col, i, j))
            {
                int h = 1;
                while (board[row+(h*i)][col+(h*j)] == oppositeColour(colour))
                {
                    board[row+(h*i)][col+(h*j)] = colour;
                }
            }
        }
    }
    return;
}

void enterMove(char *move, char colour, char board[][26], int size){

    if (move[0] == colour)
    {
        if (checkValid(colour, size, board, move[1] - 'a', move[2] - 'a'))
        {
            printf("Valid move.\n");
            flipTiles(colour, board, size, move[1] - 'a', move[2] - 'a');
            board[move[1] - 'a'][move[2] - 'a'] = colour;
            printBoard(board, size);
        }
        else
        {
            printf("Invalid move.\n");
            printBoard(board, size);
        }
    }
    return;
}

int main(void){
    int size;
    char board[26][26];
    printf("Enter the board dimension: ");
    scanf("%d", &size);
    setupBoard(size, board);
    printBoard(board, size);
    enterConfiguration(board);
    printBoard(board, size);
    printMoves(board, size);
    char move[4];
    printf("Enter a move:\n");
    scanf("%s", move);
    enterMove(move, move[0], board, size);
    return 0;
}
