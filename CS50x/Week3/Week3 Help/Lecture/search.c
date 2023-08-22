#include <cs50.h>
#include <stdio.h>
#include <string.h> // string library - check under / manual.cs50.io/#string.h (line 33)

int main(void)
                              // linear search
{   // Static array [] = {}
    int numbers[] = {20, 500, 10, 5, 100, 1, 50}; // array containing those numbers / staticly assigning the array

    int n = get_int("Number: "); // asking for user input

    for (int i = 0; i < 7; i++)  // implement linear search, will move to next element until found
    {
        if (numbers[i] == n) // if number from user input == i
        {
            printf("Found\n");
            return 0; // successful (yes)
        }
    }
    printf("Not found\n");
    return 1;



                            // string

    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("String: "); // asking for user input  // a astring is an array

    for (int j = 0; j < 6; j++)  // implement linear search // adjust number j < XX to prevent segmentation fault
    {
        if (strcmp(strings[j], s) == 0) // for string == will not work
            // does the return value of function strcmp equal 0 when passed in the current aray value / user input
        {
            printf("Found\n");
            return 0; // successful (yes)
        }
    }
    printf("Not found\n");
    return 1; // signefy error code (main return)

}