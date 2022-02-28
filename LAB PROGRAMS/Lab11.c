/*Design, Develop and Implement a Program in C for the following operations on
Graph(G) of
Cities
a. Create a Graph of N cities using Adjacency Matrix.
b. Print all the nodes reachable from a given starting node in a digraph using
DFS/BFS method*/
//bfs --> Queue
//Dfs --> Stack
#include<stdio.h>
#include<conio.h>
#define MAX 5 //create a array of size 5*5

void bfs(int adj[][MAX],int visited[],int start) //takes in 3 arguments 1)adjacency matrix 2)visited array 3) start node
{
int queue[MAX]; //we use queue in BFS. So initialize queue to size of MAX
int rear = -1, front =-1; //initializing rear and front to -1, just to make sure that the the queue is empty.
int i,k;
for(k=0;k<MAX;k++) //using a for loop just to make sure that visited array
{
visited[k]=0; //making all elements in visited array as 0.
}
queue[++rear] = start; //pre increment rear & insert "start" node to the queue.
++front; //increment front.
visited[start] =1; //after adding a node to queue, mark it as 1 in visited array.
while(front<=rear) //this while loop ends only when your queue is empty.
{
start = queue[front++]; //pops out one value from queue & stores that in "start"
printf("%d", start); //print that start to the user.
for(i=1;i<=MAX;i++) //adding adjacent/neighbor nodes of the value deleted
{
if(adj[start][i] && visited[i] == 0)
{
queue[++rear] = i; //increment rear and add the nodes at rear end of queue
visited[i] = 1; //make thie visited as 1.
}
}
}
}
void dfs(int adj[][MAX], int visited[], int start)
{
int stack[MAX];

int top=-1;
int i,k;
for(k=0;k<MAX;k++)
{
visited[k]=0;
}
stack[++top] = start;
visited[start] = 1;
while(top!=-1)
{
start = stack[top--];
printf("%d", start);
for(i=1;i<=MAX;i++)
{
if(adj[start][i] && visited[i] ==0)
{
stack[++top] = i;
visited[i] =1;
break;
}
}
}
}

int main()
{
int visited[MAX] ={0}; //create a single dimentional matrix of size MAX
int adj[MAX][MAX],i,j; //adjacency matrix= 2D matrix of 5*5 nodes
int option,size;
do
{
printf("\n *****Main Menu*****");
printf("\n 1. Enter values in graph");
printf("\n 2. BFS Traversal");
printf("\n 3. DFS Traversal");
printf("\n 4. Exit");
printf("\n\n Enter your option:");
scanf("%d", &option);
switch(option)
{
case 1: printf("\n Enter the adjacency matrix:");
for(i=1;i<=MAX;i++) //for rows
for(j=1;j<=MAX;j++) //for columns
scanf("%d", &adj[i][j]); //store the values in adjacency matrix. The graph is stored into the system. Now call either BFS or DFS totraverse.
break;

case 2: printf("BFS Traversal:");
bfs(adj,visited,1); //call bfs function with 3 arguments.1)adjacency matrix 2)visited array 3) start node
break;
case 3: printf("DFS Traversal:"); //call dfs function with 3arguments. 1)adjacency matrix 2)visited array 3) start node
dfs(adj,visited,1);
break;
}
}while(option!=4);
getch();
return 0;
}