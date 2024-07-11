SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    if (!llist) return nullptr;

    SinglyLinkedListNode* current = llist;
    while (current->next) {
        if (current->data == current->next->data) {
            SinglyLinkedListNode* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    return llist;
}
