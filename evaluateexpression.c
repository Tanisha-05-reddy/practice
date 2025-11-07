#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function to create a stack with a given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element to the stack
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return -1;
}

// Function to perform the evaluation of a suffix expression
int evaluateSuffixExpression(char* suffix) {
    struct Stack* stack = createStack(MAX_SIZE);
    for (int i = 0; suffix[i] != '\0'; i++){
        char ch = suffix[i];
        if(isdigit(ch)){
            push(stack, ch- '0');
        } else {
            int val2 = pop(stack);
            int val1 = pop(stack);
            int result;
            
            switch(ch){
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '^': result = pow(val1, val2); break;
                default:
                printf("Invalid operator: %c\n", ch);
                result = 0;
            }
            push(stack, result);
        }
    }
    //Write your code here
    return pop(stack);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        char suffix[n];
        scanf("%s", suffix);
        int result = evaluateSuffixExpression(suffix);
    
        printf("%d\n", result);
    
    }
}
