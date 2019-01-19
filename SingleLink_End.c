#include<stdio.h>
#include<stdlib.h>
#define d NULL
#define s struct SingleLink
s
{
	int ele;
	s * next;
}*root;
s * Insert_End(s *);
s * Deletion_End(s *);
void Display(s *);
int main(void)
{
	int ch;
	root=d;
	do
	{
		inv:printf("\n1.)Insert Element at End\n2.)Delete Element at End \n3.)Display the element\n0.EXIT\nEnter your choice:-");
		scanf("%1d",&ch);
		switch(ch)
		{
			case 1:root=Insert_End(root);break;
			case 3:Display(root);break;
			case 0:exit(0);break;
			case 2:root=Deletion_End(root);
			       break;
			default:printf("\nKindlly Choose valid option:-");
				goto inv;
		}
	}while(ch!=0);
	return 0;
}
s * Insert_End(s * root)
{
	s * ptr=(s *)calloc(1,sizeof(s));
	if(ptr!=d)
	{
		ptr->next=d;
		printf("\nEnter the Element Value:-");
		scanf("%d",&ptr->ele);
		if(root==d)
			root=ptr;
		else
		{
			s * temp=root;
			while(temp->next!=d)
			{
				temp=temp->next;
			}
			temp->next=ptr;
		}
	}
	else
	{
		printf("Memory Full");
	}
	Display(root);
	return root;
}
void Display(s * root)
{
	if(root==d)
	{
		printf("\nNo Data Found");
	}
	else
	{
		while(root!=d)
		{
			printf("%d\t",root->ele);
			root=root->next;
		}
	}
}
s * Deletion_End(s * root)
{

	if(root==d)
		printf("no Data found");
	else
	{
		s * temp=root;
		if(temp->next==d)
		{	
			root=d;
		}
		else
		{
			s *temp1;
			while(temp->next!=d)
			{
				temp1=temp;
				temp=temp->next;
			}
			temp1->next=d;
		}
		free(temp);
	}
	Display(root);
	return root;
}
