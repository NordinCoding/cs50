#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            long averageRGB = round(((float) image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = averageRGB;
            image[i][j].rgbtGreen = averageRGB;
            image[i][j].rgbtRed = averageRGB;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            int tempRed = round(.393 * red + .769 * green + .189 * blue);
            int tempGreen = round(.349 * red + .686 * green + .168 * blue);
            int tempBlue = round(.272 * red + .534 * green + .131 * blue);

            if (tempRed >= 256)
            {
                tempRed = 255;
            }

            if (tempGreen >= 256)
            {
                tempGreen = 255;
            }

            if (tempBlue >= 256)
            {
                tempBlue = 255;
            }

            image[i][j].rgbtRed = tempRed;
            image[i][j].rgbtGreen = tempGreen;
            image[i][j].rgbtBlue = tempBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int mid = width / 2;
        for (int j = 0; j < round(mid); j++)
        {
            RGBTRIPLE temp[height][width];

            int val = width - (j + 1);

            temp[i][j] = image[i][j];
            image[i][j] = image[i][val];
            image[i][val] = temp[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            float average = 0;

            for (int k = (i - 1); k <= (i + 1); k++)
            {
                for (int l = (j - 1); l <= (j + 1); l++)
                {
                    if ((k >= 0 && k <= (height - 1)) && (l >= 0 && l <= (width - 1)))
                    {
                        sumRed += image[k][l].rgbtRed;
                        sumGreen += image[k][l].rgbtGreen;
                        sumBlue += image[k][l].rgbtBlue;
                        average++;
                    }
                }
            }
            int avgRed = round(sumRed / average);
            int avgGreen = round(sumGreen / average);
            int avgBlue = round(sumBlue / average);

            copy[i][j].rgbtRed = avgRed;
            copy[i][j].rgbtGreen = avgGreen;
            copy[i][j].rgbtBlue = avgBlue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }
    return;
}