#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

struct Node *createNew(int value){
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=value;
	temp->left=temp->right=NULL;
	return temp;
}

struct Node *searchVal(struct Node *root, int num){
	if(root==NULL || root->data==num) return root;
	if(root->data<num) return searchVal(root->right, num);
	return searchVal(root->left, num);
}

struct Node *insertVal(struct Node *root, int value){
	if(root==NULL) return createNew(value);
	if(value < root->data) root->left=insertVal(root->left, value);
	else if(value > root->data) root->right=insertVal(root->right, value);
	return root;
}

struct Node *findMin(struct Node *root){
	if(root==NULL) return NULL;
	else if(root->left!=NULL) return findMin(root->left);
	return root;
}

struct Node *deleteVal(struct Node *root, int value){
	if(root==NULL) return NULL;
	else if(value> root->data) root->right=deleteVal(root->right, value);
	else if(value<root->data) root->left=deleteVal(root->left, value);
	else{
		if(root->right==NULL && root->left==NULL){
			free(root);
			return NULL;
		}else if(root->right==NULL || root->left==NULL){
			struct Node *temp;
			if(root->right==NULL){
				temp=root->left;
			}else{
				temp=root->right;
			}free(root);
			return temp;
		}else{
			struct Node *temp=findMin(root->right);
			root->data=temp->data;
			root->right=deleteVal(root->right, temp->data);
		}
		
	}return root;
}

void inorder(struct Node *root){
	if(root!=NULL){
		inorder(root->left);
		printf(" %d ", root->data);
		inorder(root->right);
	}
}

void preorder(struct Node *root){
	if(root!=NULL){
		printf(" %d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct Node *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf(" %d ",root->data);
	}
}
