#include <cs50.h>
#include <stdio.h>
#include <string.h> // include when working with strings

int main(void)
{
    // get the length from uset
    string word = get_string("Word: ");

    int length = strlen(word);
    for (int i = 0; i < length -1; i++)
    {
        //check if not alphabetical order (ascii)
        if (word[i] > word [i + 1]) // we know that the order is not alphabetical if the
//    previous is bigger then the following character (i.e. b > a)
        {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");
    
} // c will return 0 here anyway