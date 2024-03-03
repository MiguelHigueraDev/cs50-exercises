#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for pyramid size
    int size = 0;
    do
    {
        size = get_int("Height: ");
    }
    while (size < 1 || size > 8);

    for (int i = 0; i < size; i++)
    {
        // First print the left side
        // Print spaces
        for (int j = size - (i + 1); j > 0; j--)
        {
            printf(" ");
        }

        // Print hashes
        for (int j = (i + 1); j > 0; j--)
        {
            printf("#");
        }

        // Now print the right side, two spaces, then hashes
        printf("  ");
        for (int j = (i + 1); j > 0; j--)
        {
            printf("#");
        }

        printf("\n");
    }
}
