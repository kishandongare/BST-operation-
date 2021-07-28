
//NAME = KISHAN DONGARE
//SUBJECT = DATA STRUCTURES

//BST INSERTION AND SEARCHING 


// C program to demonstrate insert
// operation in binary
// search tree.
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left, *right;
};

// A utility function to create a new BST node
struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(sizeof(struct node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node* root)
{
	if (root == NULL)
	{ 
		return; 
	}
	inorder(root->left);
	printf("%d \n", root->data);
	inorder(root->right);
	
}

/* A utility function to insert
a new node with given key in
* BST */
struct node* insert(struct node* node, int data)
{
	/* If the tree is empty, return a new node */
	if (node == NULL)
		return newNode(data);

	/* Otherwise, recur down the tree */
	if (data< node->data)
		node->left = insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right,data);

	/* return the (unchanged) node pointer */
	return node;
}

// C function to search a given key in a given BST
struct node* search(struct node* root, int data)
{
    // Base Cases: root is null or data is present at root
    if (root == NULL || root->data== data)
       return root;
    
    // data is greater than root's data
    if (root->data < data)
       return search(root->right,data);
 
    // data is smaller than root's data
    return search(root->left, data);
}
// Driver Code
int main()
{
	struct node* root = NULL;
	root = insert(root, 50);
	insert(root, 25);
	insert(root, 12);
	insert(root, 75);
	insert(root, 30);
	insert(root, 85);
	insert(root, 52);
	insert(root, 70);
	insert(root, 60);

	// print inoder traversal of the BST
	inorder(root);
	
	
    int item;
    printf("Enter search item:->");
	scanf("%d",&item);
    // Function to find item in the tree
    struct node *found = search(root,item);

    if(found)
        printf("%d value is found in the tree",item);
    else
        printf("%d value not found",item	
return 0;
}
