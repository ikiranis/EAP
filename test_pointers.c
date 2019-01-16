/**
 *
 * File: test_pointers.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 2019-01-16
 * Time: 17:38
 *
 */

#include <stdio.h>

int main()
{
    int i, *myPointer;

    i = 10;

    myPointer = &i;

    printf("%d\n", *myPointer);

    return 0;
}