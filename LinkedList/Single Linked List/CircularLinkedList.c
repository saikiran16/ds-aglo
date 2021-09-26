#include<stdio.h>
#include<stdlib.h>
struct node {
    int data ;
    struct node *next;
};
struct node* createNewNode(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
struct node* insertNewNodeAtEnd(struct node* head , struct node* tail ,int value){
    struct node *newNode = createNewNode(value);
    if(tail == NULL)
        tail = newNode;
    else
        tail->next = newNode;
    tail = newNode;
    tail->next = head;
    return tail;
}
void display(struct node *head){
    printf("%d ", head->data);
    struct node *ptr = head->next;
    while(ptr != head){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void insertAtMiddleOfCircularLinkedList(struct node *head , int value){
    if(head == NULL){
        printf("No Elements in Linked List\n");
        return ;
    }
    struct node *ptr = head;
    struct node *fast = head;
    struct node *slow = head;
    int i = 0;
    while((fast != head && fast->next != head )  || i==0){
        slow = slow->next;
        fast = fast->next->next;
        i = 1;
    }
    printf("Middle Node is %d\n", slow->data);
    int temp = slow->data;
    struct node *newNode = createNewNode(value);
    newNode->data = slow->data;
    slow->data = value;
    newNode->next = slow->next;
    slow->next = newNode;
    display(head);
}
int main(int argc, char const *argv[])
{
    struct node *head=NULL, *tail = NULL;
    for (int i = 1; i <=8; i++){
        tail = insertNewNodeAtEnd(head , tail , i);
        if(head == NULL)
            head = tail;
    }
    display(head );
    insertAtMiddleOfCircularLinkedList(head, 1000);
    return 0;
}
