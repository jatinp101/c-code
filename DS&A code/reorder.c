/*
 *
 */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

void displayList(struct Node *head);
struct Node * destroyList(struct Node *head);
struct Node *createList(int startVal, int finishVal);

struct Node *reorderList(struct Node *head);

void main() 
{

struct Node *p = createList(3,13);

p = createList(3,13);
printf("\nCreated a list:\n");
displayList(p);
p =reorderList(p);
printf("Reordered list:\n");
displayList(p);
p = destroyList(p);

p = createList(3,12);
printf("\nCreated a list:\n");
displayList(p);
p =reorderList(p);
printf("Reordered list:\n");
displayList(p);
p = destroyList(p);

}

struct Node *reorderList(struct Node *head)
{
    if(!head || !head->next) { // if there is nothing in or after head
        return NULL;
    }
    struct Node *slow = head, *fast = head, *p=head, *q=head;
    //splitting list in half
    while(fast->next && fast->next->next) {
        slow = slow->next, fast = fast->next->next;
    }
    fast = slow->next, slow->next = NULL;
    p = fast, q = fast->next, fast->next = NULL;
    //reordering the list
    while(q)
    {
        struct Node *tem = q->next;
        q->next = p;
        p = q, q = tem;
    }
    q = head;
    while(q && p)
    {
        struct Node *tem1 = q->next, *tem2 = p->next;
        p->next = q->next;
        q->next = p;
        q = tem1, p = tem2;
    }
return head;
}


void displayList(struct Node *head)
{
printf("List: ");
for (struct Node *p=head; p!=NULL; p=p->next) {
    printf("->%d ",p->val);
}
printf("\n");
}

struct Node * destroyList(struct Node *head)
{
struct Node *p = head;
while (p!=NULL) {
	struct Node *next = p->next;
	free(p);
	p = next;
}
return NULL;
}

struct Node *createList(int startVal, int finishVal)
{
struct Node *head = NULL;  /* Head of the list */
struct Node *last = NULL;  /* Last node in the list */
for (int i=startVal; i<=finishVal; i++) {
    /* Create node */
    struct Node *p = (struct Node *) malloc(sizeof(struct Node));
    p->val = i;
    p->next = NULL;
    if (i == startVal) {
        head = p;
    }
    else {
	last->next = p;
    }
    last = p;
}
return head;
}


