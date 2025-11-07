#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
    struct node* next;
};

struct node* head;
struct node* tail;

struct node* node_new(int val){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = val;
    newnode->next = NULL;
    return newnode;
}

void insertAtEnd(int val){
    struct node* newnode = node_new(val);
    if(head==NULL){
        // When the list is empty
        head=newnode;
        tail=newnode;
        newnode->next=head;
        // Note that even though there is not really a head in the list (you can traverse the list starting at any point), we maintain the first node we insert as the head
    }
    else{
        // When the list is not empty
        tail->next=newnode;
        // Adding a new element towards the end of list
        tail=newnode;
        tail->next=head;
        
        // Updating the tail pointer so that it points to the last element
        
    }
    tail->next=head;
}

void print(){
    struct node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp->value);
        if(temp==tail) break;
        temp=temp->next;
    }
    printf("\n");
}

int main() {
    head=NULL;
    tail=NULL;
    int n;
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++){
        int value;
        scanf("%d",&value);
        insertAtEnd(value);
    }
    print();
}
