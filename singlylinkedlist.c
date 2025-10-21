#include <stdio.h>
#include <stdlib.h>

struct SLL {
    int data;
    struct SLL *next;
};
typedef struct SLL node;

node *head = NULL;

node *getNode() {
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    return newNode;
}

void createList(int n) {
    node *newNode;
    int i;
    node *temp;
    for (i = 1; i <= n; i++) {
        newNode = getNode();
        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void display(node *temp) {
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%5d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int count(node *temp) {
    int c = 0;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    return c;
}

void insert_at_beginning() {
    node *newNode = getNode();
    newNode->next = head;
    head = newNode;
}

void insert_at_end() {
    node *newNode = getNode();
    if (head == NULL)
        head = newNode;
    else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insert_at_pos(int pos) {
    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }
    node *newNode = getNode();
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    node *temp = head;
    int i;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void delete_at_beggining() {
    if (head == NULL) {
        printf("No node to delete\n");
        return;
    }
    node *temp = head;
    head = head->next;
    free(temp);
}

void delete_at_end() {
    if (head == NULL) {
        printf("There is no node to delete\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    node *temp = head;
    node *prev_node = NULL;
    while (temp->next != NULL) {
        prev_node = temp;
        temp = temp->next;
    }
    prev_node->next = NULL;
    free(temp);
}

void delete_at_pos(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }
    node *temp = head;
    if (pos == 1) {
        head = temp->next;
        free(temp);
        return;
    }
    int i;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position\n");
        return;
    }
    node *node_to_delete = temp->next;
    temp->next = node_to_delete->next;
    free(node_to_delete);
}
void search_element() {
    int key;
    printf("Enter key to search: ");
    scanf("%d", &key);

    node *temp = head;  
    int found = 0; 

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found in the list.\n", key);
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if (!found) {
        printf("Element %d not found in the list.\n", key);
    }
}

int main() {
    while (1) {
        int x;
        printf("\n1. Create \n2. Insert at beginning \n3. Insert at end \n4. Insert at any position \n5. Delete at beginning \n6. Delete at end \n7. Delete at specific position \n8.serach element \n9. Display \n10. Count \n11. Exit\n");
        printf("Choose your choice: ");
        scanf("%d", &x);

        switch (x) {
        case 1:
            createList(5);
            break;
        case 2:
            insert_at_beginning();
            break;
        case 3:
            insert_at_end();
            break;
        case 4: {
            int pos;
            printf("Enter position to insert: ");
            scanf("%d", &pos);
            insert_at_pos(pos);
            break;
        }
        case 5:
            delete_at_beggining();
            break;
        case 6:
            delete_at_end();
            break;
        case 7:
         {
             int pos;
            delete_at_pos(pos);
            break;
        }
        case 8 :
            search_element(8);
            break;
        case 9:
            display(head);
            break;
        case 10:
            printf("The number of nodes = %d\n", count(head));
            break;
        case 11:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

