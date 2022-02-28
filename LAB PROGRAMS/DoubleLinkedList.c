#include<stdio.h>
#include<stdlib.h>

struct node
{
    int item;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
NODE first=NULL;

NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    return x;
}

NODE create_new()
{
    NODE temp;
    temp=getnode();
    printf("\n\tEnter ITEM :: ");
    scanf("%d",&(temp->item));
    temp->llink=NULL;
    temp->rlink=NULL;
    return temp;
}

void insert_front()
{
    NODE temp;
    temp = create_new();
    if(first == NULL)
        first = temp;
    else
    {
    temp->rlink = first;
    first->llink = temp;
    first = temp;
    }
}

void insert_end()
{
    NODE temp,cur;
    temp = create_new();
    if(first == NULL)
        first = temp;
    else
    {
    cur = first;
    while(cur->rlink !=NULL)
      {  cur = cur->rlink;}
         cur->rlink = temp;
         temp->llink = cur;
      }
}

void delete_front()
{
  NODE temp=first;
  if(first==NULL)
    printf("\n\tEMPTY");
  else if(first->rlink==NULL)
  {   
      printf("Element deleted is %d\n",first->item);
      free(temp);
      first = NULL;
  }  
  else
  {
     printf("Element deleted is %d\n",first->item);
     first=temp->rlink;
     first->llink=NULL;
     free(temp);
  }
}

void delete_end()
{
  NODE cur;
  if(first==NULL)
    printf("\n\tEMPTY");
  else if(first->rlink==NULL)
  {   
      printf("Element deleted is %d\n",first->item);
      free(first);
      first = NULL;
  }  
  else
  {
     cur=first;
     while(cur->rlink!=NULL)
     {
         cur=cur->rlink;
     }
      printf("Element deleted is %d",cur->item);
      cur->llink->rlink=NULL;
      free(cur);
      cur=NULL;
  }
}

void display()
{
    if(first==NULL)
        printf("\n\tLINKED LIST EMPTY\n");
    else if(first->rlink==NULL)
        printf("\nDoubly Linked List is :: %d",first->item);   
    else
    {
        NODE cur = first;
        printf("\nDoubly Linked List is :: ");
        while(cur->rlink!=NULL)
        {
        printf(" %d ",cur->item);
        cur=cur->rlink;        
        }
         printf(" %d ",cur->item);
    }
}

void main()
{int option;
while(1)
{ option=0;
    printf("\nDouble Linked List\n---------------------");
    printf("\n1. Insert at front");
    printf("\n2. Insert at end");
    printf("\n3. Delete at front");
    printf("\n4. Delete at end");
    printf("\n5. Display list");
    printf("\n6. Exit");
    printf("\nEnter Choice :: ");
    scanf("%d",&option);
    switch(option)
    {
    case 1 : insert_front();break;
    case 2 : insert_end();break;
    case 3 : delete_front();break;
    case 4 : delete_end();break;
    case 5 : display();break;
    case 6 : exit(0);
    default: printf("Invalid Choice");
    }
 }
}
