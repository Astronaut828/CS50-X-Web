#include <cs50.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check for improper usage.
    if (argc != 2)
    {
        printf("Improper usage.\n");
        return 1;
    }
    // open memory card
    string filename = argv[1];
    FILE *file = fopen(filename, "r");

    // check if file exists
    if (file == NULL)
    {
        printf("No such file found.\n");
        return 1;
    }

    // read 512 bytes into buffer and check for jped signature // repeat until end of card
    int counter = -1;
    int jpg = 0;
    FILE *img;
    uint8_t *bytes = malloc(sizeof(uint8_t) * 512);

    while (fread(bytes, 1, 512, file) == 512)
    {
        if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
        {
            jpg++;
            counter++;

            if (counter >= 1)
            {
                fclose(img);
            }

            // creating filename with counter
            sprintf(filename, "%03i.jpg", counter);

            //open and start writing first jpg
            img = fopen(filename, "w");

            if (img == NULL)
            {
                printf("Could not create file.\n");
                return 1;
            }
        }

        if (jpg >= 1)
        {
            fwrite(bytes, 512, 1, img);

        }

    }
    // close all buffers and files
    fclose(file);
    free(bytes);
    fclose(img);
}