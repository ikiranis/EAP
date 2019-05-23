/**
 *
 * File: bitwise_XOR.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 23/5/2019
 * Time: 4:19 πμ
 *
 * XOR Calculation
 *
 */


#include "stdio.h"
#define M 8

void bitwise_XOR(int a[], int b[], int N)
{
    int i;

    for(i=0;i<N;i++) {
        printf("%d", a[i] ^ b[i]);
    }

    printf("\n");
}

int main()
{
    int a[M] = {0,1,1,1,0,1,0,0};
    int b[M] = {1,1,0,1,1,1,1,0};

    bitwise_XOR(a, b, M);

    return 0;
}