// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string input);

int main(int argc, string argv[])
{

    if (argc != 2) // returning error if more or less the one word in command line.
    {
        printf("Enter word\n");
        return 1;
    }
    else
    {
        string input = argv[1];
        input = replace(input);
        printf("%s\n", input);
    }

} // end of main

string replace(string input)
{
    int length = strlen(input);
    for (int i = 0; i < length; i++)
    {
        if (input[i] == 'a')
        {
            input[i] = '6';
        }
        else if (input[i] == 'e')
        {
            input[i] = '3';
        }
        else if (input[i] == 'i')
        {
            input[i] = '1';
        }
        else if (input[i] == 'o')
        {
            input[i] = '0';
        }
        else
        {
            input[i] = input[i];
        }
    }
    return input; ///
}