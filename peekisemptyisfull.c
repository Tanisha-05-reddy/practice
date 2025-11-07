int peek(){
    if(top >= 0){
        int ele = a[top];
        printf("Peeked: %d\n", ele);
        return ele;
    }
    else{
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }
}

int isEmpty(){
    return top == -1;
}

int isFull(){
    if(top >= MAX_SIZE - 1){
        return 1;
    }
    else{
        return 0;
    }
}
