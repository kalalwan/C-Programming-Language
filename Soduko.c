#include    <stdio.h>
#include    <stdbool.h>
#define     SizeGrid    4

void solveLocation(int row, int col, int grid[][SizeGrid])
{
    int h = 0, k = 0;
    int numbersArr[] = {1,2,3,4};
    bool flag = false;

    while (flag == false)
    {
        if (grid[k][col] == numbersArr[h] || grid[row][k] == numbersArr[h])
        {
            h++;
            k = 0;
        }
        if (grid[k][col] != numbersArr[h] && grid[row][k] != numbersArr[h])
        {
            k++;
        }
        if (k == 4)
        {
            flag = true;
        }
    }
    
    grid[row][col] = numbersArr[h];

    return;
}

void fillSudoko(const int Size, int sudoko[Size][Size])
{
    for (int i = 0; i < Size; i++)
    {
        for (int j = 0; j < Size; j++)
        {
            if (sudoko[i][j] == 0)
            {
                solveLocation(i, j, sudoko);
            }
        }
    }
    return;
}

int main(void)
{
    int grid[4][4] = {{1,0,3,0},{0,3,2,1},{2,0,1,0},{3,1,0,2}};

    fillSudoko(4, grid);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
