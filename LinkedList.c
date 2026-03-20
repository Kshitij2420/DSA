#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
} *head = NULL;

void insert_at_begin(struct node**,int);//function prototype
void display(struct node*);

int main(){
	int ch ,val , pos;
	while(1){
		printf(" 1. INSERT AT THE BEGINING \n 2.DISPLAY \n 3. EXIT \n");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter the data:\n");
			        scanf("%d",&val);
			        insert_at_begin(&head,val);
			        break;
			case 2: display(head);
			        break;
		    case 3: exit(1);
		    default: printf("Wrong choice");
		}
	}
	
}

void insert_at_begin(struct node**head_ref,int new_data){
struct node* new_node=(struct node*)malloc(sizeof(struct node));
new_node->data = new_data;
new_node->next = *head_ref;
*head_ref = new_node;	
}

void display(struct node*r){
	while(r!=NULL){
		printf("%d\n",r->data);
		r = r->next;
		
	}
	printf("NULL\n");
	
}
