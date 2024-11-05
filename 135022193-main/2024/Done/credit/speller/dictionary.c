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

// TODO: Choose number of buckets in hash table
const unsigned int N = 5000;

// Hash table
node *table[N];
int dictSum = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashIndex = hash(word);
    int len = strlen(word);

    // malloc space to copy word to and copy word to wordCpy
    char *wordCpy = malloc(len + 1);
    strcpy(wordCpy, word);

    // make copy of word all lowercase
    for (int i = 0; i < len; i++)
    {
        wordCpy[i] = tolower(wordCpy[i]);
    }

    // loop to check if current word is in dictionary
    for (node *tmp = table[hashIndex]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(wordCpy, tmp->word) == 0)
        {
            free(wordCpy);
            return true;
        }
    }

    free(wordCpy);
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int len = strlen(word);
    int sum = 0;

    for (int i = 0; i < len; i++)
    {
        sum = sum + toupper(word[i]);
    }

    while (sum > 5000)
    {
        sum = sum % 5000;
    }
    return sum;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // declare buffer for fscanf
    char buffer[LENGTH + 1];

    // open and store dictionary in file, close file and return false if failed
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open file, aborting load");
        fclose(file);
        return false;
    }

    // while loop for loading in 1 string at a time into the hash table
    while (fscanf(file, "%s", buffer) != EOF)
    {
        // allocating node and returning false if failed
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Malloc failed, aborting load");
            return false;
        }

        // declaring hashIndex to prevent unnecessary calls to hash()
        int hashIndex = hash(buffer);

        // detects if its beginning of linked list and stores current string if it is
        if (table[hashIndex] == NULL)
        {
            strcpy(n->word, buffer);
            n->next = NULL;
            table[hashIndex] = n;
        }
        // if not, we append new node into the existing linked list
        else
        {
            strcpy(n->word, buffer);
            n->next = table[hashIndex];
            table[hashIndex] = n;
        }
        dictSum++;
    }
    // close file and return true;
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dictSum;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            node *cursor = table[i];
            node *tmp = NULL;
            while (cursor != NULL)
            {
                tmp = cursor;
                cursor = cursor->next;
                free(tmp);
            }
        }
    }
    return true;
}
