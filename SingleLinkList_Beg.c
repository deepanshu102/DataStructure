#include<stdlib.h>
#include<stdio.h>
#define N NULL
#define s struct SingleLink
s
{
	int ele;
	s *prv;
}*root;
s * Insertion_Beg(s *);
s * Deletion_Beg(s *);
void Display(s *);
int main(void)
{
	int ch;
	root=N;
	do
	{
ch_op:printf("\n1.Insert the Element\n2.)Deletion the Element\n3.)Display the Element\n0.Exit\nEnter your choice:-");
		scanf("%1d",&ch);
		switch(ch)
		{
			case 1:
			case 2:root=(ch&1)?Insertion_Beg(root):Deletion_Beg(root);
			       break;
			case 3:Display(root);
			       break;
			case 0:exit(0);
			       break;
			default:printf("Invalid Choice:- \n Kindlly Choose correct option");
				goto ch_op;

		}
	}while(ch!=0);
}
s * Insertion_Beg(s * root)
{
	s * ptr=(s *)calloc(1,sizeof(s));
	if(ptr==N)
	{
		printf("Memory Full");
	}
	else
	{
		ptr->prv=N;
		printf("Enter the Element:-");
		scanf("%d",&ptr->ele);
		if(root!=N)
			ptr->prv=root;
		root=ptr;
	}
	Display(root);
	return root;
}
void Display(s * root)
{
	if(root==N)
	{
		printf("No Element Found");
	}
	else
	{
		while(root!=N)
		{
			printf("%d\t",root->ele);
			root=root->prv;
		}
	}
}
s * Deletion_Beg(s * root)
{
	if(root==N)
	{
		printf("No Data Found");
	}
	else
	{
		s *ptr=root;
		root=ptr->prv;
		free(ptr);
	}
	Display(root);
	return root;
}
