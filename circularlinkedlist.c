#include<stdio.h>
#include<stdlib.h>
struct CLL{
int data;
struct CLL *next;
};

typedef struct CLL node;
node *head=NULL;

node *getNode(){
node* newNode=(node*)malloc(sizeof(node));
printf("Enter a number");
scanf("%d",&newNode->data);
newNode->next=NULL;
return newNode;
}

void CreateCircularlist(int n){
node *newNode;
    int i;
    node *temp;
    for(i=1;i<=n;i++){
    newNode=getNode();
    if(head==NULL){
    head=newNode;
    newNode->next=head;
    }
    else{
    temp=head;
    do{
        temp=temp->next;
    }

while(temp->next!=head);
temp->next=newNode;
newNode->next=head;
}
}

}

void display(node *head){
    node *temp=head;
    if(head==NULL)
    printf("no list");
    else{
        do{
            printf("%5d",temp->data);
            temp=temp->next;
        }
        while(temp!=head);
    }

}

int count(node *temp){
int c=0;
do
{
c++;
temp=temp->next;
}
while(temp!=head);
return c;
}

void insert_begin(){
    node *newnode=getNode();
    if(head==NULL){
        head=newnode;
        newnode->next=head;
    }
    else{
        node *temp=head;
        newnode->next=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        head=newnode;
    }
}
void insert_end(){
    node *newnode=getNode();
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
    }
    else{
        node *temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        newnode->next=head;
        temp->next=newnode;
    }
}
void insert_pos(int pos){
    node *newnode=getNode();
    if(pos==1){
        newnode->next=head;
        head=newnode;
        return;
    }
    node *temp=head;
    int i;
    for(i=1;i<pos-1&&temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("invalid position");
        free(newnode);
        return ;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
void delete_start(){
    if(head==NULL){
        printf("no node\n");
    }
    else if(head->next==head){  
        free(head);
        head=NULL;
    }
    else{
        node *temp=head;
        node *last=head;
        while(last->next!=head){
            last=last->next;
        }
        head=head->next;       
        last->next=head;       
        free(temp);
    }
}

void delete_end(){
    if(head==NULL){
        printf("no node");
    }
    else{
        node *temp=head;
        node *before;
        while(temp->next!=head){
            before=temp;
            temp=temp->next;
        }
        before->next=head;
        free(temp);
    }
}
void delete_pos(int pos){
    int i;
    if(pos==1)
    {
        node *temp=head;
        head=temp->next;
        free(temp);
    }
    else{
        node *temp=head;
        node *before;
        for(i=1;i<=pos-1&&temp!=NULL;i++){
            before=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            printf("invalid position");
        }
        before->next=temp->next;
        free(temp);
    }
}
void search(int key){
    node *temp=head;
    int count=0;
    if(head==NULL){
        printf("no node");
    }
    do{
        count++;
        if(temp->data==key)
        {
            printf("key is found at %d position",count);
            break;
        }
        else{
            temp=temp->next;
        }
    }
    while(temp!=head);
    if(temp==head){
        printf("key not found");
    }
}

int main(){
int n;
do{
printf("\t MENU\n1. Create\n2.insert_begin\n3.insert_end\n4.insert_pos\n5. Display\n6. Count\n7.detele_start\n8.delete_end\n9.delete at pos\n10.search\n11.Exit\n");
printf("Enter your choice");
scanf("%d",&n);
switch (n){
case 1: CreateCircularlist(5); break;
case 2: insert_begin();break;
case 3: insert_end();break;
case 4: insert_pos(3);break;
case 5: display(head); break;
case 6: printf("\n Count=%d\n",count(head)); break;
case 7: delete_start();break;
case 8: delete_end();break;
case 9: delete_pos(3);break;
case 10: search(6);break;

}
}
while(n!=11);
return 0;
}
