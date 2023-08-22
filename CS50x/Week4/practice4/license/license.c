#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[7];

    // Creates malloc pointer
    char *ptr;

    // Create array to store plate numbers
    char *plates[8]; // a pointer is nothing more then an address

    FILE *infile = fopen(argv[1], "r");

    int idx = 0;

    while (fread(buffer, 1, 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';

        ptr = (char *)malloc(7);
        if (ptr == NULL)
        {
            printf("No memory allocated\n");
            return 1;
        }

        strcpy(ptr, buffer);
        plates[idx] = ptr;
        idx++;
    }

    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);
        free(plates[i]);
    }
    fclose(infile);
}