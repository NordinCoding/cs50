#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Correct usage: ./recover (file)\n");
        return 1;
    }

    FILE *raw = fopen(argv[1], "r");
    {
        if (raw == NULL)
        {
            printf("Error opening file\n");
            fclose(raw);
            return 1;
        }
    }

    unsigned char buffer[512];
    int counter = 0;
    char filename[8];
    FILE *img = NULL;

    while(fread(buffer, 512, 1, raw) != 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(counter == 0)
            {
                sprintf(filename, "%03i.jpg", counter);

                img = fopen(filename, "w");

                if (img == NULL)
                {
                    printf("Error opening file\n");
                    fclose(img);
                    return 1;
                }
                fwrite(buffer, 512, 1, img);
                counter++;
            }
            else
            {
                fclose(img);

                sprintf(filename, "%03i.jpg", counter);

                img = fopen(filename, "w");
                if (img == NULL)
                {
                    printf("Error opening file\n");
                    fclose(img);
                    return 1;
                }

                fwrite(buffer, 512, 1, img);
                counter++;
            }
        }
        else
        {
            if(img != NULL)
            {
                fwrite(buffer, 512, 1, img);
            }
        }
    }


    fclose(img);
    fclose(raw);
    return 0;
}
