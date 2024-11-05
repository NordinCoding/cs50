#include "helpers.h"
#include <math.h>

//./filter -b images/yard.bmp out.bmp

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float red;
    float green;
    float blue;
    float gray;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red = image[i][j].rgbtRed;
            green = image[i][j].rgbtGreen;
            blue = image[i][j].rgbtBlue;

            gray = (red + green + blue) / 3;

            gray = round(gray);

            image[i][j].rgbtRed = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtBlue = gray;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tmp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            tmp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = tmp;
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
            float redSum = 0;
            float greenSum = 0;
            float blueSum = 0;
            float counter = 0;

            for (int k = i-1; k <= i+1; k++)
            {
                for (int l = j-1; l <= j+1; l++)
                {
                    if(k > 0 && k < height && l > 0 && l < width)
                    {
                        redSum += copy[k][l].rgbtRed;
                        greenSum += copy[k][l].rgbtGreen;
                        blueSum += copy[k][l].rgbtBlue;
                        counter++;
                    }
                }
            }
            image[i][j].rgbtRed = redSum / counter;
            image[i][j].rgbtGreen = greenSum / counter;
            image[i][j].rgbtBlue = blueSum / counter;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
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
            for (int k = i-1; k <= i+1; k++)
            {
                for (int l = j-1; l <= j+1; l++)
                {

                }
            }

        }
    }
    return;
}
