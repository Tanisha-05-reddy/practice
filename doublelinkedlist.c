#include <stdio.h>
#include <stdlib.h>

struct DLL {
    int data;
    struct DLL* next;
    struct DLL* prev;
};

typedef struct DLL node;
node* head = NULL;

node* getNode() {
    node* newNode = (node*)malloc(sizeof(node));
    printf("Enter value: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int count() {
    int c = 0;
    node* temp = head;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    return c;
}

void displayForward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node* temp = head;
    printf("List (forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayBackward() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("List (backward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void insertBegin() {
    node* newNode = getNode();
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertEnd() {
    node* newNode = getNode();
    if (head == NULL) {
        head = newNode;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertPos(int pos) {
    int n = count();
    if (pos < 1 || pos > n+1) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        insertBegin();
        return;
    }
    if (pos == n+1) {
        insertEnd();
        return;
    }
    node* newNode = getNode();
    node* temp = head;
    for (int i = 1; i < pos-1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteBegin() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node* temp = head;
    if (head->next != NULL) {
        head = head->next;
        head->prev = NULL;
    } else {
        head = NULL;
    }
    free(temp);
}

void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    node* temp = head;
    if (head->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void deletePos(int pos) {
    int n = count();
    if (pos < 1 || pos > n) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        deleteBegin();
        return;
    }
    if (pos == n) {
        deleteEnd();
        return;
    }
    node* temp = head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

void search(int key) {
    node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Value %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Value %d not found in list\n", key);
}

int main() {
    int choice, pos;
    while (1) {
        printf("Doubly Linked List Menu");
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at position\n");
        printf("4. Delete from beginning\n5. Delete from end\n6. Delete from position\n");
        printf("7. Display forward\n8. Display backward\n9. Count\n10. Search\n11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: insertBegin(); break;
            case 2: insertEnd(); break;
            case 3: 
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                insertPos(pos);
                break;
            case 4: deleteBegin(); break;
            case 5: deleteEnd(); break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deletePos(pos);
                break;
            case 7: displayForward(); break;
            case 8: displayBackward(); break;
            case 9: printf("Number of nodes: %d\n", count()); break;
            case 10:
                printf("Enter value to search: ");
                int key;
                scanf("%d", &key);
                search(key);
                break;
            case 11: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
