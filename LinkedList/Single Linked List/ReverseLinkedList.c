struct node ReverseLinkedList(struct node *head){
    if(head == NULL || head->next == NULL)
        return head;
    struct node *current = head->next;
    struct node *nextNode = NULL;
    head->next = NULL;
    while(current){
        nextNode = current->next;
        current->next = head;
        head = current;
        current = nextNode;
    }
    return head;
}