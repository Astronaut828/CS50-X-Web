#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int main(void)
{
    int n = get_int("Get n: ");
    printf("collatz (n): %i\n", collatz(n));

}
int collatz(int n)
{
    if (n == 1) // base case
    {
        return 0;
    }
    else if ((n % 2) == 0) // recursive case 1 / even numbers
    {
        return 1 + collatz(n / 2);
    }
    else                   // recursive case 2 / odd numbers
    {
        return 1 + collatz(3*n + 1);
    }
}