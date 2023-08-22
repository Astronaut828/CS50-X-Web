#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("Name? ");
    int age = get_int("Age? ");
    string number = get_string("Phone Number? ");

printf("Contact information %s, %i, %s,", name, age, number);
printf("\n");
}