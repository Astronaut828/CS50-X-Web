#include <cs50.h>
#include <stdio.h>

int main(void)

// factorial functions

// fact(1) = 1
// fact(2) = 2 * fact(1)
// fact(3) = 3 * fact(2)        // call stack
// fact(4) = 4 * fact(3)
// fact(5) = 5 * 4 * 3 * 2 * 1
// ...

// fact(n) = n * fact(n - 1)

int fact(int n)
{
    if (n ==1)    // base case
  // fact(1) = 1
        return 1;
    else
        return n * fact(n - 1); // recusive case
  // fact(2) = 2 * fact(1)
  // fact(3) = 3 * fact(2)
  // fact(4) = 4 * fact(3)
}