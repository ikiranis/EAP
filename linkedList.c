/**
 *
 * File: linkedList.c
 *
 * Created by Yiannis Kiranis <std138327@ac.eap.gr>
 *
 * Date: 2019-03-19
 * Time: 23:16
 *
 * Tests at linked lists
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef int DataElementType;
const char DETERMINANT[] = "%d ";

// Main node structure
typedef struct list {
    DataElementType data;
    struct list *next;
} myStruct;


/**
 * Insert new node at the start of the list
 *
 * @param head
 * @param data
 * @return
 */
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

/**
 * Display list items
 *
 * @param head
 */
void displayList(myStruct **head)
{
    myStruct *current = *head;

    while(current!=NULL) {
        printf(DETERMINANT, current->data);
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
