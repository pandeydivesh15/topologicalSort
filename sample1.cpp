#include<iostream>
#include<stdlib.h>
using namespace std;
struct adjLinkedList
{
	int data;
	adjLinkedList *next;
}*ptr=NULL,*temp=NULL;

class Graph
{
	private:
		
	public:
		int vertex[100];
		adjLinkedList * adjList[100];
		Graph()
		{
			for (int i=0;i<100;++i)
			{
				vertex[i]=0;
				adjList[i]=NULL;
			}
		}
		void insertVertex(int v)
		{
			vertex[v-1]=1;
		}
		void insertEdge(int v, int u)
		{
			//listinsert(u-1,adjList[v-1]);
			int adjVertex=u-1;
			int flag=0,i=1;
			if(adjList[v-1]==NULL)
			{
				adjList[v-1]=(adjLinkedList*)malloc(sizeof(adjLinkedList));
				adjList[v-1]->data= adjVertex;
				adjList[v-1]->next=NULL;
				flag=1;
				return;
			}
			temp = (adjLinkedList*)malloc(sizeof(adjLinkedList));
			temp->data=adjVertex;
			temp->next=NULL;
			
			ptr =adjList[v-1];
			while(ptr!= NULL)
			{
			
				if(ptr->next==NULL)
				{
					ptr->next=temp;
					return; 
				}		
				ptr=ptr->next;
			}
			
			return;
		
		}
		
}x;
int visited[100],stack[100];

int count=0;	
void DFS_topologicalSort(int temp)
{
	visited[temp]=1;
	adjLinkedList *point=NULL;
	int flag=0;
	point=x.adjList[temp];
	if(point==NULL)
	{
		
		stack[count]=temp+1;
		count++;
		return;
	}
	while(point!=NULL)
	{
		if(visited[point->data]==0)
			DFS_topologicalSort(point->data);
		point=point->next;
	}
	stack[count]=temp+1;
	count++;
	return;
}
int main()
{
	int n,m,temp;
	for(int h=0;h<100;h++)
	{
	visited[h]=0;
	stack[h]=-1;
	}
	char c;
	int choice;
	cout<<"****This Program is an implementation of Topological Sort using DFS****\n";
	do
	{	
		
		cout<<"Enter your choice\n";
		cout<<"1.Insert a vertex into graph\n2.Insert an edge into graph\n3.Exit\n\n";
		cin>>choice;
		if(choice==3)
			break;
		if(!cin||choice>3||choice<1)
			{
				cout<<"Wrong Input...Try again\n";
				continue;
			}
		switch(choice)
		{
			case 1:
					cout<<"Enter vertex to be inserted ";
					
					cin>>n;
					temp=n;
					x.insertVertex(n);
					break;					
			case 2: 
				
					cout<<"Enter the two elements of the edge such that first element ---->----second element\n";
					cin>>n>>m;
					x.insertEdge(n,m);
					break;
			case 3:
					cout<<"The Program will exit...\n";
					break;
			default:
					cout<<"Wrong Input...Try again\n";
				
					
		}
		
	
		
	}while(1);
	
	for(int k=0;k<100;k++)
	{
		if(x.vertex[k]==1){
		
			if(visited[k]==0)
			{
				
				DFS_topologicalSort(k);
			}
		}
	}
	
	for(int g=99;g>-1;g--)
	{
		if(stack[g]==-1)
		{
			continue;
		}
		cout<<'\t'<<stack[g]<<" -->-- ";
	}
}


