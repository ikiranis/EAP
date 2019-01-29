/**
 *
 * File: test.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 29/1/2019
 * Time: 1:14 πμ
 *
 */

#include <stdio.h>

#define N 3

void prompt(float (*pin)[N][N]);
void display(float (*pin)[N][N]);

int main()

{

    float pinakas[N][N];

    prompt(&pinakas);

    display(&pinakas);

}//end main


void prompt(float (*pin)[N][N]){

    int i,j;

    for(i=0;i<N;i++)  {

        for(j=0;j<N;j++)  {

            printf("dose arithmo: ");

            scanf("%f",pin[i][j]);

        }//end for

    }//end for

}//end prompt

void display(float (*pin)[N][N]){

    int i,j;

    for(i=0;i<N;i++)  {

        for(j=0;j<N;j++)  {

            printf("%2.1f\t", *pin[i][j]);


        }//end for

        printf("\n");

    }//end for

}//end prompt