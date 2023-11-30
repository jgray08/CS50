#include <cs50.h>
#include <math.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int cents;
    do
    {
        cents = get_int("How much change is the customer owed? ");
    }
    while (cents < 0);

    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;

    while (cents >= 25)
    {
        cents = cents - 25;
        quarters++;
    }
    while (cents >= 10)
    {
        cents = cents - 10;
        dimes++;
    }
    while (cents >= 5)
    {
        cents = cents - 5;
        nickels++;
    }
    while (cents >= 1)
    {
        cents = cents - 1;
        pennies++;
    }
    int total = quarters + dimes + nickels + pennies;
    printf("%i\n", total);
}
