#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            int t = 0;
            int red = image[r][c].rgbtRed;
            int green = image[r][c].rgbtGreen;
            int blue = image[r][c].rgbtBlue;
            t = round(((float) red + green + blue) / 3);
            image[r][c].rgbtRed = t;
            image[r][c].rgbtGreen = t;
            image[r][c].rgbtBlue = t;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            int red = image[r][c].rgbtRed;
            int green = image[r][c].rgbtGreen;
            int blue = image[r][c].rgbtBlue;
            int newRed = round(.393 * (float) red + .769 * green + .189 * blue);
            int newGreen = round(.349 * (float) red + .686 * green + .168 * blue);
            int newBlue = round(.272 * (float) red + .534 * green + .131 * blue);
            if (newRed > 255)
            {
                newRed = 255;
            }

            if (newGreen > 255)
            {
                newGreen = 255;
            }

            if (newBlue > 255)
            {
                newBlue = 255;
            }
            image[r][c].rgbtRed = newRed;
            image[r][c].rgbtGreen = newGreen;
            image[r][c].rgbtBlue = newBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int r = 0; r < height; r++)
    {
        RGBTRIPLE temp[width];
        for (int c = 0; c < width; c++)
        {
            int red = image[r][c].rgbtRed;
            int green = image[r][c].rgbtGreen;
            int blue = image[r][c].rgbtBlue;
            int newC = width - c - 1;

            temp[newC].rgbtRed = red;
            temp[newC].rgbtGreen = green;
            temp[newC].rgbtBlue = blue;
        }

        for (int c = 0; c < width; c++)
        {
            image[r][c].rgbtRed = temp[c].rgbtRed;
            image[r][c].rgbtGreen = temp[c].rgbtGreen;
            image[r][c].rgbtBlue = temp[c].rgbtBlue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE output[height][width];
    int amt = 0;
    int red = 0;
    int green = 0;
    int blue = 0;
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            amt = 0;
            red = 0;
            green = 0;
            blue = 0;
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int newx = r + x;
                    int newy = c + y;
                    if (newx >= 0 && newx < height && newy >= 0 && newy < width)
                    {
                        amt++;
                        red += image[newx][newy].rgbtRed;
                        green += image[newx][newy].rgbtGreen;
                        blue += image[newx][newy].rgbtBlue;
                    }
                }
            }
            output[r][c].rgbtRed = round((float) red / amt);
            output[r][c].rgbtGreen = round((float) green / amt);
            output[r][c].rgbtBlue = round((float) blue / amt);
        }
    }
    // apply output array to original image array
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            image[r][c] = output[r][c];
        }
    }
    return;
}
