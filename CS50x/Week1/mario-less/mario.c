#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt user Input
    int n;
    do
    {
        n = get_int("Hight: ");  //Asking for user input / size
    }
    while (n < 1 || n >= 9);

    // Pyramid build / for loop
    int v;
    int i;
    int j;
    char h = '#';
    char d = '.';

    for (v = 1; v <= n; v++) //Vertical line
    {
        for (i = n - 1; i >= v; i--) //Horizontal add spaces to build pyramid in nested loop
        {
            printf(" ");
        }
        for (j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}