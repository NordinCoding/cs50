#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct person
{
    struct person *parents[2];
    char alleles[2];
} person;

int main(void) {
    int size = sizeof(person);

    printf("%d\n", size);
    return 0;
}
