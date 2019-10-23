#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, string argv[])
{
    //Validate an argument has been added 
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
   
    
    //ITERATE THROUGH KEY CONFIRMING ONLY DIGITS ENTERED
    for (int j = 0, n = strlen(argv[1]); j < n; j++)
    {
        if (isdigit(argv[1][j]) == false)
        {
            printf("Usage: ./caesar key\n");
            return 1;  
        }   
    }   

    
    //Shift Ascii letters by Argv[1] 
    string plaintext = get_string("Plain Text: ");
    printf("Ciphertext: ");
    for (int a = 0, n = strlen(plaintext); a < n; a++)
    {
        int k = atoi(argv[1]);
        if (isupper(plaintext[a]))
        {
            printf("%c", (((plaintext[a] - 'A' + k) % 26) + 'A')); //This is formula for loop 
        }
        else if (islower(plaintext[a]))
        {
            printf("%c", (((plaintext[a] - 'a' + k) % 26) + 'a')); //This is formula for loop 
        }
        else 
        {
            printf("%c", plaintext[a]);
        }
        if (a == n - 1)
        {
            printf("\n");
        }   
    }  
}


