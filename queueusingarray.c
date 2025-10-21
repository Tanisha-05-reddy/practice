#include<stdio.h>
#define size 5
int queue[size];
int rear=-1;
int front=-1;
void enqueue(int n){
    if (rear==size-1){
        printf("queue overflow");
    }
    else if(rear==-1){
        rear++;
        queue[rear]=n;
        front++;
    }
    else{
        rear++;
        queue[rear]=n;
    }
}

void dequeue(){
    if(front==-1 || front>rear){
        printf("empty queue");
    }
    else{
        front++;
    }
}

void display(){
    for(int i=front;i<=rear;i++){
        printf("%5d", queue[i]);
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
