/*Design , Develop and Implement a menu driven Program in C for the following
operations on
Binary Search Tree (BST) of Integers
a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
b. Traverse the BST in Inorder, Preorder and Post Order
c. Search the BST for a given element (KEY) and report the appropriate message
e. Exit
*/

/*
InOrder --> Left Root Right
    Algorithm
    ---------
        1. Traverse the left subtree ( call left subtree)
        2. Visit the root
        3. Traverse the right subtree ( call right subtree)

PreOrder --> Root Left RIght
    Algorithms 
    ----------
        1. Visit the root
        2. Traverse the left subtree 
        3. Traverse right subtree

PostOrder --> Left Right Root
    Algorithms 
    ----------
        1. Traverse the left subtree 
        2. Traverse right subtree
        3. Visit the root
        


*/

# include<stdio.h>
# include<stdlib.h>
int flag, i;
struct node
{
int data;
struct node* leftChild, *rightChild;
};
typedef struct node *NODE;
NODE createnode(int item)
{
NODE temp;
temp = (NODE)malloc(sizeof(struct node));
temp->data = item;
temp->leftChild = NULL;
temp->rightChild = NULL;
return temp;
}
void insertBST(NODE root, NODE newNode)
{
if(newNode->data == root->data)
{
printf("Key already exists\n");
i--;
return;
}
else if (newNode->data < root->data)
{
if (root->leftChild == NULL)
root->leftChild = newNode;
else
insertBST(root->leftChild, newNode);
}
else
{
if (root->rightChild == NULL)
root->rightChild = newNode;
else
insertBST(root->rightChild, newNode);
}
}

int search(NODE root, int key)
{
if(!root)
return -1;
if(key == root->data)
return 1;
if(key < root->data)
return search(root->leftChild, key);
else
return search(root->rightChild,key);
}
void inorder(NODE temp)
{
if (temp != NULL)
{
inorder(temp->leftChild);
printf("%d\t", temp->data);
inorder(temp->rightChild);
}
}
void preorder(NODE temp)
{
if (temp != NULL)
{
printf("%d\t", temp->data);
preorder(temp->leftChild);
preorder(temp->rightChild);
}
}
void postorder(NODE temp)
{
if (temp != NULL)
{
postorder(temp->leftChild);
postorder(temp->rightChild);
printf("%d\t", temp->data);
}
}
int main()
{
int choice,n,item;
int key,keyFound = 0;
NODE root=NULL,newNode;
while(1)
{
choice=0;
printf("\n-----------------MENU----------------------\n");
printf("1. Create a BST\n");
printf("2. Traverse a BST\n");

printf("3. Search a BST\n");
printf("4. Exit\n");
printf("-------------------------------------------\n");
printf("Enter choice : ");
scanf("%d", &choice);
switch(choice)
{
case 1: root= NULL;
printf("Enter the number of elements in the BST:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter the integer:");
scanf("%d",&item);
newNode = createnode(item);
if(root == NULL)
root = newNode;
else
insertBST(root,newNode);
}
break;
case 2: if (root == NULL)
{
printf("Tree is empty\n");
break;
}
else
{
printf("BST Preorder travsersal\n");
preorder(root);
printf("\nBST Inorder travsersal\n");
inorder(root);
printf("\nBST Postorder travsersal\n");
postorder(root);
break;
}
case 3: printf("Enter the search key:");
scanf("%d",&key);
keyFound = search(root,key);
if(keyFound == 1)
printf("Element %d is found in the BST",key);
else
printf("Element %d is not found in the BST",key);
break;
case 4: return;
default:printf("Wrong choice\n");
return;
}
}
}