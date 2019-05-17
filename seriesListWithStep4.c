/**
 *
 * File: seriesListWithStep4.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 17/5/2019
 * Time: 3:05 πμ
 *
 * Επαναληπτικές 2017 Θέμα 5α
 *
 */

#include "stdio.h"
#include "stdlib.h"

struct node {
    int num;
    struct node *next;
};

int main()
{
    struct node *list;
    struct node *temp;
    struct node *current;
    int i;

    list = malloc(sizeof(list));

    list->num = 1;
    list->next = NULL;

    current = list;

    for(i=5; i<=100; i+=4) {
        temp = malloc(sizeof(temp));

        temp->num = i;
        temp->next = NULL;
        current->next = temp;
        current = temp;
    }

}