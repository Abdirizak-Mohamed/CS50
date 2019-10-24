#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int CArdTypeV(long n);
int CArdTypeA(long n);
int CArdTypeM(long n);
int validity(long n);
long cardno = 0;
int g = 0;

int main(void)
{
    bool  r = false;
    while (r == false)
    {
        cardno = get_long("Input Card No:");
        if ((cardno > 999999999999 && cardno < 10000000000000) || (cardno > 99999999999999 && cardno < 10000000000000000))
        {
            r = true;
        }
        else
        {
            r = false;
        }
    }



    int cardtypev = CArdTypeV(cardno);
    int cardtypea = CArdTypeA(cardno);
    int cardtypem = CArdTypeM(cardno);

    int valid = validity(cardno);

    if (valid != 1)
    {
        printf("INVALID\n");
    }

    if (cardtypev == 1 && valid == 1)
    {
        printf("VISA\n");
    }

    if (cardtypea == 1 && valid == 1)
    {
        printf("AMEX\n");
    }

    if (cardtypem == 1 && valid == 1)
    {
        printf("MASTERCARD\n");
    }

}

int validity(long n)
{
    for (int i = 1; i < 17; i++)
    {
        int h = n % 10;
        n = (n - h) / 10;
        int so = 0;
        if (i % 2 == 0)
        {
            if (h * 2 > 9)
            {
                so = (h * 2) % 10;
                h = (((h * 2) - so) / 10);
                g = g + h + so;
            }
            else
            {
                g = g + (h * 2);
            }
        }
        else
        {
            int qr = h;
            g = g + qr;
        }
    }
        if (g % 10 == 0)
        {
            return 1;
        }
        else
        {
            return 2;
        }
return 4;
}

    int CArdTypeV(long n)
    {
        int cv13a = n % 1000000000000;
        int cv16a = n % 1000000000000000;
        int cv13 = (n - cv13a) / 1000000000000;
        int cv16 = (n - cv16a) / 1000000000000000;

        if (cv16 == 4 || cv13 == 4)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    int CArdTypeA(long n)
    {
        int cv15a = n % 10000000000000;
        int cv15 = (n - cv15a) / 10000000000000;


        if (cv15 == 34 || cv15 == 37)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }

    int CArdTypeM(long n)
    {
        int cv16m = n % 100000000000000;
        int cv16 = (n - cv16m) / 100000000000000;


        if (cv16 > 50 && cv16 < 56)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
