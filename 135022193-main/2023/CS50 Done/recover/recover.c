#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    int BLOCK_SIZE = 512;
    int jpgAmount = 0;
    FILE *img = NULL;
    BYTE buffer[512];
    char filename[8];

    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, input) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpgAmount == 0)
            {
                sprintf(filename, "%03i.jpg", jpgAmount);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
                jpgAmount++;
            }
            else
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", jpgAmount);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
                jpgAmount++;
            }
        }
        else
        {
            if (img != NULL)
            {
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
            }
        }
    }

    fclose(input);
    fclose(img);
}