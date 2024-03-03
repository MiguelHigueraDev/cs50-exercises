#include <cs50.h>
#include <stdio.h>

/**
 * Checks if a credit card number is valid using Luhn's algorithm.
 * Outputs INVALID if the number provided is not a valid credit card
 * or AMEX, VISA, MASTERCARD if is valid.
 */

int getEveryOtherDigitSum(long ccNumber);
int getFinalSum(int sum, long ccNumber);
bool checkLastDigit(int sum);
int countDigits(long ccNumber);
int getFirstTwoDigits(long ccNumber);
int getFirstDigit(long ccNumber);
string getCreditCardCompany(long ccNumber);

int main(void)
{
    // Prompt user for credit card number
    long ccNumber = get_long("Number: ");

    // Multiply every other digit
    int everyOtherDigitSum = getEveryOtherDigitSum(ccNumber);

    // Add all the rest of the digits that weren't multiplied to the sum
    int finalSum = getFinalSum(everyOtherDigitSum, ccNumber);

    // Checks if the credit card number is valid
    bool valid = checkLastDigit(finalSum);
    // If invalid, print "INVALID"
    if (!valid)
    {
        printf("INVALID\n");
    }
    else
    {
        // Get the credit card company
        printf("%s", getCreditCardCompany(ccNumber));
    }
}

int getEveryOtherDigitSum(long ccNumber)
{
    // Store a boolean so only every other digit is checked
    bool check = false;
    int sum = 0;
    while (ccNumber)
    {
        // This will only check every other digit (thanks to the boolean)
        if (check)
        {
            // Multiply every other digit by two
            int product = (ccNumber % 10) * 2;
            // Split product into its digits and add them to the sum
            while (true)
            {
                int digit = product % 10;
                sum += digit;
                // Break the loop in case that was the last digit.
                if ((product % 10 == digit) && product < 10)
                {
                    break;
                }
                // Continue with the remaining digit(s).
                else
                {
                    product /= 10;
                }
            }
        }
        // Remove last digit from number
        ccNumber /= 10;
        // Toggle the boolean
        check = !check;
    }
    return sum;
}

int getFinalSum(int sum, long ccNumber)
{
    // This works similarly to getEveryOtherDigitSum(), except that it selects the rest of the numbers
    // and it doesn't multiply the digits.
    bool check = true;
    while (ccNumber)
    {
        if (check)
        {
            sum += ccNumber % 10;
        }

        ccNumber /= 10;
        check = !check;
    }

    return sum;
}

bool checkLastDigit(int sum)
{
    return sum % 10 == 0;
}

string getCreditCardCompany(long ccNumber)
{
    /**
     * AMEX: 15 digits, starts with 34 or 37
     * MasterCard: 16 digits, starts with 51, 52, 53, 54, or 55
     * Visa: 13 or 16 digits, starts with 4
     */
    int numberOfDigits = countDigits(ccNumber);
    int firstTwoDigits = getFirstTwoDigits(ccNumber);

    if (numberOfDigits == 15 && (firstTwoDigits == 34 || firstTwoDigits == 37))
    {
        return "AMEX\n";
    }
    else if (numberOfDigits == 13)
    {
        if (getFirstDigit(ccNumber) == 4)
        {
            return "VISA\n";
        }
        else
        {
            return "INVALID\n";
        }
    }
    else if (numberOfDigits == 13 || numberOfDigits == 16)
    {
        if (getFirstDigit(ccNumber) == 4)
        {
            return "VISA\n";
        }
        else if (firstTwoDigits == 51 || firstTwoDigits == 52 || firstTwoDigits == 53 || firstTwoDigits == 54 ||
                 firstTwoDigits == 55)
        {
            return "MASTERCARD\n";
        }
        else
        {
            return "INVALID\n";
        }
    }
    else
    {
        return "INVALID\n";
    }
}

int countDigits(long ccNumber)
{
    int count = 0;
    while (ccNumber)
    {
        count++;
        ccNumber /= 10;
    }
    return count;
}

int getFirstTwoDigits(long ccNumber)
{
    while (ccNumber > 99)
    {
        ccNumber /= 10;
    }

    return ccNumber;
}

int getFirstDigit(long ccNumber)
{
    while (ccNumber > 9)
    {
        ccNumber /= 10;
    }

    return ccNumber;
}
