#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int shift(char c);
int main(int argc, string argv[])
{
    if (argc != 2) //Validate keyword is one word
    {
        printf("Usage: ./vignere keyword \n");
    }
    
    for (int j = 0, n = strlen(argv[1]); j < n; j++)  //Validate all characters in keyword are letters
    {
        if ((isalpha(argv[1][j])) == false)
        {
            printf("Usage: ./vignere keyword \n");
            return 1;
        }        
    } 

    
    string plaintext = get_string("Plaintext:  "); //Enter Plaintext
    printf("Ciphertext: ");
    int k = (0); //Declare variable for counter of which letter of keyword
    for (int j = 0, n = strlen(plaintext); j < n; j++) //Go through each char and shift
    {
        if (k == strlen(argv[1])) //if counter is length of keyword reset
        {
            k = 0;
        }
        if isupper(plaintext[j]) 
            //If plaintext letter is upper shift word by value of keyword thats currenly selected then add one to counter 
        {
            printf("%c", (plaintext[j] - 'A' + shift(argv[1][k])) % 26 + 'A');
            k++;
        }
        else if islower(plaintext[j])
        {
            printf("%c", (plaintext[j] - 'a' + shift(argv[1][k])) % 26 + 'a');
            k++;
        }
    }         
    printf("\n"); 
}


//How to shift by where in the alphabet letter is 
int shift(char c)
{
    if isupper(c)
    {
        int a = c - 65;
        return (a);
    }    
    else if islower(c)
    {
        int a = c - 97;
        return (a);
    }
    else 
    {
        return 1;
    }
} 
