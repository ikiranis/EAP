/**
 *
 * File: stackList.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 2019-03-18
 * Time: 22:47
 *
 * Δοκιμές σε στοίβα με συνδεδεμένη λίστα
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int number;
    struct stack *previous;
} myStack;

/* Αρχικοποίηση μιας άδειας στοίβας */
void construct(myStack **top)
{
    *top = NULL;
}

void push(myStack **top, int number)
{
    myStack *temp = (myStack *) malloc(sizeof(*temp));

    if(temp==NULL) {
        printf("Δεν υπάρχει διαθέσιμη Μνήμη\n");
        return;
    }

    temp->previous = *top;
    temp->number = number;

    *top = temp;

}

/* Συνάρτηση που αφαιρεί ένα στοιχείο από τη στοίβα */
int pop(myStack **top)
{
    int x;
    myStack *temp;

    x = (*top)->number;
    temp = *top;
    *top = (*top)->previous;
    free(temp);

    return x;
}

/* Συνάρτηση που επιστρέφει το στοιχείο της κορυφής της στοίβας */
int peek(myStack *top)
{
    if (top==NULL) {
        return 0;
    }

    return top->number;
}

int main()
{
    myStack *top;

    construct(&top);

    push(&top, 12);
    push(&top, 10);
    push(&top, 16);
    push(&top, 13);
    push(&top, 20);

    printf("%d \n", pop(&top));
    printf("%d \n", pop(&top));
    printf("%d \n", pop(&top));
    printf("%d \n", pop(&top));
    printf("%d \n", pop(&top));

    return 0;
}