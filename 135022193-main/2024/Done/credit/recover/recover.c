#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    unsigned char buffer[512];
    int jpgSum = 0;
    FILE *img = NULL;
    char *filename = malloc(sizeof(char) * 8);

    if (argc != 2)
    {
        printf("correct use: ./recover card.raw\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        return 1;
    }

    bool result = true;

    while (result == true)
    {
        if (fread(buffer, 512, 1, file) < 1)
        {
            result = false;
            break;
        }

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", jpgSum);

            if (img == NULL)
            {
                img = fopen(filename, "w");
                fwrite(buffer, 512, 1, img);
            }
            else
            {
                fclose(img);
                img = fopen(filename, "w");
                fwrite(buffer, 512, 1, img);
            }
            jpgSum++;
        }
        else if (img != NULL)
        {
            fwrite(buffer, 512, 1, img);
        }
    }
    if (img != NULL)
    {
        fclose(img);
    }

    fclose(file);
    free(filename);
}
