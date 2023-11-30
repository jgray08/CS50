#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int height;
    int spaces;
    do
    {
        height = get_int("How tall should your pyramids be? ");
    }
    while (height > 8 || height < 1);
    for (int i = 1; i < height + 1; i++)
    {
        spaces = height - i;
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }

        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < i; k++)
            {
                printf("#");
            }
            if (j == 0)
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}