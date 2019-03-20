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
int insertAtStart(myStruct **head, DataElementType data) {
    myStruct *newNode;

    // Create new node and allocate memory
    newNode = (myStruct *) malloc(sizeof(myStruct));
    newNode->data = data;

    if (*head == NULL) { // If the list is empty
        newNode->next = NULL; // New node points to NULL (end of list)
        *head = newNode; // Head points to new node
    } else {
        newNode->next = (*head); // New node points to past head (first item)
        *head = newNode; // Current head points to new node
    }

    return 1;
}

/**
 * Insert new node at the of the list
 *
 * @param head
 * @param data
 * @return
 */
int insertAtTheEnd(myStruct **head, DataElementType data)
{
    myStruct *newNode, *current = *head;

    // Create new node and allocate memory
    newNode = (myStruct *) malloc(sizeof(myStruct));
    newNode->data = data;

    if(*head==NULL) { // If the list is empty
        newNode->next = NULL; // New node points to NULL (end of list)
        *head = newNode; // Head points to new node
    } else {
        while (current->next != NULL) { // Go to the end of the list
            current = current->next;
        }

        newNode->next = NULL;  // New node points to NULL (end of list)
        current->next = newNode; // Past last node points to new node
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

    // Scan all the list nodes until the end (NULL)
    while(current!=NULL) {
        printf(DETERMINANT, current->data); // Print data of current node
        current = current->next; // Go to the next node
    }

    printf("\n");
}


int main()
{
    myStruct *head = NULL;

//    insertAtStart(&head, 10);
//    insertAtStart(&head, 40);
//    insertAtStart(&head, 5);
//    insertAtStart(&head, 12);

    insertAtTheEnd(&head, 34);
    insertAtTheEnd(&head, 24);
    insertAtTheEnd(&head, 13);
    insertAtTheEnd(&head, 21);

    displayList(&head);

    return 0;
}
