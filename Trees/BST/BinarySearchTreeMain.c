#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.c"

struct Node *root=NULL;

int main(){
	int choice, val;
	while(1){
		printf("\nWhat function do you want to perform in the BST\n");
        printf("1. Insert element\n");
        printf("2. Search for element\n");
        printf("3. Delete element\n");
        printf("4. Inorder traversal (DFS)\n");
        printf("5. Preorder traversal (DFS)\n");
        printf("6. Postorder traversal (DFS)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root=insertVal(root, val);
				printf("Inserted %d\n", val);
                break;
                
            case 2:
            	printf("Enter value to search: ");
                scanf("%d", &val);
                if(searchVal(root, val)!=NULL) printf("Element is present in tree");
                else printf("Element not found");
                break;
                
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root=deleteVal(root, val);
				printf("Deleted %d\n", val);
                break;
                
            case 4:
            	printf("Inorder: ");
                inorder(root);
                break;            
            case 5:
            	printf("Preorder: ");
            	preorder(root);
            	break;            
            case 6:
            	printf("Postorder: ");
            	postorder(root);
                break;
            case 7:
            	printf("Exiting\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
