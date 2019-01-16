/**
 *
 * File: constExample.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 2019-01-16
 * Time: 19:45
 *
 */

#include <stdio.h>

int main()
{
    const int someConst=100;

    int someNumber;

    printf("Give a number: ");
    scanf("%d", &someNumber);

    printf("This is the const: %d\n", someConst);
    printf("This is the variable: %d\n", someNumber);

    return 0;
}