#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Max number of candidates
#define MAX 9 // syntax used here to mean that MAX is a constant (equal to 9) that can be used throughout the program
// maximum number of candidates an election can have.

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate; // defines a global array of candidates, where each element is itself a candidate.

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1; // copies command-line arguments into the array candidates
    if (candidate_count > MAX) // MAX being 9
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: "); //asks the user to type in the number of voters

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: "); // Then every voter types in a vote, calling the vote function on each candidate voted

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner(); // call to the print_winner/s

}// End Main //

// Update vote totals given a new vote
bool vote(string name)
{
    int count = candidate_count;
    for (int i = 0; i < count; i++)
    {
        if (strcasecmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes = candidates[i].votes + 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int count = candidate_count;
    int most = 0;

    for (int n = 0; n < count; n++)
    {
        if (most <= candidates[n].votes)
        {
            most = candidates[n].votes;
        }
    }
    for (int m = 0; m < count; m++)
    {
        if (most <= candidates[m].votes)
        {
            printf("%s\n", candidates[m].name);
        }
    }
    return;
}