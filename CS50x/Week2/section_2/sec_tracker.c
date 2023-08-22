#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int length;
    do
    {
        // get the length from uset
        length = get_int("Length: ");
    }
    while (length < 1);

    // declare array
    int mult_by2 [length];

    // set the first value
    mult_by2[0] = 1;
    printf("%i\n", mult_by2[0]); // print out that value

    for (int i = 1; i < length; i++)
    {
        // make the current element twice the value of the previous
        mult_by2[i] = 2 * mult_by2[i - 1];
        printf("%i\n", mult_by2[i]);
    }
}