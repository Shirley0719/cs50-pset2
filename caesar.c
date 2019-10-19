#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])

{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //Read the argv[1]
    string key = argv[1];

//Validating the key

    for (int i = 0, n = strlen(key); i < n ; i++)
    {
        if (!isdigit(key[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    }

//Convert the string to integer
    int k = atoi(key) ;

// Prompt user for the text

    string p = get_string("plaintext: ");
    printf("ciphertext: ");

//Check if every character in the plaintext is alphabetic
    {
        for (int i = 0, n = strlen(p); i < n ; i++)
        {
            if (!isalpha(p[i]))
            {
                printf("%c", p[i]);
            }
            //Preserve case
            else if (isupper(p[i]))
            {
                printf("%c", ((p[i] - 65 + k) % 26) + 65);
            }

            else if (islower(p[i]))
            {
                printf("%c", ((p[i] - 97 + k) % 26) + 97);
            }

        }
    }

    printf("\n");
}
