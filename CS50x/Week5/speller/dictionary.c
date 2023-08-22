// Implements a dictionary's functionality

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Hash the word to get the index of the corresponding linked list in the hash table
    int index = hash(word);

    // Traverse the linked list at the hashed index to look for the word
    for (node *cursor = table[index]; cursor != NULL; cursor = cursor->next)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            // The word is found in the linked list
            return true;
        }
    }

    // The word is not found in the linked list
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Initialize hash value to 0
    unsigned int hash_value = 0;

    // Iterate over each character in the word
    for (int i = 0; word[i] != '\0'; i++)
    {
        // Multiply hash value by a prime number and add ASCII value of character (found the prime number hint in stackoverflow research)
        hash_value = (hash_value * 31) + tolower(word[i]);
    }

    // Reduce hash value to a number between 0 and N-1
    return hash_value % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Read words from file and add to hash table
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create new node for word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            return false;
        }

        // Copy word into node and hash node
        strcpy(new_node->word, word);
        int index = hash(word);
        new_node->next = table[index];
        table[index] = new_node;
    }

    // Close dictionary file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    int count = 0;

    // Traverse hash table
    for (int i = 0; i < N; i++)
    {
        // Traverse linked list at each index in the hash table
        for (node *ptr = table[i]; ptr != NULL; ptr = ptr->next)
        {
            count++;
        }
    }

    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Traverse hash table
    for (int i = 0; i < N; i++)
    {
        // Traverse linked list at each index in the hash table
        while (table[i] != NULL)
        {
            // Store address of current node and move to next node
            node *current_node = table[i];
            table[i] = current_node->next;

            // Free memory allocated for current node
            free(current_node);
        }
    }
    return true;
}