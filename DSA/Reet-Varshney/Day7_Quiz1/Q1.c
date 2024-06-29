SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    if (!llist) return NULL;

    SinglyLinkedListNode* current = llist;
    while (current->next) {
        if (current->data == current->next->data) {
            SinglyLinkedListNode* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
    return llist;
}
