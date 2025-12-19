#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *insertVal(struct Node *root, int value);
struct Node *deleteVal(struct Node *root, int value);
struct Node *searchVal(struct Node *root, int value);
void inorder(struct Node *root);
void preorder(struct Node *root);
void postorder(struct Node *root);
//void levelorder(struct Node *root,);

#endif
