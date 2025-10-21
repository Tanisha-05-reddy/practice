#include <stdio.h>
#include <stdlib.h>
#define MAX

struct stack
{
    int data;
    struct stack* next;
};

typedef struct stack Node;

Node *head = NULL;
Node *top = NULL;

int count(Node *head)
{
    int c = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }
    return c;
}

Node* getNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void push(int value)
{
    if (count(head) == MAX)
    {
        printf("Stack Overflow! Cannot insert more nodes.\n");
        return;
    }
    Node* newNode = getNode(value);
    newNode->next = head;
    head = newNode;
    top = newNode;
    printf("%d pushed to stack\n", value);
}

void pop()
{
    if (head == NULL)
    {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }
    Node* temp = head;
    printf("%d popped from stack\n", temp->data);
    head = head->next;
    top = head;
    free(temp);
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is %d\n", top->data);
}

void display()
{
    if (head == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = head;
    printf("Stack elements (top to bottom): ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("Stack Menu\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Count\n6. Exit\n");
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
                printf("Number of elements in stack: %d\n", count(head));
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
