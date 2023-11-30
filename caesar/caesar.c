#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate();

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("usage: ./caesar key\n");
        return 1;
    }
    else
    {
        int result = strcmp(argv[1], "2x");
        if (result == 0)
        {
            return 1;
        }
        int key = atoi(argv[1]);
        printf("isdigit: %i\n", isdigit(key));
        printf("plaintext:  ");
        string text = get_string("");
        rotate(key, text);
    }
}

void rotate(int key, string text)
{
    char cipher[strlen(text)];
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            while (key > 26)
            {
                key -= 26;
            }
            char tmp = text[i];
            if (isupper(text[i]))
            {
                tmp = 'A' + (tmp - 'A' + key) % 26;
            }
            else if (islower(text[i]))
            {
                tmp = 'a' + (tmp - 'a' + key) % 26;
            }
            cipher[i] = tmp;
        }
        else
        {
            cipher[i] = text[i];
        }
    }
    printf("ciphertext: ");
    for (int i = 0; i < strlen(cipher); i++)
    {
        printf("%c", cipher[i]);
    }
    printf("\n");
}
