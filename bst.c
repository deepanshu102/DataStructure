#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct bst
{
	struct bst *rf,*lf;
 	int el;
}bst;
typedef struct head
{
  bst *ele;
  int no_no,pos;
//  int lev,deg;
  struct head *next;
}head;
#define N NULL;
static int pos=0;
/*************************************************
 *
 * 		FUNCTION PROTOTYPES
 ************************************************/
head* create_tree(head *,int);
void display_n_tree(head *);
bst* search(head *,int);
void insert(bst *,int);
void display_inorder(bst *);
bst * create_bst_node(int );
void display_preorder(bst *);
void display_postorder(bst *);
bst * deletion_bst(bst *,int);
bst * find_MAX(bst *);
bst * find_MIN(bst *);
bst * search_element(bst *,int data);
/*************************************************************
 *
 * 			FUNCTION DECLARATION
 *********************************************************/


head* create_tree(head *hd,int ele)
{
	head *ptr=(head *)malloc(sizeof(head));
	ptr->ele=(bst *)malloc(sizeof(bst));
	if(ptr && ptr->ele)
	{
		(ptr->ele)->el=ele;
		(ptr->ele)->rf=(ptr->ele)->lf=N;
		ptr->no_no=1;
	//	ptr->lev=0;
	//	ptr->deg=0;
		ptr->pos=pos++;
		ptr->next=N;
		ptr->next=hd;
		hd=ptr;
		printf("Unique Identification Number of the tree is :- %d",ptr->pos);
		return hd;
	}	
	else
		printf("OVERFLOW");
}

void display_n_tree(head *hd)
{
	if(hd)
	{
		head *temp=hd;
		while(temp)
		{
			printf("\a Root Element is %d\t Unique Identification Number:-%d\t Number of Nodes:-%d\n",(temp->ele)->el,temp->pos,temp->no_no);
			temp=temp->next;
		}
	}
	else
	{	
		printf("Underflow");
	}
}


bst*  search(head *hd,int pos)
{
	if(hd)
	{
		head *temp=hd;
		while(temp->pos!=pos)
		{
			temp=temp->next;
		}	
		return temp->ele;
	}
	else
		return N;
	
}


bst * create_bst_node(int ele)
{
	bst *ptr=(bst *)malloc(sizeof(bst));
	ptr->el=ele;
	ptr->rf=ptr->lf=N;
	return ptr;

}

void insert(bst * tree,int ele)
{

	if(tree)
	{
		bst *temp=tree,*prv=tree;
		while(temp)
		{
			prv=temp;
			if(temp->el>ele)
			temp=temp->lf;
			else
			  temp=temp->rf;
		}
		if(prv->el>ele)
		 prv->lf=create_bst_node(ele);
		else
			prv->rf=create_bst_node(ele);
	}
	else
		return;
}

void display_inorder(bst *tree)
{
	if(tree)
	{
		display_inorder(tree->lf);
		printf("%d\t",tree->el);
		display_inorder(tree->rf);
	}
	else
		return;
}

void display_preorder(bst *tree)
{
	if(tree)
	{
		printf("%d\t",tree->el);
		display_preorder(tree->lf);
		display_preorder(tree->rf);
	}
	else
		return;
}


void display_postorder(bst *tree)
{
	if(tree)
	{
		display_postorder(tree->lf);
		display_postorder(tree->rf);
		printf("%d\t",tree->el);
	}
	else
		return;

}

bst * find_MAX(bst *tree)
{
	if(tree->rf)
	{
		   find_MAX(tree->rf);		
	}
	else
		return tree;
	
}

bst * find_MIN(bst * tree)
{
	if(tree->lf)
	{
		 find_MIN(tree->lf);
	}
	else
		return tree;
}

