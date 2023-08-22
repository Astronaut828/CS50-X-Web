#include <cs50.h>
#include <stdio.h>

void draw(int n); // defined over all positive integers

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int n)
{
    if (n <= 0) // "base case" stops the recursion
    {
        return;
    }

    draw(n - 1);

    for  (int i = 0; i < n; i++)
    {
         printf("#");
    }
    printf("\n");
}
