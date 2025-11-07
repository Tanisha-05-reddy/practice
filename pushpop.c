// Remove the __ and complete the code
#define MAX_SIZE 101
int a[MAX_SIZE];
int top = -1;

void push(int ele) {
    if (top <= MAX_SIZE - 1) {
        top ++
        a[__] = __;
        printf("Pushed: %d\n", __);
    } else {
        printf("Stack is full. Cannot push: %d\n", ele);
    }
}

int pop() {
    if (top >= 0) {
        int ele = a[__];
        top--;
        printf("Popped: %d\n", ele);
        return __;
    } else {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
}
