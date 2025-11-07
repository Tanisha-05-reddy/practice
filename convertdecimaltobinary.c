#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 101
char a[MAX_SIZE];
int top = -1;

void push(char ele){
    if(top<=MAX_SIZE-1){
        a[++top]=ele;
    }
    else{
        printf("Stack is full. Cannot push: %c\n",ele);
    }
}

int pop(){
    if(top>=0){
        return a[top--];
    }
    else{
        printf("Stack is empty. Cannot pop.\n");
        return '\0';
    }
}

int isEmpty(){
    return top==-1;
}

int isFull(){
    return top>=MAX_SIZE;
}

char* decimalToBinary(int decimal){
    if(decimal == 0) {
        char* zero = (char*)malloc(2);
        zero[0] = '0';
        zero[1] = '\0';
        return zero;
    }
    while (decimal > 0) {
        // Update the code below
        char bit = (decimal % 2) + '0';
        push(bit);
        decimal /= 2;
    }

    char* ans = (char*)malloc(MAX_SIZE);
    int i=0;
    while(!isEmpty()){
        ans[i++] = pop();
    }
    ans[i] = '\0';
    return ans;
}

int main(){
    int t;
    scanf("%d",&t);

    while(t--){
        int decimal;
        scanf("%d",&decimal);
        char* ans = decimalToBinary(decimal);
        printf("%s\n", ans);
        free(ans);
        }
        printf("\n");
    }
}
