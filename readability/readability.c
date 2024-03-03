#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int countLetters(string text);
int countWords(string text);
int countSentences(string text);
float calculateIndex(float averageLetters, float averageSentences);

int main(void)
{
    // Prompt the user for text
    string text = get_string("Text: ");

    // Count letters, words, and sentences
    int letters = countLetters(text);
    int words = countWords(text);
    int sentences = countSentences(text);

    // Average number of letters per 100 words
    float averageLetters = ((float) letters / words) * 100.0;

    // Average number of sentences per 100 words
    float averageSentences = ((float) sentences / words) * 100.0;

    // Coleman-Liau index calculation
    float index = calculateIndex(averageLetters, averageSentences);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        // Round index to nearest whole number
        printf("Grade %i\n", (int) round(index));
    }
}

int countLetters(string text)
{
    int letters = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // Checks if the specified char is a-z or A-Z
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int countWords(string text)
{
    // Words start at 1 because the last word doesn't have any spaces.
    int words = 1;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

int countSentences(string text)
{
    int sentences = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}

float calculateIndex(float averageLetters, float averageSentences)
{
    return 0.0588 * averageLetters - 0.296 * averageSentences - 15.8;
}
