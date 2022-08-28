#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

    struct node *head,*tail,*temp;
int lenght(void);
void insert();
void insert_beg();
void insert_end();
int insert_pos();
void delete_beg();
void delete_end();
void delete_pos();
void display();
void reverse();

int main()
{
	int ch,flag=1;
	
	while(flag=1)
	{
	  	printf("\n LINKED LIST MENU:");
	 	printf("\n PRESS 1 FOR INSERT:");
	 	printf("\n PRESS 2 FOR INSERT AT BEGINNING:");
	 	printf("\n PRESS 3 FOR INSERT AT END:");
	 	printf("\n PRESS 4 FOR INSERT AT POSITION:");
	       printf("\n PRESS 5 FOR DISPLAY:");
	       printf("\n PRESS 6 FOR DELETE FROM BEGINNING:");
	       printf("\n PRESS 7 FOR DELETE FROM END:");
	       printf("\n PRESS 8 FOR DELETE FROM POSITION:");
	       printf("\n PRESS 9 FOR REVERSE THE ELEMENT:");
	 
		
		printf("\n ENTER THE YOUR OPTION:");
		scanf("%d",&ch);
		
		switch(ch)
		{
		 case 1:insert();
			 break;
		 case 2:insert_beg();
		        break;
	        case 3:insert_end();
	               break;
	        case 4:insert_pos();
	               break;
	        case 5:display();
	               break;
	        case 6:delete_beg();
	               break;
	        case 7:delete_end();
	               break;
	        case 8:delete_pos();
	               break;
	        case 9:reverse();
	               break;
	        
			     
               default:printf("\n ENTER THE CORRECT OPITION");
                      break;
                      
		}
		printf("\n PRESS 1 FOR LINKED LIST MENU:");
		scanf("%d",&flag);
	}
	return 0;
}

void insert() 
{
	struct node *newnode;
	head=NULL;
	int ch=1;
	
	while(ch)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\n ENTER THE DATA:");
		scanf("%d",&newnode->data);
		
		if(head==NULL)
		{
			head=tail=newnode;
			head->next=head;
			head->prev=head;
		}
		else
		{
			tail->next=newnode;
			newnode->prev=tail;
			newnode->next=head;
			head->prev=newnode;
			tail=newnode;
		}
		printf("TAIL NEXT DATA(HEAD DATA):%d",tail->next->data);
		printf("\nHEAD PREVIOUS DATA(TAIL DATA):%d",head->prev->data);
			
		printf("\n DO YOU WANT TO CONTINUE(PRESS 1):");
		scanf("%d",&ch);
	}

}

void insert_beg()
{
	struct node *newnode;
	
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\n ENTER THE DATA:");
	scanf("%d",&newnode->data);
	
	if(head==NULL)
	{
		head=tail=newnode;
		newnode->prev=tail;
		newnode->next=head;
	}
	else
	{
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
		head->prev=tail;
		tail->next=head;
	}
		printf("TAIL NEXT DATA(HEAD DATA):%d",tail->next->data); 
		printf("\nHEAD PREVIOUS DATA(TAIL DATA):%d",head->prev->data);
}

void insert_end()
{
	struct node *newnode;
	
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\n ENTER THE DATA:");
	scanf("%d",&newnode->data);
	
	if(head==NULL)
	{
		head=tail=newnode;
		newnode->prev=tail;
		newnode->next=head;
	}
	else
	{
		newnode->prev=tail;
		tail->next=newnode;
		newnode->next=head;
		head->prev=newnode;
		tail=newnode;
		
	}
		printf("TAIL NEXT DATA(HEAD DATA):%d",tail->next->data); 
		printf("\nHEAD PREVIOUS DATA(TAIL DATA):%d",head->prev->data);
	
}

int insert_pos()
{
	struct node *newnode,*temp;
	int pos,i=1,l;
	temp=head;
	
	printf("\n ENTER THE POSITION:");
	scanf("%d",&pos);
	l=lenght();
	printf("\nlenght of list:%d",l);
	
	if(pos>l || pos<0)
	{
		printf("\n INVALID POSITION !");
	}
       else if(pos==1)
	{
	  insert_beg();
	}
	else 
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("\n ENTER THE DATA:");
		scanf("%d",&newnode->data);
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		}
		newnode->prev=temp;
		newnode->next=temp->next;
		temp->next->prev=newnode;
		temp->next=newnode;
       }
	return 0;
}
int lenght()    
{
 	int cout;
 	temp=head;
        while(temp->next!=head)
 	{
 	       cout++;
 		temp=temp->next;
 		if(temp->next==tail->next)
 		{
 			cout++;
		 }
	}
       
        

	return(cout);
 }
 
void delete_beg()
{
	 struct node *temp;
	 temp=head;
	 
	 if(head==NULL)
	 {
	 	printf("\n LIST IS EMPTY");
	 }
	 else if(head->next==head)
	 {
	 	head=tail=NULL;
	 	free(temp);
	 }
	 else
	 {
	 	head=head->next;
	 	head->prev=tail;
	 	tail->next=head;
	 	printf("\n DELETE ELEMENT:%d",temp->data);
	 	free(temp);
	 }
}

void delete_end()
{
	struct node *temp;
	temp=tail;
	
	if(head==NULL)
	{
		printf("\n LIST IS EMPTY");
	}
	else if(tail->next==tail)
	{
		head=tail=NULL;
		free(temp);
	}
	else
	{
		tail=tail->prev;
		tail->next=head;
		head->prev=tail;
		printf("\n DELETE ELEMENT:%d",temp->data);
		free(temp);
	}
}

void delete_pos()
{
	struct node *temp;
	 int pos,i=1,l;
	temp=head;
	
	printf("\n ENTER THE POSITION:");
	scanf("%d",&pos);
	l=lenght();
        printf("\n lenght of list:%d",l);
      
      	if(pos>l || pos<0)
	{
		printf("\n INVALID POSITION !");
	}
       else if(pos==1)
	{
		delete_beg();
	}
	else 
	{
		while(i<pos)
	{
		temp=temp->next;
		i++;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	if(temp->next==head)
	{
	   tail=temp->prev;
	   printf("\n DELETE ELEMENT:%d",temp->data);
	   free(temp);	
	}
	else
	{
		printf("\n DELETE ELEMENT:%d",temp->data);
		free(temp);
	}
       }  
}

void reverse()
{     
       int cout; 
	 temp=tail;
       while(temp!=head)
   {
   	printf("\n%d",temp->data);
   	temp=temp->prev;
   	cout++;
   }
   printf("\n%d",temp->data);
}
void display()
{

	struct node *temp;
	temp=head;
	
	if(head==NULL)
	{
		printf("\n LIST IS EMPTY");
	}
	else
	{
		while(temp!=tail)
		{  
			printf("\n%d",temp->data);
			temp=temp->next;
		}
		printf("\n%d",temp->data);
	}
}
