#include <cs50.h>
#include <stdio.h>

int main(void)                                     // Still smal miscalculation with Visa 4111111111111113

{
// prompt input - get Number:
    long number;
    do
    {
        number = get_long("Number: ");  //Asking for user input (13,15,16 digits)
    }
    while (number < -1 && number <= 6000000000000000);

    long cn = number;
    long nu = number;
    long sd = number;

// checksum check:
// take every other digit, multiply digits by 2 and add together.
// test number: test# 4003600000000014, 5555555555554444
// add to remaining digits.
// modulo has to equal 0.
    {
        {
            int a = cn % 100 / 10;
            int c = cn % 10000 / 1000;
            int e = cn % 1000000 / 100000;
            int g = cn % 100000000 / 10000000;
            int i = cn % 10000000000 / 1000000000;
            int k = cn % 1000000000000 / 100000000000;
            int m = cn % 100000000000000 / 10000000000000;
            int o = cn % 10000000000000000 / 1000000000000000;

            int a2 = a * 2;
            int c2 = c * 2;
            int e2 = e * 2;
            int g2 = g * 2;
            int i2 = i * 2;
            int k2 = k * 2;
            int m2 = m * 2;
            int o2 = o * 2;

            int a3 = a2 % 10;
            int a4 = a2 / 10;
            int c3 = c2 % 10;
            int c4 = c2 / 10;
            int e3 = e2 % 10;
            int e4 = e2 / 10;
            int g3 = g2 % 10;
            int g4 = g2 / 10;
            int i3 = i2 % 10;
            int i4 = i2 / 10;
            int k3 = k2 % 10;
            int k4 = k2 / 10;
            int m3 = m2 % 10;
            int m4 = m2 / 10;
            int o3 = o2 % 10;
            int o4 = o2 / 10;

            int luhn = a3 + a4 + c3 + c4 + e3 + e4 + g3 + g4 + i3 + i4 + k3 + k4 + m3 + m4 + o3 + o4;

// grabing second set of digits

            int b = cn % 10 / 1;
            int d = cn % 1000 / 100;
            int f = cn % 100000 / 10000;
            int h = cn % 10000000 / 1000000;
            int j = cn % 1000000000 / 100000000;
            int l = cn % 100000000000 / 10000000000;
            int n = cn % 10000000000000 / 1000000000000;
            int p = cn % 1000000000000000 / 100000000000000;

// modulo check for calulation outcome

            int check = luhn + b + d + f + h + j + l + n + p;
            int check1 = check % 2;

            if (check1 == 0)
            {
                int dn = 0;
                int ft = 0;

                while (number != 0)
                {
                    number = number / 10;
                    dn++;
                }


                if (dn >= 13 && dn <= 16)
                {
                    while (sd >= 99)
                    {
                        sd = sd / 10;
                    }
                    ft = (int) sd;

                    if (ft == 34 || ft == 37)
                    {
                        printf("AMEX\n");
                    }
                    else if (ft == 40 || ft == 41 || ft == 42 || ft == 43 || ft == 44 || ft == 45 || ft == 46 || ft == 47 || ft == 48 || ft == 49)
                    {
                        printf("VISA\n");
                    }
                    else if (ft == 51 || ft == 51 || ft == 52 || ft == 53 || ft == 54 || ft == 55)
                    {
                        printf("MASTERCARD\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
}


