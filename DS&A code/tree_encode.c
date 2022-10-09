#include <stdlib.h>
#include <stdio.h>

#define LENGTH1 15
#define LENGTH2 15

struct node {
    int val;
    struct node * left;
    struct node * right;
};

int list1[LENGTH1] = {25,34,16,-1,80,-1,-1,-1,63,13,-1,-1,92,-1,-1};
int list2[LENGTH2] = {25,63,92,-1,-1,13,-1,-1,34,-1,16,80,-1,-1,-1};


struct node * create_node(int val);
void display_preorder(struct node * p);
void display_inorder(struct node * p);
struct node * create_tree(int list[], int length); 

void main()
{
struct node * tree = create_tree(list1, LENGTH1);
printf("Tree 1:\n");
printf("Preorder: ");
display_preorder(tree);
printf("\n");
printf("Inorder: ");
display_inorder(tree);
printf("\n");

struct node * tree2 = create_tree(list2, LENGTH2);
printf("Tree 2:\n");
printf("Preorder: ");
display_preorder(tree2);
printf("\n");
printf("Inorder: ");
display_inorder(tree2);
printf("\n");
}

/* Creates a tree from the encoded list */
struct node * create_tree(int list[], int length) 
{
    struct node *head;
    struct node *sub1 = NULL;
    struct node *sub2 = NULL;
    struct node * node1 = NULL;
    struct node * node2 = NULL;
    int i = length - 3;
    for (i; i> 0; i = i-3) {
        if (node1 == NULL) {
            struct node *temp = create_node(list[i]);
            struct node *left = create_node(list[i+1]);
            struct node *right = create_node(list[i+2]);
            temp->left = left;
            temp->right = right;
            node1 = temp;
        } else {
            struct node *temp = create_node(list[i]);
            struct node *left = create_node(list[i+1]);
            struct node *right = create_node(list[i+2]);
            temp->left = left;
            temp->right = right;
            node2 = temp; 
        }
        if (node1 != NULL && node2 != NULL) {
            i--;
            struct node *temp = create_node(list[i]);
            temp->left = node2;
            temp->right = node1;
            if (sub1 == NULL) {
                sub1 = temp;
            } else {
                sub2 = temp;
            }
            node1 = NULL;
            node2 = NULL;
        } 
    }
    head = create_node(list[0]);
    head->left = sub2;
    head->right = sub1;

return head;
}


/* Display values in a tree using preorder traversal */
void display_preorder(struct node * p)
{
if (p==NULL) return;
if (p->val != -1) printf("%d ",p->val);
display_preorder(p->left);
display_preorder(p->right);
}

/* Display values in a tree using inorder traversal */
void display_inorder(struct node * p)
{
if (p==NULL) return;
display_inorder(p->left);
if (p->val != -1) printf("%d ",p->val);
display_inorder(p->right);
}

/* Creates a node which has value 'va' and no children */
struct node * create_node(int val)
{
struct node * p = (struct node *) malloc(sizeof(struct node));
p->val = val;
p->left = NULL;
p->right = NULL;
return p;
}