bst * deletion_bst(bst * tree,int data)
{
		if(tree->el>data)
		{
			tree->lf=deletion_bst(tree->lf,data);
		}
		else if(tree->el<data)
		{	tree->rf=deletion_bst(tree->rf,data);
		}
		else
		{
			//ELEMENT FOUND
			bst * temp;
			if(tree->lf && tree->rf)
			{
				temp=find_MAX(tree->lf);
				tree->el=temp->el;
				tree->lf=deletion_bst(tree->lf,tree->el);
			}
			else 
			{
				temp=tree;
				if(tree->lf==NULL)
				tree=tree->rf;
				else if(tree->rf==NULL)
					tree=tree->lf;
				free(temp);		
			}
		}
		return tree;
}
bst * search_element(bst * tree,int data)
{
	if(tree->el>data)
		return tree->lf=search_element(tree->lf,data);
	else if(tree->el<data)
		return tree->rf=search_element(tree->rf,data);
	else if(tree->el==data || tree!=NULL)
		return tree;
}
int main()
{
	int i,ele,pos;
	char ch;
	bst * temp_bst;

	head *temp,*hd=NULL;
	do{
	printf("\n1.)Creation of Tree");
	printf("\n2.)Insertion of the element in the tree\n3.)Deletion of the Tree\n4.)Display the Element in Inoder\n5.)Display Element in Pre-order\n6.)Display Element in Post-order\n7.)Search the element in the bst Tree \n8.) Find Maximum element in the bst Tree\n 9.)Find Minimum element in the bst \n10.)Display  number of tree\t press 0 for Exit\nEnter your choice:- ");
	 scanf("%d",&i);
	 switch(i)
	 {
		 case 1:printf("Enter the Element");
			scanf("%d",&ele);
			hd=create_tree(hd,ele);break;
		 case 2:printf("\nEnter Unique Identity of the Tree:-");
			scanf("%d",&pos);
			printf("\nEnter the Element:- ");
			scanf("%d",&ele);
			temp_bst=search(hd,pos);
			if(temp_bst)
			{
			 insert(temp_bst,ele);
				temp=hd;
			 while(temp->pos!=pos)
				 temp=temp->next;
			 temp->no_no++;
			}
			else
				printf("\nNo Tree Found\n");
			break;
		 case 3:printf("\nEnter the Unique Identification Number of the Tree:- ");
			scanf("%d",&pos);
			printf("\n Enter which element you want to delete:- ");
			scanf("%d",&ele);
			temp_bst=search(hd,pos);
			if(temp_bst==NULL)				
			{
			       	printf("\nNo Tree Found");
			}
			else
			{
		       		temp_bst=deletion_bst(temp_bst,ele);
				temp=hd;
				while(temp->pos!=pos)
				  temp=temp->next;
				temp->no_no-=1;
				temp->ele=temp_bst;
			}
			break;
		 case 4:printf("\nEnter the Unique Identification Number of the Tree:- ");
			scanf("%d",&pos);
			(search(hd,pos)==NULL)?printf("\n No Tree Found"):display_inorder(search(hd,pos));break;	
		 case 5:printf("\nEnter the Unique Identification Number of the Tree:- ");
			scanf("%d",&pos);
			(search(hd,pos)==NULL)?printf("\n No Tree Found"):display_preorder(search(hd,pos));break;
		case 6:	printf("\nEnter the Unique Identification Number of the Tree:- ");
			scanf("%d",&pos);
			(search(hd,pos)==NULL)?printf("\n No Tree Found"):display_postorder(search(hd,pos));break;
		case 7:printf("\nEnter the Unique Identification Number:- ");
		       scanf("%d",&pos);
		       printf("\nEnter the element you want to found:- ");
		       scanf("%d",&ele);
		       temp_bst=search(hd,pos);
		       if(temp_bst==NULL)
		       {
			       printf("\nNo TREE FOUND");
		       }
		       else
		       {
				temp_bst=search_element(temp_bst,ele);
		   		if(temp_bst==NULL)
				printf("\n %d is not found",ele);
				else
				printf("%d is found ",temp_bst->el);		
		       }
			break;
		case 8:printf("\nEnter the Unique Identification Number:- ");
		       scanf("%d",&pos);
			printf("\n%d is Maximum Element in the Tree",find_MAX(search(hd,pos))->el);break;
		case 9:	printf("\nEnter the Unique Identification Number:-");
			scanf("%d",&pos);
			printf("\n%d is the Minimum elment in the tree ",find_MIN(search(hd,pos))->el);break;
	       	case 10:display_n_tree(hd);break;
		case 0:exit(0);
		default:printf("InValid choice ");
	 }
	printf("\nDo you want to Continue:- Press Y \t otherwise press N");
	scanf("%1s",&ch);

	}while(ch=='Y' || ch=='y');
}


