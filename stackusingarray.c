#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

int count()
{
    return top + 1;
}

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow! Cannot insert more elements.\n");
        return;
    }
    top++;
    stack[top] = value;
    printf("%d pushed to stack\n", value);
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }
    printf("%d popped from stack\n", stack[top]);
    top--;
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is %d\n", stack[top]);
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int choice, value;
    while (1)
    {
        printf(" Stack Menu");
        printf("1. Push/n2. Pop\n3. Peek\n4. Display\n5. Count\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Number of elements in stack: %d\n", count());
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
