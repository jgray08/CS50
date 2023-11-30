#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int starting;
    int ending;
    do
    {
        starting = get_int("What is the starting population? ");
    }
    while (starting < 9);

    // TODO: Prompt for end size
    do
    {
        ending = get_int("What is the ending population? ");
    }
    while (ending < starting);
    // TODO: Calculate number of years until we reach threshold

    int pass;
    int new;
    int population = starting;
    int years = 0;
    do
    {
        pass = population / 4;
        new = population / 3;
        population = population + new - pass;
        years++;
    }
    while (population < ending);
    if (starting == ending)
    {
        printf("Years: 0\n");
    }
    else
    {
        printf("Years: %i\n", years);
    }

    // TODO: Print number of years
}
