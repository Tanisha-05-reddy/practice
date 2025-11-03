#include<stdio.h>
#include<stdlib.h>
struct AVL{
	struct AVL *lptr;
	int data;
	int height;
	struct AVL *rptr;
};
typedef struct AVL node;
node *root=NULL;
node *getNode(int val){
	node *newNode=(node*)malloc(sizeof(node));
	newNode->data=val;
	newNode->height=0;
	newNode->lptr=NULL;
	newNode->rptr=NULL;
	return newNode;
}
int getHeight(node *ht){
	if(ht==NULL)
	return -1;
	return ht->height;
}
int getBalance(node *curr){
	if(curr==NULL)
	return 0;
	return getHeight(curr->lptr)-getHeight(curr->rptr);
}
node* insert(node* root,int val){
	node* newNode=getNode(val);
	if(root==NULL){
		root=newNode;
	}
	else if(val<root->data){
		root->lptr=insert(root->lptr,val);
	}
	else if(val>root->data){
		root->rptr=insert(root->rptr,val);
	}
	else
		return root;
	root->height=1+max(getHeight(root->lptr),getHeight(root->rptr));
	int balance=getBalance(root);
	if(balance>1 && val < root->left->data){
		return RightRotate(root); 
	}
	else if(balance>1 && val>root->left->data){
	root->left=LeftRotate(root->lptr);
	return RightRotate(root);
	}
	else if(balance<-1 && val>root->rptr->data){
		return LeftRotate(root);
	}
	else if(balance <-1 && val<root->rptr->data){
		root->rptr=RightRotate(root->rptr);
		return LeftRotate(root);
	}
}
int max(int h1,int h2){
	return (h1>h2?h1:h2);
}
void preorder(node *root) {
    if (root != NULL) {
    	int balance=getBalance(root);
        printf("%d : %d->", root->data,balance);
        preorder(root->left);
        preorder(root->right);
    }
}
node* LeftRotate(node *y){
	node *x=y->rptr;
	node *t2=x->lptr;
	x->lptr=y;
	y->rptr=t2;
	y->height=1+max(getHeight(y->lptr),getHeight(y->rptr));
	x->height=1+max(getHeight(x->lptr),getHeight(x->rptr));
	return x;
}
node* RightRotate(node *y){
	node *x=y->lptr;
	node *t2=x->rptr;
	x->rptr=y;
	y->lptr=t2;
	y->height=1+max(getHeight(y->lptr),getHeight(y->rptr));
	x->height=1+max(getHeight(x->lptr),getHeight(x->rptr));
	return x;
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
/*node* deleteNode(node *root, int key) {
    if (root == NULL)
        return root;
    else if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL && root->right == NULL)
			{
            free(root);
            return NULL;
        } else if (root->left == NULL)
	{
            node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) 
{
            node *temp = root->left;
            free(root);
            return temp;
        } else {
            node *temp = getmin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}*/
int main(){
	int x;
	while(1){
		printf("AVL\n 1.Insert\n 2.inOrder\n 3.preOrder\n 4.postOrder\n 5.search\n 6.find min value\n 7.maxValue\n 8.height\n 9.exit(0)\n");
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
			x=getHeight(root);printf("%d is height",x);break;
		case 9:
			exit(0);
		}
	}
	return 0;
}