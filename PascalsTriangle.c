#include    <stdio.h>
#include    <math.h>

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int choose(int n, int r)
{
    return (factorial(n))/((factorial(r))*(factorial(n-r)));
}

void triangle(int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int gap = 1; gap < rows - i; gap++)
        {
            printf("   ");
        }
        for (int col = 0; col <= i; col++)
        {
            int num = choose(i, col);
            printf("%d", num);
            
            if (num <= 10)
            {
                printf("     ");
            }
            if (num > 10 && num < 100)
            {
                printf("    ");
            }
            if (num >= 100)
            {
                printf("   ");
            }
        }
        printf("\n");
    }
    return;
}

int main(void) {
  int rows;

  do {
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    if (rows >= 0 && rows <= 13) {
      triangle(rows);
    }
  } while (rows >= 0 && rows <= 13);

  return 0;
}
