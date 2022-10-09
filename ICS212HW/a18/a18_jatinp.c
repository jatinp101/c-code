/**
 * Linked list assignment.
 * @author Jatin P
 * @since 3/23/2018
 */

#include <stdio.h>
#include <stdlib.h> //has functions malloc() and free()
#include <string.h>
#include <time.h>

/**
 * node structure
 */
struct node{
    int data;
    struct node *next;
};

// node data type
typedef struct node Node;
typedef struct node* NodePointer;


//function prototypes 
void insertIntoLinkedList(int, NodePointer *);
void displayLinkedList(NodePointer);
int sum(NodePointer);
int count(NodePointer);

int main (void) {
    srand(time(NULL));
    NodePointer head = NULL;
    int total = 0;
    int counter = 0;
    int num = rand()% 101;
    int i = 0;
    int limit = rand() % (75 - 25 + 1) + 25;
    for (i = 0; i <= limit; i++) {
        num = rand() % (100 - 0 + 1) + 0;
        insertIntoLinkedList(num, &head);
    }
    displayLinkedList(head);
    total = sum(head);
    printf ("sum = %i\n",total);
    counter = count(head);
    printf ("Count = %i\n",counter);
    int avg = total/counter;
    printf ("Average = %i\n",avg);
    return 0;
}

void insertIntoLinkedList (int numOne, NodePointer *head2) {
    NodePointer newNode = NULL;
    NodePointer previous = NULL;
    NodePointer current = *head2;

    newNode = malloc(sizeof(Node));
    
    if(NULL != newNode){
        newNode->data = numOne;
        while(NULL != current && numOne > current->data){
            previous = current;
            current = current->next;
        }
        if(NULL == previous){
            newNode->next = current;
            *head2 = newNode;
        } else {
             previous->next = newNode;
             newNode->next = current;
        }
    }
}

void displayLinkedList(NodePointer current){
     if(NULL == current){
         printf("The linked list is empty!\n\n");
         return;
     }
     printf("linked list items: ");
     while(NULL != current){
         printf("%i, ", current->data);
         current = current->next;
     }
     printf("\n\n");
}

int sum (NodePointer current) {
    if (NULL == current) {
        printf ("The linked list is empty!\n\n");
        return;
    }
    int total = 0;
    while (NULL != current) {
        total += current->data;
        current = current->next;
    }
    return total;
}

int count (NodePointer current) {
    if (NULL == current) {
        printf ("The linked list is empty!\n\n");
        return;
    }
    int counter = 0;
    while (NULL != current) {
        counter++;
        current = current->next;
    }
    return counter;
}
