/*******************************************************
 * STACK WORKS ON LAST IN FIRST OUT
 *****************************************************/
#include<stdio.h>
#include<stdlib.h>
#define n NULL
#define S struct Stack
S
{
	int ele;
	S * next;
}*root;


S * push(S *);
S * pop(S *);
void traversal(S *);
int main()
{
	int ch;
	root=n;
	do
	{
	inv:printf("\n1.)Push the Element in the Stack\n2.)Pop the Element in the Stack\n3.)Display the Stack\n0.)Exit\nEnter your choice:-");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:root=push(root);break;
			case 3:traversal(root);break;
			case 2:root=pop(root);break;
			case 0:exit(0);break;
			default:printf("\nINVALID CHOICE");
				goto inv;
		}
	}while(ch!=0);

}
S * push(S * root)
{
	S * ptr=(S *)calloc(1,sizeof(S *));
	if(ptr==n)
	{
		printf("\n Memory Full");
	}
	else
	{
		printf("Enter the Element Value:-");
		scanf("%d",&ptr->ele);
		ptr->next=n;
		if(root==n)
		{
			root=ptr;
		}
		else
		{
			ptr->next=root;
			root=ptr;

		}
	}
	return root;
}
void traversal(S * root)
{
	if(root==n)
	{
		printf("No Data Found!");
	}
	else
	{
		while(root!=n)
		{
			printf("%d\t",root->ele);
			root=root->next;
		}
	}
}

S * pop(S * root)
{
	if(root==n)
	{
		printf("Stack is Empty");
	}
	else
	{
		S * temp=root;
		root=temp->next;
		printf("PROCESSED ELEMENT IS %d",temp->ele);
		free(temp);
	}
	return root;
}

