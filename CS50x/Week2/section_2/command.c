#include <cs50.h>
#include <stdio.h>
#include <string.h> // include when working with strings

// clang / make

int main(int argc, string argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("argv[%i] is %s\n", i, argv[i]);
    }
}

//  ./command ==
//              argv[0] is ./command

//  ./command Marco ==
//                    argv[0] is ./command
//                    argv[1] is Marco

