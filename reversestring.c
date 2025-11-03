#include<stdio.h>
#include<string.h>
#define size 100
char stack[size];
int top=-1;

void push(char ele){
	if(top==size-1){
		printf("Stack overflow");
		return;
	}
	else{
		top++;
		stack[top]=ele;
	}
}

void pop(){
	if(top==-1){
		printf("Stack underflow (or) Stack is empty");
	}
	else{
		top--;
	}
}

void display(){
	int i;
	if(top==-1){
		printf("Stack underflow (or) Stack is empty");
		return;
	}
	else{
		for(i=top;i>=0;i--){
			printf("%c",stack[i]);
			printf("\n");
		}
	}
}
int peek(){
	if(top==-1){
		return -1;
	}
	else{
		return stack[top];
	
	}
}

int main(){
	int i;
	char ch[size];
	printf("Enter a string: ");
	scanf("%s",ch);
	for(i=0;i<strlen(ch);i++){
		push(ch[i]);
	}
	display();
	return 0;
}