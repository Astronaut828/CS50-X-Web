#include <cs50.h>
#include <stdio.h>
#include <ctype.h> // ctype.h library - check under / manual.cs50.io/#ctype.h
#include <math.h>
#include <string.h> // string library - check under / manual.cs50.io/#string.h

int count_letters(string text); // function to count letters from user input.
int count_words(string text); // function to count words from user input.
int count_sentences(string text); // function to count senteces from user input.

int main(void)
{
    // ask user for string (Text:) / use get_string.
    string text = get_string("Text: ");

    int letter_count = count_letters(text);
    int word_count = count_words(text);
    int sentence_count = count_sentences(text);

    // calculate reading level via Coleman-liau index / index = 0.0588 * L - 0.296 * S - 15.8
    float L = (((float)letter_count / (float)word_count) * 100);
    float S = (((float)sentence_count / (float)word_count) * 100);

    float index = ((0.0588 * L) - (0.296 * S));
    index = (index - 15.8);
    index = round(index); // rounding of index number 

    // print out reading grade level (Grade X) - round float to nearest int.
    // if 16 and up use (Grade 16+) if under 1 use (Before Grade 1).
    int i = index;
    if (i < 1)
    {
        printf("Before Grade 1\n");
    }
    if (i == 1)
    {
        printf("Grade 1\n");
    }
    if (i == 2)
    {
        printf("Grade 2\n");
    }
    if (i == 3)
    {
        printf("Grade 3\n");
    }
    if (i == 4)
    {
        printf("Grade 4\n");
    }
    if (i == 5)
    {
        printf("Grade 5\n");
    }
    if (i == 6)
    {
        printf("Grade 6\n");
    }
    if (i == 7)
    {
        printf("Grade 7\n");
    }
    if (i == 8)
    {
        printf("Grade 8\n");
    }
    if (i == 9)
    {
        printf("Grade 9\n");
    }
    if (i == 10)
    {
        printf("Grade 10\n");
    }
    if (i == 11)
    {
        printf("Grade 11\n");
    }
    if (i == 12)
    {
        printf("Grade 12\n");
    }
    if (i == 13)
    {
        printf("Grade 13\n");
    }
    if (i == 14)
    {
        printf("Grade 14\n");
    }
    if (i == 15)
    {
        printf("Grade 15\n");
    }
    if (i == 16)
    {
        printf("Grade 16\n");
    }
    if (i > 16)
    {
        printf("Grade Grade 16+\n");
    }

}
// count the number of letters, words and sentences in text (string).
// letter is any islower or isupper.
int count_letters(string text)
{
    string letters = text;
    int letter_count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        char count = letters[i];
        if (isupper(count))
        {
            letter_count ++;
        }
        if (islower(count))
        {
            letter_count ++;
        }
    }
    return letter_count;
}
// claculating wordcount
// words are seperated by space (check for isspace).
int count_words(string text)
{
    string words = text;
    int word_count = 1;

    for (int i = 0; i < strlen(text); i++)
    {
        char count = words[i];
        if (isspace(count))
        {
            word_count ++;
        }
    }
    return word_count;
}
// calculating sentence count
// sentence is seperated by (. ! ?).
int count_sentences(string text)
{
    string sentence = text;
    int sentence_count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        char count = sentence[i];
        if (count == '.')
        {
            sentence_count ++;
        }
        if (count == '!')
        {
            sentence_count ++;
        }
        if (count == '?')
        {
            sentence_count ++;
        }
    }
    return sentence_count;
}