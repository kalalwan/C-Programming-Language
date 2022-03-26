#include    <stdio.h>
#include    <math.h>
#include    <stdbool.h>

//Implement the Euclidean ALgorithm for finding the greatest common divisor.

int gcd(int A, int B)
{
    while (A > 0)
    {
        int temp = B % A;
        B = A;
        A = temp;
    } 

    return B;
}

int main(void)
{
    //Variables for "k" and "a"'s bounds
    int kLower, kUpper, aLower, aUpper, result1, result2;

    //Boolean value for the completion of the search. Initialize to false so that the loop can run once.
    bool done = false;

    //These do/while loops are for getting the right parameters for k and a.
    do
    {
        printf("Enter the number to start searching for k (> 2, inclusive): ");
        scanf("%d", &kLower);
    } while (kLower <= 2);
    do
    {
        printf("Enter the number to stop searching for k (inclusive): ");
        scanf("%d", &kUpper);
    } while (kUpper <= kLower);
    do
    {
        printf("Enter the number to start searching for a (> 0, inclusive): ");
        scanf("%d", &aLower);
    } while (aLower <= 0);
    do
    {
        printf("Enter the number to stop searching for a (inclusive): ");
        scanf("%d", &aUpper);
    } while (aUpper <= aLower);

    //This outer while loop is repeating the inside loops until a E-W number is found or the k range is exceeded
    
    for (int k = kLower; (k <= kUpper) && (done == false); k++)
    {
        printf("Trying k = %d...\n", k);
        for (int a = aLower; (a <= aUpper) && (done == false); a++)
        {
            int counter = 0;
            for (int i = 1; (i <= k) && (done == false); i++) 
            {
                result1 = gcd(a, a+i);
                result2 = gcd(a+k, a+i);

                if(result1 > 1 || result2 > 1)
                {
                    counter++;
                }
                if((result1 == 1 && result2 == 1) && counter != k)
                {
                    counter = 0;
                }
            }
            if (counter == k)
            {
                done = true;
                printf("Erdos-Woods number: %d\n", k);
                printf("a = %d", a);
            }
        }
    }
    return 0;
}
