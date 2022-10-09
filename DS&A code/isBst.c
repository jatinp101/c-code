#include <stdlib.h>
#include <stdio.h>

struct node {
   int val;
   struct node *left;
   struct node *right;
};

struct node * create_node(int val);
void destroy_tree(struct node * root);
int is_bst(struct node * root);

/* Creating trees */
struct node * create_tree1();
struct node * create_tree2();
struct node * create_tree3();
struct node * create_tree4();

/* Helper functions*/
int max_val(int a, int b); /* Returns max value */
int min_val(int a, int b); /* Returns min value */
void helper(struct node * root, int* stack, int *size); /*Helps figure out whether tree is a BST*/


void main()
{
struct node *root;
root = create_tree1();
printf("Tree 1 is a binary search: "); 
if (is_bst(root) == 1) { 
    printf("Yes\n");
}
else {
    printf("No\n");
}
destroy_tree(root);

root = create_tree2();
printf("Tree 2 is a binary search: "); 
if (is_bst(root) == 1) { 
    printf("Yes\n");
}
else {
    printf("No\n");
}
destroy_tree(root);

root = create_tree3();
printf("Tree 3 is a binary search: "); 
if (is_bst(root) == 1) { 
    printf("Yes\n");
}
else {
    printf("No\n");
}
destroy_tree(root);

root = create_tree4();
printf("Tree 4 is a binary search: "); 
if (is_bst(root) == 1) { 
    printf("Yes\n");
}
else {
    printf("No\n");
}
destroy_tree(root);

return;
}

int is_bst(struct node * root)
{
    int *stack=NULL;
    int size = 0, i;
    int success = 1;
    
    if(root==NULL)
        return 1;
    
    stack = (int*)malloc(10240*sizeof(int));
    helper(root,stack,&size);
    
    for(i=1;i<size;i++)
    {
        if(stack[i-1] >= stack[i])
        {
            success = 0;
            break;
        }
    }
    
    free(stack);
    
    return success;
}

void helper(struct node * root, int* stack, int *size)
{
    if(root==NULL)
        return;
    
    helper(root->left, stack, size);
    stack[(*size)++] = root->val;
    helper(root->right, stack, size);
}

struct node * create_node(int val)
{
struct node *p = (struct node *) malloc(sizeof(struct node));
p->val = val;
p->left = NULL;
p->right = NULL;
return p;
}

void destroy_tree(struct node * root)
{
if (root==NULL) return;
destroy_tree(root->left);
destroy_tree(root->right);
free(root);
return;
}

struct node * create_tree1()
{
struct node * root = create_node(15);
root->left = create_node(6);
root->right = create_node(30);
root->right->left = create_node(10);
root->right->right = create_node(34);
return root;
}

struct node * create_tree2()
{
struct node * root = create_node(15);
root->left = create_node(6);
root->left->right = create_node(10);
root->left->right->left = create_node(7);
root->right = create_node(30);
root->right->left = create_node(22);
root->right->right = create_node(34);
return root;
}

struct node * create_tree3()
{
struct node * root = create_node(15);
root->left = create_node(6);
root->right = create_node(30);
root->right->left = create_node(10);
root->right->left->left = create_node(8);
root->right->left->right = create_node(12);
root->right->right = create_node(34);
return root;
}

struct node * create_tree4()
{
struct node * root = create_node(15);
root->left = create_node(6);
root->left->left = create_node(1);
root->left->right = create_node(10);
root->right = create_node(30);
return root;
}

int max_val(int a, int b)
{
if (a > b) return a;
else return b;
}

int min_val(int a, int b)
{
if (a > b) return b;
else return a;
}

