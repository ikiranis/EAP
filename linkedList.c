/**
 *
 * File: linkedList.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 2019-03-19
 * Time: 23:16
 *
 * Δοκιμές στις συνδεδεμένες λίστες
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef int DataElementType;

typedef struct list {
    DataElementType data;
    struct list *next;
} myStruct;


DataElementType insertAtStart(myStruct **head, DataElementType data)
{
    myStruct *newNode;

    newNode = (myStruct *) malloc(sizeof(myStruct));
    newNode->data = data;

    if(*head==NULL) {
        newNode->next = NULL;
        *head = newNode;
    } else {
        newNode->next = (*head);
        *head = newNode;
    }

    return 1;
}

void displayList(myStruct **head)
{
    myStruct *current = *head;

    while(current!=NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}


int main()
{
    myStruct *head = NULL;

    insertAtStart(&head, 10);
    insertAtStart(&head, 40);
    insertAtStart(&head, 5);
    insertAtStart(&head, 12);

    displayList(&head);

    return 0;
}
