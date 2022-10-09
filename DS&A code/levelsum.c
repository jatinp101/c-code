/*
 * Your task is to implement 'levelsum'
 * which returns the sum of all the nodes at a particular level in 
 * the binary tree 'root'
 */

#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};


struct TreeNode * createTreeNode(int val); 
void destroyTreeNode(struct TreeNode * node);
void displayTreeNode(struct TreeNode * node);
struct TreeNode * buildTree();
void displayInorder(struct TreeNode * root);
void displayPreorder(struct TreeNode * root);
int levelsum(struct TreeNode * root, int level); 

void main()
{
struct TreeNode * root = buildTree();
printf("Inorder: ");
displayInorder(root);
printf("\n");
printf("Preorder: ");
displayPreorder(root);
printf("\n");
printf("Level %d: %d\n", 0, levelsum(root, 0));
printf("Level %d: %d\n", 1, levelsum(root, 1));
printf("Level %d: %d\n", 2, levelsum(root, 2));
printf("Level %d: %d\n", 3, levelsum(root, 3));
}

/* 
 * The following function doesn't work, so your task is to 
 * make it work
 */
int levelsum(struct TreeNode * root, int level) 
{
	int sum = 0;
	if(root == NULL)  
      return; 
   if( level == 0 ) 
   { 
      return root->val; 
   } 
   else
   {       
       sum += levelsum( root->left, level-1 ) ; 
      sum += levelsum( root->right, level-1 ) ; 
   } 
   return sum;
}



struct TreeNode * createTreeNode(int val) 
{
struct TreeNode * node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
node->val = val;
node->left = NULL;
node->right = NULL;
return node;
}

void destroyTreeNode(struct TreeNode * node)
{
free(node);
}

void displayTreeNode(struct TreeNode * node)
{
printf("%d", node->val);
}

struct TreeNode * buildTree()
{
struct TreeNode *p0 = createTreeNode(0);
struct TreeNode *p1 = createTreeNode(1);
struct TreeNode *p2 = createTreeNode(2);
struct TreeNode *p3 = createTreeNode(3);
struct TreeNode *p4 = createTreeNode(4);
struct TreeNode *p5 = createTreeNode(5);
struct TreeNode *p6 = createTreeNode(6);
struct TreeNode *p7 = createTreeNode(7);
struct TreeNode *p8 = createTreeNode(8);

p3->left = p5;
p3->right = p1;
p5->left = p6;
p5->right = p2;
p2->left = p7;
p2->right = p4;
p1->left = p0;
p1->right = p8;

return p3;
}

void displayInorder(struct TreeNode * root)
{
if (root == NULL) return;
displayInorder(root->left);
displayTreeNode(root);
printf(" ");
displayInorder(root->right);
}

void displayPreorder(struct TreeNode * root)
{
if (root == NULL) return;
displayTreeNode(root);
printf(" ");
displayPreorder(root->left);
displayPreorder(root->right);
}








