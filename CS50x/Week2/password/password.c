// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)

{
    string len = password;

    bool upper = 0;
    bool lower = 0;
    bool digit = 0;
    bool symbol = 0;

    //When looping over a staring you are looking at each char one by one
    for (int i = 0; i < strlen(password); i++)
    {
        char check = len[i];

        if (isupper(check))
        {
            upper = 1;
        }
        else if (islower(check))
        {
            lower = 1;
        }
        else if (isdigit(check))
        {
            digit = 1;
        }
        else if (ispunct(check))
        {
            symbol = 1;
        }
    }

    if (upper && lower && digit && symbol)
    {
        return true;
    }
    else
    {
        return false;
    }
}