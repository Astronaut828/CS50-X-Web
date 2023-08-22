#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{

    // TODO
    int tru = 0;

    for(int fal = 2; fal <= number; fal++)
    {
        if((number % fal) == 0)
        {
        tru = 1;
        }
        if ((tru == 0 && fal == (number -1)) || number < 3)
        {
        return true;
        }
    }
    return false;
}