#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // calculate average value off pixel / RGB
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            float avg = (blue + green + red);

            //set RGB to new AVG value (rounded)
            int avg_round = (avg / 3.0) + 0.5;

            image[i][j].rgbtRed = avg_round;
            image[i][j].rgbtGreen = avg_round;
            image[i][j].rgbtBlue = avg_round;
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

            // apply sepia calculation to pixel
            int sepiared = (red * .393 + green * .769 + blue * .189) + 0.5;
            int sepiagreen = (red * .349 + green * .686 + blue * .168) + 0.5;
            int sepiablue = (red * .272 + green * .534 + blue * .131) + 0.5;

            // check for 255 cap
            if (sepiared > 255)
            {
                sepiared = 255;
            }
            if (sepiagreen > 255)
            {
                sepiagreen = 255;
            }
            if (sepiablue > 255)
            {
                sepiablue = 255;
            }

            // apply new value to pixel
            image[i][j].rgbtRed = sepiared;
            image[i][j].rgbtGreen = sepiagreen;
            image[i][j].rgbtBlue = sepiablue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    // loading image into temp array
    for (int i = 0; i < height; i++)
    {
        int reflect = 0;
        for (int j = 0; j < width; j++)
        {
            temp[i][reflect] = image[i][j];
            reflect++;
        }
    }

    // loading initial array with temp values / reverse
    for (int i = 0; i < height; i++)
    {
        int count = width - 1;
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][count];
            count--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE box_blur[height][width];

    // copy original image into temp array
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            box_blur[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = 0.0;
            float green = 0.0;
            float blue = 0.0;
            int count = 0;

            // checking for corner and frame cases
            for (int row = i - 1; row <= i + 1; row++)
            {
                for (int col = j - 1; col <= j + 1; col++)
                {
                    if ((col < width) && (row < height) && (col >= 0) && (row >= 0))
                    {
                        red += box_blur[row][col].rgbtRed;
                        green += box_blur[row][col].rgbtGreen;
                        blue += box_blur[row][col].rgbtBlue;
                        count++;
                    }
                }
            }
            // rounded average value of pixel
            image[i][j].rgbtRed = round(red / count);
            image[i][j].rgbtGreen = round(green / count);
            image[i][j].rgbtBlue = round(blue / count);
        }
    }
    return;
}
