#include <stdio.h>
#define MAX 50

void stuff(const char ip[], char result[])
{
    int i, j, count = 0;
    for (i = 0, j = 0; ip[i] != '\0'; i++, j++)
    {
        result[j] = ip[i];
        if (ip[i] == '1')
        {
            count++;
            if (count == 5)
            {
                result[++j] = '0';
                count = 0;
            }
        }
        else
            count = 0;
    }
    result[j] = '\0';
}

void destuff(const char stuffed[], char result[])
{
    int i, j, count = 0;
    for (i = 0, j = 0; stuffed[i] != '\0'; i++, j++)
    {
        result[j] = stuffed[i];
        if (stuffed[i] == '1')
        {
            count++;
            if (count == 5)
            {
                count = 0;
                i++;
            }
        }
        else
            count = 0;
    }
    result[j] = '\0';
}

int main()
{
    char ip[MAX];
    char stuffed[MAX * 2];
    char destuffed[MAX];

    printf("Enter the bits: \n");
    scanf("%s", ip);

    stuff(ip, stuffed);
    printf("Bits after stuffing: \n%s\n", stuffed);

    destuff(stuffed, destuffed);
    printf("Bits after de-stuffing: \n%s\n", destuffed);

    return 0;
}
