// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[1])
{
  string word = argv[1];
  int j = strlen(word);
  int i;
  char new[j + 1];

  for (i = 0; i < j; i++)
  {
    if (word[i] == 'e')
    {
      new[i] = '3';
    }
    else if (word[i] == 'i')
    {
      new[i] = '1';
    }
    else if (word[i] == 'a')
    {
      new[i] = '6';
    }
    else if (word[i] == 'o')
    {
      new[i] = '0';
    }
    else
    {
      new[i] = word[i];
    }
  }

    new[j] = 0;

  printf("%s\n", new);
}
