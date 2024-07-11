SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    if (llist == NULL || llist->next == NULL) {
        return llist;
    }
    
    SinglyLinkedListNode* current = llist;
    
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            SinglyLinkedListNode* duplicate = current->next;
            current->next = current->next->next;
            free(duplicate);
        } else {
            current = current->next;
        }
    }
    
    return llist;
}
