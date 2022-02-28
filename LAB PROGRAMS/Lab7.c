/*Design, Develop and Implement a menu driven Program in C for the following
operations on
Singly Linked List (SLL) of Student Data with the fields: USN, Name, Branch,
Sem, PhNo.
a. Create a SLL of N Students Data by using front insertion.
b. Display the status of SLL and count the number of nodes in it
c. Perform Insertion / Deletion at End of SLL
d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack)
e. Exit

*/
#include<stdio.h>
#include<stdlib.h>

//creation of structure for node
struct node
{
char usn[10],name[10],branch[10],phno[10];
int sem;
struct node *link;
};
typedef struct node *NODE;
NODE temp, FIRST=NULL;

//Function to create a NODE
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
x->link=NULL;
return x;
}

//Function to read the information which has to be stored in data field of a node
void read()
{
temp=getnode();
printf("Enter USN:");
scanf("%s",temp->usn);
printf("Enter Name:");
scanf("%s",temp->name);
printf("Enter Branch:");
scanf("%s",temp->branch);
printf("Enter Phone Number:");

scanf("%s",temp->phno);
printf("Enter Semester:");
scanf("%d",& temp->sem);
}

//a)Create a SLL of N Students Data by using front insertion.
void create_sll()
{
int i,n;
printf("Enter the number of students:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("\n Enter the details of student %d\n",i);
read();
if(FIRST==NULL)
{
FIRST=temp;
}
else
{
temp->link=FIRST;
FIRST=temp;
}
}
}

//b)Display the status of SLL and count the number of nodes in it
void display_count()
{
int count=0;
temp=FIRST;
printf("Student details:\n");
if(FIRST==NULL)
{
printf("Student detail is NULL. Count is Zero\n");
}
else
{
printf("\nUSN\tNAME\tBRANCH\tPH NO\tSEM\n");
while(temp->link!=NULL)
{
count++;
printf("%s\t%s\t%s\t%s\t%d\n",temp->usn,temp->name,temp->branch,temp->phno,temp->sem);
temp=temp->link;
}
count++;
printf("%s\t%s\t%s\t%s\t%d\n",temp->usn,temp->name,temp->branch,temp->phno,temp->sem);
printf("\n Student count:%d\n",count);
}
return;
}

//d)Insertion at front of SLL
void insert_front()
{
printf("Enter the details of students\n");
read();
if(FIRST==NULL)
{
FIRST=temp;
}
else
{
temp->link=FIRST;
FIRST=temp;
}
}

//c)Insertion at end of SSL
NODE insert_end()
{
NODE last=FIRST;
printf("Enter the details of student\n");
read();
if(FIRST==NULL)
{
FIRST=temp;
}
else
{
while(last->link!=NULL)
{
last=last->link;
}
last->link=temp;
}
return FIRST;
}

//d) deletion at front of SSL
void delete_front()
{
temp=FIRST;
if(FIRST==NULL)
{
printf("List is empty");

}
else
{
printf("Deleted elements is %s\n",temp->usn);
FIRST=FIRST->link;
free(temp);
}
return;
}
//c) deletion at end of SSL
void delete_end()
{
NODE last=NULL;
temp=FIRST;
if(FIRST==NULL)
{
printf("List is empty\n");
}
else if(FIRST->link==NULL)
{
printf("Deleted elemt is %s\n",temp->usn);
free(FIRST);
FIRST=NULL;
}
else
{
while(temp->link!=NULL)
{
last=temp;
temp=temp->link;
}
last->link=NULL;
printf("Deleted elemt is %s\n",temp->usn);
free(temp);
}
return;
}

//main Function
void main()
{
int choice;
while(1)
{
printf("-----------------MENU--------------------------------------\n");
printf("1. Create a SLL of N Students using front insertion\n");
printf("2. Display from Beginning\n");
printf("3. Insert at front\n");
printf("4. Insert at end\n");
printf("5. Delete at front\n");
printf("6. Delete at end\n");
printf("7. Exit\n");

printf("-----------------------------------------------------------\n");
printf("Enter choice : ");
scanf("%d", &choice);
switch (choice)
{
case 1: create_sll();
break;
case 2: display_count();
break;
case 3: insert_front();
break;
case 4: insert_end();
break;
case 5: delete_front();
break;
case 6: delete_end();
break;
case 7: return;
default:printf("Invalid choice\n");
}
}
}