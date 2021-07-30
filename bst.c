
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
/* Given a non-empty binary search
   tree, return the node
   with minimum key value found in
   that tree. Note that the
   entire tree does not need to be searched. */
struct node* inoderSuccessor(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
struct node* deleteNode(struct node* root, int data)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the data to be deleted
    // is smaller than the root's
    // data, then it lies in left subtree
    if (data < root->data)
        root->left = deleteNode(root->left, data);
 
    // If the data to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
 
    // if data is same as root's data,
    // then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct node* temp = inoderSuccessor(root->right);
 
        // Copy the inorder
        // successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
// Driver Code
int main()
{
	struct node* root = NULL;
	root = insert(root, 25);
	insert(root, 20);
	insert(root, 30);
	insert(root, 26);
	insert(root, 36);
	insert(root, 31);
	insert(root, 38);
	insert(root, 35);

	// print inoder traversal of the BST
	inorder(root);
	
	
    int item;
    int item2;
    int n;
    printf("Enter search item:->");
	scanf("%d",&item);
    // Function to find item in the tree
    struct node *found = search(root,item);

    if(found){
        printf("%d value is found in the tree\n",item); //searching
        printf("you wand to delete press 0 else 1\n");
        scanf("%d",&n);
        if(n==0){
           printf("Enter Delete item\n"); //deletion
	       scanf("%d",&item2);          //deletion
           root = deleteNode(root,item2); //deletion
           printf("Inorder traversal of the modified tree \n"); //deletion
           inorder(root); //deletion
         } 
        else
           printf("ok then");

    }
    else
        printf("%d value not found\n",item); //searching
        	
return 0;
}
