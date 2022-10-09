#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

void display_list(struct Node *head);
void destroy_list(struct Node *head);
struct Node *create_list(int startVal, int finishVal);

struct Node *reverse(struct Node *head);
struct Node *remove_Kth_from_end(struct Node *head, int k);

void main() 
{
struct Node *p = create_list(3,13);
printf("\nCreated a list:\n");
display_list(p);
p = reverse(p);
printf("Reversed the list:\n");
display_list(p);
destroy_list(p);

p = create_list(3,13);
printf("\nCreated a list:\n");
display_list(p);
p =remove_Kth_from_end(p, 5);
printf("Removed 5-th from end:\n");
display_list(p);
destroy_list(p);
}

struct Node *reverse(struct Node *head)
{
 struct Node *prev = NULL;
 struct Node *curr = head;
 while (curr != NULL) {
     struct Node *temp = curr->next;
     curr->next = prev;
     prev = curr;
     curr = temp;
 }
 return prev;
}

struct Node *remove_Kth_from_end(struct Node *head, int k)
{
    int i = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        i++;
        temp = temp->next;
    }
    if (k > i) {
        return head;
    } else if (k == i) {
        return head->next;
    } else {
        int diff = i - k;           
        struct Node* prev = NULL;        
        struct Node* curr = head;          
        for(int j = 0;j < diff;j++){ 
            prev = curr;             
            curr = curr->next;       
        } 
        prev->next = curr->next; 
        return head; 
    }
}

void display_list(struct Node *head)
{
printf("List: ");
for (struct Node *p=head; p!=NULL; p=p->next) {
    printf("->%d ",p->val);
}
printf("\n");
}

void destroy_list(struct Node *head)
{
struct Node *p = head;
while (p!=NULL) {
	struct Node *next = p->next;
	free(p);
	p = next;
}
return;
}

struct Node *create_list(int startVal, int finishVal)
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

