#include <stdlib.h>
#include <stdio.h>

struct node {
   int val;
   struct node *left;
   struct node *right;
};

struct node * create_node(int val);
void destroy_tree(struct node * root);
int mirror(struct node * root);
int isMirror(struct node *root1, struct node *root2);

/* Creating trees */
struct node * create_tree1();
struct node * create_tree2();
struct node * create_tree3();
struct node * create_tree4();


void main()
{
struct node *root;
root = create_tree1();
printf("Tree 1 is symmetric: "); 
if (mirror(root) == 1) { 
    printf("Yes\n");
}
else {
    printf("No\n");
}
destroy_tree(root);

root = create_tree2();
printf("Tree 2 is symmetric: "); 
if (mirror(root) == 1) { 
    printf("Yes\n");
}
else {
    printf("No\n");
}
destroy_tree(root);

root = create_tree3();
printf("Tree 3 is symmetric: "); 
if (mirror(root) == 1) { 
    printf("Yes\n");
}
else {
    printf("No\n");
}
destroy_tree(root);

root = create_tree4();
printf("Tree 4 is symmetric: "); 
if (mirror(root) == 1) { 
    printf("Yes\n");
}
else {
    printf("No\n");
}
destroy_tree(root);

return;
}

int mirror(struct node * root)
{
    return isMirror(root, root); 
}

int isMirror(struct node *root1, struct node *root2) 
{   
    if (root1 == NULL && root2 == NULL) return 1; 
    if (root1 && root2 && root1->val == root2->val) 
        return isMirror(root1->left, root2->right) && 
               isMirror(root1->right, root2->left); 
    return 0; 
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
root->left->left = create_node(10);
root->left->right = create_node(34);
root->right = create_node(6);
root->right->left = create_node(34);
root->right->right = create_node(10);
return root;
}

struct node * create_tree2()
{
struct node * root = create_node(15);
root->left = create_node(6);
root->left->right = create_node(10);
root->left->right->left = create_node(7);
root->right = create_node(6);
root->right->left = create_node(10);
root->right->left->right = create_node(7);
return root;
}

struct node * create_tree3()
{
struct node * root = create_node(15);
root->left = create_node(6);
root->left->right = create_node(34);
root->right = create_node(6);
root->right->right = create_node(34);
return root;
}

struct node * create_tree4()
{
struct node * root = create_node(15);
root->left = create_node(6);
root->left->left = create_node(1);
root->left->right = create_node(10);
root->right = create_node(6);
return root;
}

