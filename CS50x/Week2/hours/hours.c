#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks]; // array with number of weeks

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A'); // letter is capitalized (ASCII numbers = A/65, T/84)

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    // loop calculate total
    int total = 0;
    for (int x = 0; x < weeks; x++)
    {
        total += hours[x];
    }
    if (output == 84) // ascii value
    {
        return total;
    }

    // loop calculate  average
    int average = 0;
    for (int y = 0; y < weeks; y++)
    {
        average += hours[y];
    }
    if (output == 65)
    {
        return average / (float) weeks;
    }

    return 0;
}