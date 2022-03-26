#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//This function takes in the direction that the word was found and prints the appropriate direction.
void printFoundLocation(int rowDir, int colDir)
{
    if (rowDir == 1)
    {
        if (colDir == 1)
        {
            printf(" in the south-east direction.");
        }
        if (colDir == 0)
        {
            printf(" in the south direction.");
        }
        if (colDir == -1)
        {
            printf(" in the south-west direction.");
        }
    }
    if (rowDir == 0)
    {
        if (colDir == 1)
        {
            printf(" in the east direction.");
        }
        if (colDir == -1)
        {
            printf(" in the west direction.");
        }
    }
    if (rowDir == -1)
    {
        if (colDir == 1)
        {
            printf(" in the north-east direction.");
        }
        if (colDir == 0)
        {
            printf(" in the north direction.");
        }
        if (colDir == -1)
        {
            printf(" in the north-west direction.");
        }
    }
}

bool search1D(char word[], int wordSize, const int Size, char grid[Size][Size], int row, int col, int rowDir, int colDir)
{
    //We want the search to continue of we match the letter in the search to the letter in the word so we initialize a bool
    //called letterFound that helps us determine whether the loop should continue, or if we should move on to another direction
    bool letterFound = true;
    bool wordFound = false;
    //This for loop initializes a variable k which is multiplied by rowDir and colDir to give a net movement in some direction
    for (int k = 1; k < wordSize && wordFound == false && letterFound == true; k++)
    {
        if (word[k] != grid[row+(k*rowDir)][col+(k*colDir)])
        {
            //if a letter is not found, the whole loop stops and we start checking another direction
            letterFound = false;
        }
        if (k == wordSize - 1)
        {
            //if the number of letters that we find is equal to the number of letters in the word - 1, this means we found
            //the word in the word-search!
            wordFound = true;
        }
    }
    return wordFound;
}

//This function is responsible for putting together the above functions.
void search2D(char word[], int wordSize, const int Size, char grid[Size][Size])
{
    int I = 0, J = 0;
    //First, we initialize the wordFound flag to false, in hopes that if we find the word, we can stop the loop.
    bool wordFound = false;

    //This first for loop is to traverse the matrix in the row direction
    for (int i = 0; i < Size && wordFound == false; i++)
    {
        //this second for loop is to traverse the matrix in the column direction
        for (int j = 0; j < Size && wordFound == false; j++)
        {
            //here we're checking if the letter that we're at in the grid matches the first letter of the word we're looing for
            if (grid[i][j] == word[0])
            {
                //this for loop is picking one of the three directions Up, Down, or None
                for (int rowDir = -1; rowDir < 2 && wordFound == false; rowDir++)
                {
                    //this for loop is picking one of the three directions Left, Right, or None
                    for (int colDir = -1; colDir < 2 && wordFound == false; colDir++)
                    {
                        //If the search in the chosen direction yields True i.e. the word is found...
                        if (search1D(word, wordSize, Size, grid, i, j, rowDir, colDir) == true)
                        {
                            wordFound = true;
                            //The location of the first letter of the word is printed...
                            printf("Word found at row %d and column %d", i, j);
                            //then the direction of the word is printed using the printFoundLocation function
                            printFoundLocation(rowDir, colDir);
                        }
                    }
                }
            }
            J++;
        }
        I++;
    }
    if (I == Size && J == Size && wordFound == false)
    {
        printf("Word not found.");
    }
    
    return;
}

int main(void)
{

    return 0;
}
