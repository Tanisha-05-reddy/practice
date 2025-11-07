#include <stdio.h>
#include <stdlib.h>

// Structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp->next != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}

// Function to remove duplicates from the linked list
void removeDuplicates(struct Node* head) {
    struct Node* current = head;
    
    while(current != NULL && current->next != NULL)
    {
        if(current->data == current->next->data)
        {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
        }else{
            current = current->next;
        }
    }
    
    
    
    
}

int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    int n, data;

    // Input number of nodes
    scanf("%d", &n);

    // Input values for the linked list nodes
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        struct Node* new_node = newNode(data);

        if (head == NULL) {
            head = new_node;  // First node becomes the head
        } else {
            temp->next = new_node;  // Link the new node to the previous one
        }
        temp = new_node;  // Move temp to the new node
    }


    // Remove duplicates from the linked list
    removeDuplicates(head);

    // Print the linked list after removing duplicates
    printList(head);

    return 0;
}
