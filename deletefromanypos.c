
void deleteNode(struct LinkedList* list, int value) {
    if(list ->head==NULL)
    {
        return;
    }
    if (list->head->value == value) {
        struct Node* targetNode = list->head;
        list->head = targetNode->next;
        free(targetNode);
    } else {
        struct Node* iter = list->head;
        
        // Traverse the list
        // When next element is our target element, eliminate it
        while (iter->next != NULL) {
            if (iter->next->value == value) {
                // Set next of iter
                struct Node* targetNode=iter->next;
                iter->next = targetNode->next;
                free(targetNode);
                
                // To next to next of iter
                
                
                
                break;
            }
            iter = iter->next;
        }
    }
}
