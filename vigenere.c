#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int shift(char c);

//Beginning of the program - get the key from the user
int main(int argc, string argv[])

{
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }


// Read the key
    string key = argv[1];

//validating the key
    {
        for (int i = 0, n = strlen(key); i < n ; i++)
            if (!isalpha(key[i]))
            {
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }
    }

//Prompt user for the plaintext

    string p = get_string("plaintext: ");
//Enciper
    printf("ciphertext: ");
    {
        for (int i = 0, j = 0, n = strlen(p), l = strlen(key); i < n; i++)
        {
            //Preserve the case
            string t;
            if (isupper(p[i]))
            {

                printf("%c", (p[i] - 65 + shift(key[j % l])) % 26 + 65);
                j++;
            }

            else if (islower(p[i]))
            {

                printf("%c", (p[i] - 97 + shift(key [j % l])) % 26 + 97);
                j++;
            }

            else
            {
                printf("%c", p[i]);
            }
        }
    }
    printf("\n");

}


//Declaration of the shift function

int shift(char c)

{
    return tolower(c) - 97;

}
