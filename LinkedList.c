#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
} *head = NULL;

void insert_at_begin(struct node**,int);//function prototype
void display(struct node*);
void insert_at_end(struct node**,int);
void delete_begin(struct node** head_ref);
void insert_at_specific(struct node** head_ref,int new_data,int position);
void delete_at_specific(struct node**head_ref , int position);

int main(){
	int ch ,val , pos;
	while(1){
		printf(" 1. INSERT AT THE BEGINING \n 2.DISPLAY \n 3. EXIT \n 4. INSERT AT THE END \n 5.DELETE AT THE BEGINING\n 6.INSERT AT THE SPECIFIC\n 7.Delete at specific location\n ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter the data:\n");
			        scanf("%d",&val);
			        insert_at_begin(&head,val);
			        break;
			case 2: display(head);
			        break;
		    case 3: exit(1);
		    case 4:  printf("Enter the data:\n");
			        scanf("%d",&val);
			        insert_at_end(&head,val);
			        break;
			case 5: delete_begin(head);
			        break;
			case 6: 
			        printf("Enter the data:\n");
			        scanf("%d",&val);
			        printf("Enter the position:\n");
			        scanf("%d",&pos);
			        insert_at_specific(&head,val,pos);
			        break;
			case 7: printf("Enter the position:\n");
			        scanf("%d",&pos);
			       delete_at_specific(&head , pos);
			       break;
		    default: printf("Wrong choice");
		}
	}
	
}
//function definition
void insert_at_begin(struct node**head_ref,int new_data){
struct node* new_node=(struct node*)malloc(sizeof(struct node));
new_node->data = new_data;
new_node->next = *head_ref;
*head_ref = new_node;	
}
void insert_at_end(struct node**head_ref,int new_data){
struct node* new_node=(struct node*)malloc(sizeof(struct node));
new_node->data = new_data;
new_node->next = NULL;
if(*head_ref==NULL){
	*head_ref = new_node;
	return;
}
struct node* temp = *head_ref;
while(temp->next!=NULL)	{
	temp = temp->next;
	temp->next=new_node;
}

}
void delete_begin(struct node** head_ref){
	if(*head_ref== NULL) return;
	struct node* temp = *head_ref;
	*head_ref = (*head_ref)->next;
	printf("\n deleted item is %d\n", temp->data);
	free(temp);
}
void delet_last(struct node** head_ref){
	if((*head_ref)->next==NULL){
		printf("\nDeleted item is %d\n",(*head_ref)->data);
		free(*head_ref);
		*head_ref=NULL;
		return;
	}
	struct node* temp = *head_ref;
	while(temp->next->next!=NULL){temp = temp->next;}
	temp->next=NULL;
	}

void display(struct node*r){
	
	while(r!=NULL){
		printf("%d\n",r->data);
		r = r->next;
		
	}
	printf("NULL\n");
	
}

void insert_at_specific(struct node** head_ref,int new_data,int position){
	
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = NULL;
	
	if(position<0){
		new_node->next=*head_ref;
		*head_ref = new_node;
		return;
	}
	struct node* current = *head_ref;
	int i;
	for(i =0; i<position-1 && current!=NULL;i++){
		current = current->next;
	}
	if(current==NULL){
		printf("Invalid position.Insert at the end\n");
		current =*head_ref;
		while(current->next!=NULL){
			current = current->next;
			current->next=new_node;
		}
	}
	else{
		new_node->next=current->next;
		current->next = new_node;
	}
	
}


void delete_at_specific(struct node**head_ref , int position){
	if(*head_ref==NULL){
		printf("\nLinked List is empty");
		return;
	}
	if(position<=1){
		struct node* temp =*head_ref;
		*head_ref =(*head_ref)->next;
		printf("\nDeleted item is %d\n",temp->data);
		free(temp);
	}
	int i;
	struct node* current = *head_ref;
	for( i =0;i<position-1&&current !=NULL;i++){
		current =current->next;
	}
	if(current==NULL){printf("\nInvalid position.Delete at the end\n");
	if((*head_ref)->next==NULL){
		printf("\n Deleted item is %d\n",(*head_ref)->data);
		free(*head_ref);
		*head_ref=NULL;
		return;
	}
	struct node* temp = *head_ref;
	while(temp->next->next!=NULL){
		temp= temp->next;
	}
	printf("DELETED item is %d\n",(temp->next)->data);
	free(temp->next);
	temp->next=NULL;
	
	}
   else{
   	struct node*temp;
   	temp=current->next;
   	current->next=temp->next;
   	temp->next = NULL;
   	printf("\nDeleted element is %d",temp->data);
   	free(temp);
   }
}
