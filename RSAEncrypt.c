#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int p, q, x, y, n, z, flag, t[100], e[100], d[100], temp[100], en[100];
char text[100];
void ce();
int prime(long int);
long int cd(long int);
void encrypt();
void decrypt();

int main()
{
    printf("Enter Prime Numbers");
    printf("\nValue of P: ");
    scanf("%d", &p);

    flag = prime(p);
    if (flag == 0)
    {
        printf("\nWrong Input");
        getch();
        exit(1);
    }

    printf("\nValue of Q: ");
    scanf("%d", &q);

    flag = prime(q);
    if (flag == 0 || p == q)
    {
        printf("\nWrong Input");
        getch();
        exit(1);
    }

    printf("\nEnter Text: ");
    fflush(stdin);
    scanf("%s", text);
    // printf("\nHello");

    for (x = 0; text[x] != NULL; x++)
        t[x] = text[x];

    // printf("\nHii");
    n = p * q;
    z = (p - 1) * (q - 1);
    // printf("\nHeyy");
    ce();
    // printf("\nHahaha");
    printf("\nPossible Values of E and D are ");
    for (x = 0; x < y - 1; x++)
        printf("\n %ld \t %ld", e[x], d[x]);

    encrypt();
    decrypt();
    getch();

    return 0;
}

int prime(long int pr)
{
    int x;
    y = sqrt(pr);

    for (x = 2; x <= y; x++)
    {
        if (pr % x == 0)
        {
            return 0;
        }
    }
    return 1;
}

void ce()
{
    int k;
    k = 0;

    for (x = 2; x < z; x++)
    {
        if (z % x == 0)
            continue;
        flag = prime(x);

        if (flag == 1 && x != p && x != q)
        {
            e[k] = x;
            flag = cd(e[k]);
            if (flag > 0)
            {
                d[k] = flag;
                k++;
            }
        }
        if (k == 99)

            break;
    }
}

long int cd(long int h)
{
    long int k = 1;
    while (1)
    {
        k = k + z;
        if (k % h == 0)
            return (k / h);
    }
}

void encrypt()
{

    long int pt, ct, key = e[0], k, len;

    x = 0;
    len = strlen(text);

    while (x != len)
    {
        pt = t[x];
        pt = pt - 96;
        k = 1;

        for (y = 0; y < key; y++)
        {
            k = k * pt;
            k = k % n;
        }

        temp[x] = k;
        ct = k + 96;
        en[x] = ct;
        x++;
    }

    en[x] = -1;
    printf("\nThe Encrypted Message is:");
    for (x = 0; en[x] != -1; x++)
    {
        printf("%c", en[x]);
    }
}

void decrypt()
{
    long int pt, ct, key = d[0], k;
    x = 0;

    while (en[x] != -1)
    {
        ct = temp[x];
        k = 1;
        for (y = 0; y < key; y++)
        {
            k = k * ct;
            k = k % n;
        }
        pt = k + 96;
        t[x] = pt;
        x++;
    }

    t[x] = -1;
    printf("\nThe Decrypted Message is:");
    for (x = 0; t[x] != -1; x++)
    {
        printf("%c", t[x]);
    }
}