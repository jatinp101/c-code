#include <stdio.h>
#include <stdlib.h>

struct Node {
	char data;
	struct Node *left;
	struct Node *right;
};

struct Node * createNode(char data);
struct Node * createTree(char encoding[], int *curr); 
void preorder(struct Node * root);
void inorder(struct Node * root);
void postorder(struct Node * root);
struct Node * delete(struct Node * root, char c);
struct Node * findSuccessor(struct Node* node);

void main()
{
char tree[] = "hca//d/fe///mk//rn/p///";

int curr = 0;
struct Node * root = createTree(tree, &curr);
printf("Initial Tree Encoding: %s\n", tree);
printf("Preorder: ");
preorder(root);
printf("\n");
printf("Inorder: ");
inorder(root);
printf("\n");
printf("Postorder: ");
postorder(root);
printf("\n");

root = delete(root,'f'); 
root = delete(root,'c'); 
root = delete(root,'m'); 
printf("\nDeleted 'f', 'c', and then 'm'\n");
printf("Preorder: ");
preorder(root);
printf("\n");
printf("Inorder: ");
inorder(root);
printf("\n");
printf("Postorder: ");
postorder(root);
printf("\n");

return;
}

/* Deletes node 'c' from tree 'root' */
struct Node * delete(struct Node * root, char c)
{
    if (root == NULL) return root; 
    if (c < root->data)   root->left = delete(root->left, c); 
    else if (c > root->data)  root->right = delete(root->right, c); 
    else { 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
       
        struct Node* temp = findSuccessor(root->right); 
        root->data = temp->data; 
        root->right = delete(root->right, temp->data); 
    } 
    return root; 
}
struct Node * findSuccessor(struct Node * node) 
{ 
    struct Node* current = node; 
    while (current && current->left != NULL) 
        current = current->left; 
    return current; 
} 

void preorder(struct Node * root)
{
if (root==NULL) return;
printf("%c", root->data);
preorder(root->left);
preorder(root->right);
}

void inorder(struct Node * root)
{
if (root==NULL) return;
inorder(root->left);
printf("%c", root->data);
inorder(root->right);
}

void postorder(struct Node * root)
{
if (root==NULL) return;
postorder(root->left);
postorder(root->right);
printf("%c", root->data);
}

struct Node * createNode(char data)
{
struct Node *p = (struct Node *) malloc(sizeof(struct Node));
p->left = NULL;
p->right = NULL;
p->data = data;
}

struct Node * createTree(char encoding[], int *curr) 
{
if (encoding[*curr] == '/') { 
	return NULL;
}
struct Node *p = createNode(encoding[*curr]);
(*curr)++;
p->left = createTree(encoding, curr);
(*curr)++;
p->right = createTree(encoding, curr);

return p;
}



