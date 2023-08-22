#include <cs50.h>
#include <stdio.h>
// see phonebook.c in weekk3 help

typedef struct // declared globaly, called in main
{
    string name;
    int votes;
    // maximum attributes is unlimited (keep it kinda short)
}
candidate;

// struct ==
// name: candidate
// what are the types of date in this struct


// new faviable ==
// candidate(struct) (name) president;
// president.name = "Alyssa"; / line 5
// president.votes = 10;      / line 6

// calling the value with president.name / president.votes

candidate get_candidate(string prompt); //prototype for function

int main(void)
{
    candidate candidates_array[3];
    for (int i = 0; i < 3; i++)
    {
        candidates_array[i] = get_candidate("Enter a candidate: ");
        // to access the the candidates specific information = candidates[0].name / .votes
    }
}

{
    candidate president = get_candidate("Enter a candidate: ");
    candidate votes = get_candidate("Votes: ");

    printf("%s\n", president.name);
    printf("%i\n", president.votes);
}

candidate get_candidate(string prompt) // function as declared in line 25
{
    printf("%s\n", prompt);

    candidate c;
    c.name = get_string("Entere a name: ");
    c.votes = get_int("Enter a number of votes: ");
    return c;
}



