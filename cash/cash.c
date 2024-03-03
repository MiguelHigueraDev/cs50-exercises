#include <cs50.h>
#include <stdio.h>
#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

int getMinimumCoins(int changeOwed);
int main(void)
{
    // Prompt user for change owed
    int changeOwed = 0;
    do
    {
        changeOwed = get_int("Change owed: ");
    }
    while (changeOwed < 1);

    int minimumCoinAmount = getMinimumCoins(changeOwed);
    printf("%i\n", minimumCoinAmount);
}

int getMinimumCoins(int changeOwed)
{
    int coins = 0;

    // Check if the quotient of dividing changeOwed / coin is > 1 for all coins besides pennies
    // If no one of the "higher" coins is suitable, a penny will be used instead
    // Subtract that coin amount from changeOwed
    // And add a coin at the end of the loop
    while (changeOwed)
    {
        if (changeOwed / QUARTER >= 1)
        {
            changeOwed -= QUARTER;
        }
        else if (changeOwed / DIME >= 1)
        {
            changeOwed -= DIME;
        }
        else if (changeOwed / NICKEL >= 1)
        {
            changeOwed -= NICKEL;
        }
        else
        {
            changeOwed -= PENNY;
        }
        coins++;
    }

    return coins;
}
