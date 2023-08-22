// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    int max = array[0]; // initialize the maximum value to the first element of the array
    for (int i = 1; i < n; i++) // iterate through the array
    {
         if (array[i] > max) // check if the current element is greater than the maximum value
         {
         max = array[i]; // if it is, update the maximum value
         }
    }
    return max; // return the maximum value
}