#include<stdio.h>
#include<stdlib.h>
struct BST{
	struct BST *lptr;
	int data;
	struct BST *rptr;
};
typedef struct BST node;
node *root=NULL;
node *getNode(int val){
	node *newNode=(node*)malloc(sizeof(node));
	newNode->data=val;
	newNode->lptr=NULL;
	newNode->rptr=NULL;
	return newNode;
}
node* insert(node* root,int val){
	node* newNode=getNode(val);
	if(root==NULL){
		root=newNode;
	}
	else if(val<root->data){
		root->lptr=insert(root->lptr,val);
	}
	else{
		root->rptr=insert(root->rptr,val);
	}
	return root;
}
void inOrder(node* root){
	if(root!=NULL){
		inOrder(root->lptr);
		printf("%d->",root->data);
		inOrder(root->rptr);
	}
}
void preOrder(node* root){
	if(root!=NULL){
		printf("%d->",root->data);
		preOrder(root->lptr);
		preOrder(root->rptr);
	}
}
void postOrder(node* root){
	if(root!=NULL){
		postOrder(root->lptr);
		postOrder(root->rptr);
		printf("%d->",root->data);
	}
}
node* search(node* root,int val){
	if(root==NULL)
	printf("key not found");
	if(root->data==val){
		printf("key found");
		return root;
	}
	else{
		if(val<root->data){
			return search(root->lptr,val);
		}
		else{
			return search(root->rptr,val);
		}
	}
}
void minValue(node* root){
	if(root==NULL){
		printf("tree is empty");
	}
	else{
		while(root->lptr!=NULL){
			root=root->lptr;
		}
		printf("%d",root->data);
	}
}
void maxValue(node* root){
	if(root==NULL){
		printf("tree is empty");
	}
	else{
		while(root->rptr!=NULL){
			root=root->rptr;
		}
		printf("%d",root->data);
	}
}
int main(){
	while(1){
		printf("BST\n 1.Insert\n 2.inOrder\n 3.preOrder\n 4.postOrder\n 5.search\n 6.find min value\n 7.maxValue\n 8.exit(0)\n");
		int choice;
		printf("enter choice");
		scanf("%d",&choice);
		switch(choice){
		case 1:{
			int val;
			printf("enter value");
			scanf("%d",&val);
			root=insert(root,val);
			break;
		}
		case 2:
			inOrder(root);break;
		case 3:
			preOrder(root);break;
		case 4:
			postOrder(root);break;
		case 5:{
			printf("enter element to find");
			int key;
			scanf("%d",&key);
			root=search(root,key);printf("%d->",root->data);break;
		}
		case 6:
			minValue(root);break;
		case 7:
			maxValue(root);break;
		case 8:
			exit(0);
		}
	}
	return 0;
}