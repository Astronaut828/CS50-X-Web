#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string user_input = get_string("Message: \n"); // ask user for input (string)

    int len = strlen(user_input);
    int bin[8]; // setting array for binary number [8 bits]

    for (int i = 0; i < len; i++)
    {
        int ascii = user_input[i];

        for (int j = 8; j > 0; j--) // loading bit array [8] to [0]
        {
            bin[j] = ascii % 2; // dividing ascii value with modulo operator
            ascii = ascii / 2;
        }
        for (int h = 1; h <= 8; h++) // counting down each element oh array bit[0] to [8]
        {
            int bit = bin[h];
            print_bulb(bit); // calling function print_bulb with value of bit (0/1)
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
