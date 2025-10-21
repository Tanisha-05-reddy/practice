#include<stdio.h>
#include<stdlib.h>
struct qll{
    int data;
    struct qll *next;
};

typedef struct qll node;
node *head=NULL;
node*rear=NULL;
node*front=NULL;

node* getnode(){
    node *newnode=(node*)malloc(sizeof(node));
    return newnode;
}

void enqueue(int n){
    node *newnode=getnode();
    newnode->data=n;
    newnode->next=NULL;
    if(rear==NULL){
        front=rear=newnode; //empty queue
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

void dequeue(){
    node *temp=front;
    if(front==NULL){
        printf("empty queue");
        return;
    }
    front=front->next;
    if(front==NULL){
        rear=NULL;
    }
    printf("\ndequeued element is %d",temp->data);
    free(temp);
}

void display(){
    node *temp=front;
    printf("\nelements of the queue are : ");
    while(temp!=NULL){
        printf("%5d",temp->data);
        temp=temp->next;
    }
}

int main(){
    int choice;
    int n;
    while(1){
        printf("select operation :\n1.enqueue\n2.dequeue\n3.display\n4.exit");
        scanf("%d",&choice);
        switch(choice){
            case 1 :
                printf("enter element to insert : ");
                scanf("%d",&n);
                enqueue(n);break;
            case 2: dequeue();break;
            case 3: display();break;
            case 4: printf("exiting...");break;
            default:printf("invalid choice");
        }
    }
    return 0;
}
