// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"


//./speller dictionaries/small texts/cat.txt

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

int wordSum = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);

    for (node *ptr = table[index]; ptr != NULL; ptr = ptr->next)
    {
        if (strcasecmp(ptr->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int wordValue = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        wordValue += tolower(word[i]);
    }

    while(wordValue > 5000)
    {
        wordValue = wordValue % 5000;
    }
    return wordValue;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    while(fscanf(dict, "%s", word) != EOF)
    {
        wordSum++;

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            free(n);
            return false;
        }
        int index = hash(word);
        strcpy(n->word, word);

        if(table[index] == NULL)
        {
            table[index] = n;
            n->next = NULL;
        }
        else
        {
            n->next = table[index];
            table[index] = n;
        }
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return wordSum;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *tmp = NULL;
        for (node *ptr = table[i]; ptr != NULL; ptr = tmp)
        {
            tmp = ptr->next;
            free(ptr);
        }
    }
    return true;
}
