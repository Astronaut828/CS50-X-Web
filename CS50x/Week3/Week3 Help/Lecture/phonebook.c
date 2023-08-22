#include <cs50.h>
#include <stdio.h>
#include <string.h> // string library - check under / manual.cs50.io/#string.h

typedef struct // initialize struct
{
    string name;
    string number;
// can add / string adress;
}
person; // structure name / later array[]


int main(void);

    string names[] = {"Carter", "David"};
    string numbers[] = {"+1-617-459-1000", "+1-949-468-2750"};

    string name = get_string("Name: "); // asking for user input  // a astring is an array

    for (int j = 0; j < 2; j++)  // implement linear search // adjust number j < XX to prevent segmentation fault
    {
        if (strcmp(names[j], name) == 0) // for string == will not work
            // does the return value of function strcmp equal 0 when passed in the current aray value / user input
        {
            printf("Found %s\n", numbers[j]); // will print number in array numbers
            return 0; // successful (yes)
        }
    }
    printf("Not found\n");
    return 1; // signefy error code (main return)




//  typedef struct (defined in line 5)  // linear search

    person people[2]; // data structure person // creat an array of size2 
    people[0].name = "Carter";  // create name and number
    people[0].number ="+1-617-459-1000";

    people[1].name = "David";
    people[1].number ="+1-949-468-2750";


    string name = get_string("Name: "); // asking for user input  // a astring is an array

    for (int i = 0; i < 2; i++)  // implement linear search // adjust number j < XX to prevent segmentation fault
    {
        if (strcmp(people[i].name, name) == 0)

        {
            printf("Found %s\n", people[i].number); // will print number in array number
            return 0; // successful (yes)
        }
    }
    printf("Not found\n");
    return 1; // signefy error code (main return)

}