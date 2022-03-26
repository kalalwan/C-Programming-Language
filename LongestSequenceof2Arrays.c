#include    <stdio.h>

void longestSequence(int a[], int sizeA);

int main(void)
{
    return 0;
}

void longestSequence(int a[], int sizeA)
{
    int counter = 0, streak = 1, streakStart, longestStreak = 1, i = 0;

    while (counter < sizeA)
    {
        if (a[counter] < a[counter + 1])
        {
            streak++;
        }
        if (a[counter] >= a[counter +1])
        {
            if(streak > longestStreak)
            {
                streakStart = (counter + 1) - streak;
                longestStreak = streak;
            }
            streak = 1;
        }
        if (sizeA == 1)
        {
            printf("Longest sequence is %d", a[0]);
        }
        counter++;
    }

    printf("Longest sequence is ");
    for (; i < longestStreak - 1; i++)
    {
        printf("%d, ", a[streakStart + i]);
    }
    printf("%d. ", a[streakStart + i]);
    
    return;
}

******************* Question 3 *********************/

#include    <stdio.h>

void longestMutualSequence(int firstArr[], int secondArr[], int sizeA, int sizeB)
{
    int thirdArr[sizeA][sizeB];

    //changes the 2D array into all zeros
    for (int i = 0; i < sizeA; i++)
    {
        for (int j = 0; j < sizeB; j++)
        {
            thirdArr[i][j] = 0;
        }
    }

    //traverse the 2D array backwards and checks for sequences
    //if a sequence is found, it's numbered from length of sequence to 1
    for (int i = sizeA; i >= 0; i--)
    {
        for (int j = sizeB; j >= 0; j--)
        {
            if (firstArr[i] == secondArr[j] && (i != sizeA - 1))
            {
                thirdArr[i][j] = thirdArr[i + 1][j + 1] + 1;
            }
            if (firstArr[i] == secondArr[j] && (i == sizeA - 1))
            {
                thirdArr[i][j] = 1;
            }
        }
    }
    
    int temp = 0, sequenceStart;
    //this loop finds the maximum sequence length and which index it starts at
    for (int i = 0; i < sizeA; i++)
    {
        for (int j = 0; j < sizeB; j++)
        {
            int difference = thirdArr[i][j] - temp;
            if (thirdArr[i][j] > temp)
            {
                temp += difference;
                sequenceStart = i;
            }
        }
    }
    //printing the result using the variables above
    printf("Longest common sequence is ");
    for (int i = 0; i < temp - 1; i++)
    {
        printf("%d, ", firstArr[sequenceStart+i]);
    }
    printf("%d.", firstArr[sequenceStart+temp-1]);


    return;
}

int main(void)
{
    int a[] = {1, 2, 3, 4, 1000, 90, 100, 110, 200, 202};
    int b[] = {1, 1, 2, 3, 90, 100, 110, 200, 202, 600};

    longestMutualSequence(a, b, 10, 10);

    return 0;
}
