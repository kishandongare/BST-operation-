// C program to insert a node in AVL tree
#include<stdio.h>
#include<stdlib.h>

// An AVL tree node
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	int height;
};

// A utility function to get the height of the tree
int height(struct Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b)
{
	return (a > b)? a : b;
}

/* Helper function that allocates a new node with the given data and
	NULL left and right pointers. */
struct Node* newNode(int data)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially added at leaf
	return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	// Return new root
	return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

// Recursive function to insert a data in the subtree rooted
// with node and returns the new root of the subtree.
struct Node* insert(struct Node* node, int data)
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return (newNode(data));

	if (data < node->data)
		node->left = insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);
	else// Equal datas are not allowed in BST
	    return node;

	/* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
						height(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && data < node->left->data)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && data > node->right->data)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && data > node->left->data)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && data < node->right->data)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
 return node;
}

// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct Node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

/* Driver program to test above function*/
int main()
{
struct Node *root = NULL;

/* Constructing tree given in the above figure */
root = insert(root, 55);
root = insert(root, 60);
root = insert(root, 65);
root = insert(root, 20);
root = insert(root, 10);
root = insert(root, 40);
root = insert(root, 30);
root = insert(root, 45);
root = insert(root, 35);
root = insert(root, 50);
root = insert(root, 70);
root = insert(root, 75);
printf("Preorder traversal of the constructed AVL"
		" tree is \n");
preOrder(root);

return 0;
}
