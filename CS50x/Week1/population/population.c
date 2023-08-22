#include <cs50.h>
#include <stdio.h>


int main(void)
{
    // TODO: Prompt for start size

    float y = 0;
    int up;

    int pops;
    do
    {
        pops = get_int("Start size:");
    }
    while (pops <= 8);

    // TODO: Prompt for end size
    int pope ;
    do
    {
        pope = get_int("End size:");
    }
    while (pope < pops);
    if (pops == pope)
    {
        y = 0;
    }



    // TODO: Calculate number of years until we reach threshold

    while (pops < pope)
    {
        up = (pops / 3 - pops / 4);
        pops = pops + up;
        y++;
    }

    // TODO: Print number of years

    float a = y;
    int n = (int) a;
    printf("Years: %i", n);
}
