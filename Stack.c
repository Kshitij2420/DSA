#include <stdio.h>
#include<stdlib.h>
int stack[5];
int size = 5;
int top= -1;
void push(int );
void pop();
void display();
int main(){
	int ch ,val ;
	while(1){
		printf(" 1. Push \n 2.POP \n 3. EXIT \n 4. DISPLAY \n  ");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter the data:\n");
			        scanf("%d",&val);
			        push(val);
			        break;
			case 2: pop();
			        break;
		    case 3: exit(1);
		    case 4:  display();
			        break;

		    default: printf("Wrong choice");
		}
	}
	
}
void push(int x){
	if(top == size-1){
		printf("STACK OVERFLOW\n");
	}
	else{
		top++;
		stack[top]=x;
	}
}

void pop(){
	if(top == -1){
		printf("STACK UNDERFLOW\n");
	}
	else{
		printf("POPPED ELEMENT IS %d\n",stack[top]);
		top--;
	}
}

void display(){
	int i ;
	i=top;
	if(i == -1){
		printf("Empty\n");
	}
	else{
		while(i>=0){
			printf("%d\n", stack[i]);
			i--;
		}
	}
}
 
