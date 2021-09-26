// Write a C function to insert a new value in a sorted Circular Linked List (CLL)

using namespace std ;
#include<bits/stdc++.h>
struct node {
    int data ;
    struct node *next ;
} ;
struct node* createNewNode(int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data ;
    newNode->next = nullptr ;
    return newNode ;
}
struct node *insertAtEnd(struct node *tail , int key){
    struct node *newNode = createNewNode(key);
    if(tail == nullptr){
        newNode->next = newNode ;
        tail = newNode;
    }
    newNode->next = tail->next ;
    tail->next = newNode ;
    tail = newNode ;
    
    return tail ;
}
void displayCircularLinkedList(struct node *head){
    if(head == nullptr) { cout << "empty Linked List " << endl ; return ;}
    struct node *ptr = head ; 
    do{
        cout << ptr->data  ;
        ptr = ptr->next ;
        if(ptr!=head) cout << "-->";
    }while(ptr!=head);
    cout <<endl;
}
void splitList(struct node  *head, struct node  **head1_ref, struct node  **head2_ref)
{
    if(head == nullptr || head->next == head) {
        *head1_ref = head ;
        *head2_ref = nullptr ;
        return ;
    }
    // your code goes here
    struct node  *slow = head ;
    struct node  *fast = head->next;
    struct node   *prev_of_fast = nullptr ;
    while(fast != head && fast->next != head ){
        slow = slow->next ;
        prev_of_fast = fast->next ;
        fast = fast->next->next ;
    }
    *head1_ref = head ;
    *head2_ref = slow->next ;
    slow->next= *head1_ref ;
    
    if(fast == head){
        prev_of_fast->next = *head2_ref;
    }
    else{
        fast->next = *head2_ref ;
    }
    
}

int main(){
    struct node *tail = nullptr ;
    for(int i = 0 ; i < 10 ; i++){
        tail = insertAtEnd(tail , i);
    }
    displayCircularLinkedList(tail->next);
    struct node *head1_ref = nullptr , *head2_ref = nullptr ;
    splitList(tail->next , &head1_ref , &head2_ref);
    displayCircularLinkedList(head1_ref);
    displayCircularLinkedList(head2_ref);
}