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

#define ARRAY_LENGTH 12

// Main node structure
typedef struct list {
    DataElementType data;
    struct list *next;
} myStruct;

/**
 * Return 1 if list is empty
 *
 * @param head
 * @return
 */
int isEmpty(myStruct **head)
{
    if(*head==NULL) {
        return 1;
    }

    return 0;
}

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
int displayList(myStruct **head)
{
    myStruct *current = *head;

    if(isEmpty(head)) {
        return 0;
    }

    // Scan all the list nodes until the end (NULL)
    while(current!=NULL) {
        printf(DETERMINANT, current->data); // Print data of current node
        current = current->next; // Go to the next node
    }

    printf("\n");

    return 0;
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

    if(isEmpty(head)) {
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

    if(isEmpty(head)) {
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

/**
 * Search element in list and return the position
 *
 * @param head
 * @param hay
 * @return
 */
DataElementType searchForElement(myStruct **head, DataElementType hay)
{
    myStruct *current = *head;
    int position = 1;

    if(isEmpty(head)) {
        return 0;
    }

    // Search for element
    while ( (current->next != NULL) && (current->data != hay)) {
        current = current->next;
        position++;
    }

    if(current->data == hay) {
        return position;
    }

    return 0;

}

/**
 * Search how many times an element exist in a list
 *
 * @param head
 * @param hay
 * @return
 */
int countForItems(myStruct **head, DataElementType hay)
{
    myStruct *current = *head;
    int counter = 0;

    if(isEmpty(head)) {
        return 0;
    }

    // Search for element
    while (current->next != NULL) {
        current = current->next;

        if(current->data == hay) {
            counter++;
        }
    }

    return counter;

}

/**
 * Copy array items to a list
 *
 * @param array
 * @param head
 */
void copyArrayToList(DataElementType array[], myStruct **head, int arrayLength)
{
    int i;

    for(i=0; i<arrayLength; i++) {
        insertAtTheEnd(head, array[i]);
    }
}


int main()
{
    myStruct *head = NULL;
    int searchedPosition, searchedElements;
    DataElementType array[ARRAY_LENGTH] = {1,5,4,10,45,23,43,32,24,23,12,65};

//    insertAtStart(&head, 10);
//    insertAtStart(&head, 40);
//    insertAtStart(&head, 5);
//    insertAtStart(&head, 12);

//    insertAtTheEnd(&head, 34);
//    insertAtTheEnd(&head, 24);
//    insertAtTheEnd(&head, 21);
//    insertAtTheEnd(&head, 13);
//    insertAtTheEnd(&head, 21);
//
//    displayList(&head);

//    deleteNodeFromNPosition();
//    searchElementAndDeleteNode(&head, 24);

//    if( (searchedPosition = searchForElement(&head, 21)) ) {
//        printf("Element founded in %d position", searchedPosition);
//    }

//    if( (searchedElements = countForItems(&head, 21)) ) {
//        printf("Element founded %d times", searchedElements);
//    }

    copyArrayToList(array, &head, ARRAY_LENGTH);

    displayList(&head);

    return 0;
}
