/*Lab Program 8
Design, Develop and Implement a menu driven Program in C for the following operations on Doubly
Linked List (DLL) of Employee Data with the fields: SSN, Name, Dept., Designation, Salary, Ph No.
a. Create a DLL of N Employees Data by using end insertion.
b. Display the status of DLL and count the number of nodes in it.
c. Perform Insertion and Deletion at End of DLL.
d. Perform Insertion and Deletion at Front of DLL
e. Demonstrate how this DLL can be used as Double Ended Queue
f. Exit

Theory:
Doubly linked list is a linked data structure that consists of a set of sequentially linked records called
nodes. A doubly linked list whose nodes contain three fields: an integer value, the link to the next
node, and the link to the previous node. In a doubly linked list, each node contains two links the first

link points to the previous node and the next link points to the next node in the sequence. The two-
node links allow traversal of the list in either direction. While adding or removing a node in a doubly

linked list requires changing more links than the same operations on a singly linked list, the operations
are simpler and potentially more efficient (for nodes other than first nodes) because there is no need
to keep track of the previous node during traversal or no need to traverse the list to find the previous
node, so that its link can be modified.
*/
#include<stdio.h>
#include<stdlib.h>
int count;
struct node
{
int ssn;
float sal;
char name[20],dept[10],desg[20],phno[15];
struct node *llink;
struct node *rlink;
};
typedef struct node *NODE;
NODE first=NULL;

NODE getnode()
{
NODE x;
x = (NODE)malloc(sizeof(struct node));
return x;
}

NODE create_node()
{
NODE temp;
temp = getnode();
printf("Enter Employee Details : \n");
printf("Enter SSN : ");
scanf("%d", &(temp->ssn));
printf("Enter Name : ");
scanf("%s", temp->name);
printf("Enter Department : ");
scanf("%s", temp->dept);
printf("Enter Designation : ");
scanf("%s", temp->desg);
printf("Enter Salary : ");
scanf("%f", &(temp->sal));
printf("Enter Phone No : ");
scanf("%s", temp->phno);
temp->llink = NULL;
temp->rlink = NULL;
count++;

return temp;
}

void disp_deleted(NODE temp)
{
printf("The following employee detail is deleted:\n");
printf("SSN | Name | Dept | Designation | Salary | Ph. No \n");
printf("-----------------------------------------------------------\n");
printf("%d | %s | %s | %s | %.2f | %s \n",temp->ssn,temp->name,temp->dept,temp->desg,temp->sal,temp->phno);
count--;
}

void insert_front()
{
NODE temp;
temp = create_node();
if(first == NULL)
{
first = temp;
}
else
{
temp->rlink = first;
first->llink = temp;
first = temp;
}
}

void delete_front()
{
NODE temp;
if(first == NULL)
{
printf("List is Empty\n");
}
else if(first->rlink == NULL)
{
disp_deleted(first);
free(first);
first = NULL;
}
else
{
temp = first;

disp_deleted(temp);
first = first->rlink;
first->llink = NULL;
temp->rlink = NULL;
free(temp);
temp = NULL;
}
}

void insert_rear()
{
NODE temp,cur;
temp = create_node();
if(first == NULL)
{
first = temp;
}
else
{
cur = first;
while(cur->rlink !=NULL)
{
cur = cur->rlink;
}
cur->rlink = temp;
temp->llink = cur;
}
}

void delete_rear()
{
NODE cur;
if(first == NULL)
{
printf("List is empty\n");
}
else if(first->rlink == NULL)
{
disp_deleted(first);
free(first);
first = NULL;
}
else
{
cur = first;
while(cur->rlink != NULL)

{
cur = cur->rlink;
}
disp_deleted(cur);
cur->llink->rlink = NULL;
cur->llink = NULL;
free(cur);
cur = NULL;
}
}

void display()
{
NODE cur;
if(first == NULL)
{
printf("List is empty\n");
}
else
{
cur = first;
printf("The employee details in doubly Linked list from beginning : \n");
printf("SSN | Name | Dept | Designation | Salary | Ph. No \n");
printf("-----------------------------------------------------------\n");
while(cur != NULL)
{
printf("%d | %s | %s | %s | %.2f | %s \n",cur->ssn,cur->name,cur->dept,cur->desg,cur->sal,cur->phno);
cur = cur->rlink;
}
printf("-----------------------------------------------------------\n");
printf("Number of Nodes = %d\n",count);
}
}

void main()
{
int choice,i,n;
while(1)
{
choice=0;
printf("-----------------MENU--------------------------------------\n");
printf("1. Create a DLL of N Employees by using End Insertion\n");
printf("2. Display Status and Count of nodes\n");
printf("3. Insertion at rear\n");
printf("4. Deletion at rear\n");

printf("5. Insertion at front\n");
printf("6. Delete at front\n");
printf("7. Exit\n");
printf("-----------------------------------------------------------\n");
printf("Enter choice : ");
scanf("%d", &choice);
switch (choice)
{
case 1: printf("Enter number of employees:");
scanf("%d",&n);
for(i=0;i<n;i++)
insert_rear();
break;
case 2: display();
break;
case 3: insert_rear();
break;
case 4: delete_rear();
break;
case 5: insert_front();
break;
case 6: delete_front();
break;
case 7: return;
default:printf("Invalid choice\n");
return;
}
}
}