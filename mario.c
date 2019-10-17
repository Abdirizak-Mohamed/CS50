#include <cs50.h>
#include <stdio.h>

void brick(int n);
void space(int n);
int main(void)
{
    int height = 0; 
    bool z = false;
    while (z == false) 
    {
        int x = get_int("Height:");
        if (x > 8 || x < 1) 
        {
            z = false;    
        }
       
        else
        {
            z = true;
            height = x; 
        }
         
    } 
    for (int j = 0; j <= height; j++)
    {
        int d = height - j;
        if (j != 0)
        {
        space(d);
        brick(j);
        printf("\n"); 
        }
    }
}

void brick(int n)
{
    for (int i = 0; i < n; i++) 
    {
        printf("#");   
    }
}
void space(int n)
{
    for (int i = 0; i < n; i++) 
    {
        printf(" ");   
    }
}
