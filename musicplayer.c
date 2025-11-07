#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
    struct node* next;
    struct node* prev;   // Additional pointer for doubly linked list
};

struct node* head;
struct node* cur;

struct node* node_new(int val){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = val;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void addSong(int songId){
    struct node* newsong = node_new(songId);
    // Consider the case when list is empty too
    if(head == NULL){
        head = newsong;
        cur = newsong;
    } else {
        struct node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newsong;
        newsong->prev = temp;
    }
    
}

void nextSong(){
    if(cur!= NULL && cur -> next != NULL){
        cur = cur->next;
    }
}

void prevSong(){
    if(cur != NULL && cur->prev != NULL){
        cur = cur -> prev;
    }
}

void switchSong(int songId){
    struct node* temp = head;
    while(temp != NULL){
        if(temp->value == songId){
            cur = temp;
            return;
        }
        temp = temp->next;
    }
}

int current(){
    if(cur != NULL){
        return cur->value;
    }
    return -1;
}

int main() {
    head=NULL;
    cur=NULL;
    int n;
    scanf("%d",&n);
    while(n--){
        int q;
        scanf("%d",&q);
        if(q==1){
            int songId;
            scanf("%d",&songId);
            addSong(songId);
        }
        else if(q==2){
            nextSong();
        }
        else if(q==3){
            prevSong();
        }
        else if(q==4){
            int songId;
            scanf("%d",&songId);
            switchSong(songId);
        }
        else{
            int ans = current();
            printf("%d\n",ans);
        }
    }
}
