/**
 *
 * File: ascii_chars.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 2019-01-16
 * Time: 19:28
 *
 */

#include <stdio.h>

int main()
{
    int myNumber;

    do {
        printf("Give a number from 66 to 99: ");
        scanf("%d", &myNumber);
    } while (myNumber<66 || myNumber>99);

    printf("%c %d\n", myNumber-1, myNumber-1);
    printf("%c %d\n", myNumber, myNumber);
    printf("%c %d\n", myNumber+1, myNumber+1);

    return 0;
}