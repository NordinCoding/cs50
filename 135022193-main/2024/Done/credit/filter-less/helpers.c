#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            float tmp = (red + green + blue) / 3;

            int grayscale = round(tmp);

            image[i][j].rgbtRed = grayscale;
            image[i][j].rgbtGreen = grayscale;
            image[i][j].rgbtBlue = grayscale;
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
            float red = image[i][j].rgbtRed;
            float green = image[i][j].rgbtGreen;
            float blue = image[i][j].rgbtBlue;

            float sepiaRed = (0.393 * red) + (0.769 * green) + (0.189 * blue);
            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = round(sepiaRed);
            }

            float sepiaGreen = (0.349 * red) + (0.686 * green) + (0.168 * blue);
            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = round(sepiaGreen);
            }

            float sepiaBlue = (0.272 * red) + (0.534 * green) + (0.131 * blue);
            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = round(sepiaBlue);
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            BYTE tmpR = image[i][j].rgbtRed;
            BYTE tmpG = image[i][j].rgbtGreen;
            BYTE tmpB = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width - (j + 1)].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - (j + 1)].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - (j + 1)].rgbtBlue;

            image[i][width - (j + 1)].rgbtRed = tmpR;
            image[i][width - (j + 1)].rgbtGreen = tmpG;
            image[i][width - (j + 1)].rgbtBlue = tmpB;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float sumRed = 0;
    float sumGreen = 0;
    float sumBlue = 0;
    float sumValid = 0;

    RGBTRIPLE copy[height][width];

    // nested loop for copying the original pixels to a copy 2D array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // nested loop for looping over the pixel grid
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // nested loop for creating the 3x3 grid around the pixel
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    // if statement to check each pixels validity
                    if (i + k >= 0 && j + l >= 0 && i + k <= height - 1 && j + l <= width - 1)
                    {
                        sumRed = sumRed + copy[i + k][j + l].rgbtRed;
                        sumGreen = sumGreen + copy[i + k][j + l].rgbtGreen;
                        sumBlue = sumBlue + copy[i + k][j + l].rgbtBlue;

                        sumValid++;
                    }
                }
            }
            // final calculation for the new average value of the pixel. And initiliazing variables
            // back to 0
            int averageRed = round(sumRed / sumValid);
            int averageGreen = round(sumGreen / sumValid);
            int averageBlue = round(sumBlue / sumValid);

            image[i][j].rgbtRed = averageRed;
            image[i][j].rgbtGreen = averageGreen;
            image[i][j].rgbtBlue = averageBlue;

            sumRed = 0;
            sumGreen = 0;
            sumBlue = 0;
            sumValid = 0;
        }
    }
    return;
}
