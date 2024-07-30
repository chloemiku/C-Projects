// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
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

const unsigned int N = 676;
unsigned int wordCount = 0;

// Hash table
node *table[N]; // array of first node pointers of each linked list

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashValue = hash(word);
    node *cursor = table[hashValue];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
            return true;
        else
            cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    char c1 = toupper(word[0]), c2 = '\0';
    int hashValue = 0;

    if (isalpha(word[1]))
    {
        c2 = toupper(word[1]);
        hashValue = (c1 - 'A') * 26 + (c2 - 'A');
    }

    else
        hashValue = (c1 - 'A') * 26;

    return hashValue;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }

    char c;
    int index = 0;
    node *newNode = NULL;

    // Read each word in the file
    while (fread(&c, sizeof(char), 1, source))
    {
        // Check for end-of-file
        if (feof(source))
        {
            break;
        }

        // Allocate memory for new node and word
        if (newNode == NULL)
        {
            newNode = malloc(sizeof(node));
            if (newNode == NULL)
            {
                fclose(source);
                return false;
            }
            memset(newNode->word, 0, sizeof(newNode->word));
        }

        // Add character to word if it's alphabetic or an apostrophe
        if (isalpha(c) || (c == '\'' && index > 0))
        {
            newNode->word[index++] = c;
        }

        // If it's the end of a word
        else if (index > 0)
        {
            newNode->word[index] = '\0';
            newNode->next = NULL;
            int bucket = hash(newNode->word);

            // Insert newNode into hash table
            if (table[bucket] == NULL)
            {
                table[bucket] = newNode;
            }
            else
            {
                newNode->next = table[bucket];
                table[bucket] = newNode;
            }

            // Reset index and newNode for next word
            index = 0;
            newNode = NULL;
            wordCount++;
        }
    }

    // Close dictionary file
    fclose(source);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int index = 0; index < N; index++)
    {
        node *cursor = table[index];

        while (cursor != NULL)
        {
            node *temp = cursor->next;
            free(cursor);
            cursor = temp;
        }

        table[index] = NULL;
    }
    return true;
}
