#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int a = 28; // assinging value
    int b = 50; // assinging value
    int *c = &a; // pointer *c to an (int) gets the adress ((value) stored at) of a

    *c = 14; //go to (adress of a) the value c is holding, and change to 14
    c = &b; // changing c's value to adress of b (&b)
    *c = 25; // follow c (b's adress) and change value to 25

    // print results
    printf("a has the value %i, located at %p\n", a, &a);
    printf("a has the value %i, located at %p\n", b, &b);
    printf("a has the value %p, located at %p\n", c, &c);
}