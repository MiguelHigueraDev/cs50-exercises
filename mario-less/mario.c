#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for pyramid size until it is valid (> 0)
    int size = 0;
    do
    {
        size = get_int("Height: ");
    }
    while (size < 1);

    // First there is a lot of spaces and one hash, and at the end there is only hashes
    // Unless user enters 1, in that case only a hash is printed
    for (int i = 0; i < size; i++)
    {
        // First print spaces
        for (int j = size - (i + 1); j > 0; j--)
        {
            printf(" ");
        }

        // Then print hashes
        for (int j = (i + 1); j > 0; j--)
        {
            printf("#");
        }

        // Add a new line to start the next row
        printf("\n");
    }
}
