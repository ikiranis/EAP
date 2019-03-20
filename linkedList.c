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

/**
 * Delete node from n position of the list
 *
 * @param head
 * @param nPosition
 * @return
 */
int deleteNodeFromNPosition(myStruct **head, int nPosition)
{
    myStruct *current = *head, *next, *previous = *head;
    int currentPosition = 1;

    if(*head==NULL) {
        return 0;
    }

    // Go to nPosition
    while ( (current->next != NULL) && (currentPosition < nPosition)) {
        previous = current;
        current = current->next;
        currentPosition++;
    }

    // If current is NOT the last node
    if(current->next != NULL) {
        next = current->next; // Get the next node

        // Copy next to current and delete
        *current = *next;
        free(next);
    } else { // If current is the last node
        // Previous points to NULL and delete current node
        previous->next = NULL;
        free(current);
    }

    return 1;
}

/**
 * Search for hay and delete the node
 *
 * @param head
 * @param hay
 * @return
 */
int searchElementAndDeleteNode(myStruct **head, DataElementType hay)
{
    myStruct *current = *head, *previous = *head;

    if(*head==NULL) {
        return 0;
    }

    // Search for element
    while ( (current->next != NULL) && (current->data != hay)) {
        previous = current;
        current = current->next;
    }

    // If element founded
    if(current->data == hay) {
        // Previous points to next node of current and delete current
        if(previous == current) { // If we are in first node
            *head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }

    return 1;
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

//    deleteNodeFromNPosition();
    searchElementAndDeleteNode(&head, 24);

    displayList(&head);


    return 0;
}
