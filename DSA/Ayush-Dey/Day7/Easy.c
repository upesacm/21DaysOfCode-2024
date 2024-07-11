//Delete duplicate-value nodes from a sorted linked list
//Author- Ayush Dey

      SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* llist) {
    SinglyLinkedListNode* current = llist;
    while (current != NULL && current->next != NULL) {
    if (current->data == current->next->data) {
            SinglyLinkedListNode* new_next = current->next->next;
            free(current->next);
            current->next = new_next;  } 
    else {
            current = current->next;
         }}
return llist;}