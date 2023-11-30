#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");
    int sentences = 0;
    int words = 1;
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
        if (text[i] == ' ')
        {
            words++;
        }
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    if (sentences == 0)
    {
        sentences++;
    }
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;
    int grade = round(0.0588 * L - 0.296 * S - 15.8);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
