#include<stdio.h>
#include<stdlib.h>
#define N NULL
#define S struct QUEUE
S
{
	int ele;
	S * next;
}*root;
S * Enqueue(S *);
S * Dequeue(S *);
void traversal(S *);
int main()
{
	int ch;
	root=N;
	do{
inv:printf("1.)INSERT THE ELEMENT IN THE QUEUE\n2.)DISPLAY THE ELEMENT OF QUEUE\n3.DELETE THE ELEMENT FROM QUEUE\n0.Exit\nENTER YORU CHOICE");
		scanf("%1d",&ch);
		switch(ch)
		{
			case 1:root=Enqueue(root);
			       traversal(root);
			       break;
			case 2:traversal(root);break;
			case 3:root=Dequeue(root);
			       traversal(root);break;
			case 0:exit(0);
			       break;
			default:printf("kindlly choose the correct option:-");
				goto inv;
		}
	}while(ch!=0);
}

S * Enqueue(S * root)
{
	S * ptr=(S *)calloc(1,sizeof(S));
	if(ptr==N)
	{
		printf("Memory full");
	}
	else
	{
		ptr->next=N;
		printf("Enter the Element:-");
		scanf("%d",&ptr->ele);
		if(root==N)
			root=ptr;
		else
		{
			S * temp=root;
			while(temp->next!=N)
			 	temp=temp->next;
			temp->next=ptr;
		}
	}
	return root;
}
void traversal(S * root)
{
	if(root==N)
	{
		printf("No Data Found");
	}
	else
	{
		while(root!=N)
		{
			printf("%d\t",root->ele);
			root=root->next;
		}
	}
}
S * Dequeue(S * root)
{
	if(root==N)
	{
		printf("No element in the Queue");
	}
	else
	{
		S * temp=root;
		root=temp->next;
		free(temp);
	}
	return root;
}
