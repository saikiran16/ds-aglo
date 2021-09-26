using namespace std ;
#include<bits/stdc++.h>
struct node {
    int data ;
    struct node *next;
};

struct node *createNewNode(int data){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data ;
    newNode->next = nullptr ;
    return newNode ;
}
struct node *insertAtBegining(struct node *head , int data) {
    struct node *newNode = createNewNode(data);
    if(head == nullptr)
        return newNode ;
    newNode->next = head ;
    return newNode ;
}
struct node *insertAtEnding(struct node *head , int data){
    struct node *newNode = createNewNode(data);
    if(head == nullptr) return newNode ;
    struct node *ptr = head ;
    while(ptr->next){
        ptr = ptr->next;
    }
    ptr->next = newNode ;
    return head ;
}
struct node *insertAtPosition(struct node *head , int data , int pos){
    struct node *newNode = createNewNode( data);
    if(pos - 1 == 0) return insertAtBegining(head , data);
    struct node *prev = nullptr ;
    struct node *ptr = head;
    for(int i = 1 ; i < pos  ; i++){
        prev = ptr ;
        ptr = ptr->next ;
        
    }
     prev->next = newNode ;
     newNode->next = ptr ;
     return head;


}

struct node *deleteAtBegining(struct node *head ){
    if(head == nullptr || head->next == nullptr) return nullptr ;

    struct node *ptr = head ;
    head = head->next ;
    ptr->next = nullptr ;
    free(ptr) ;
    return head ;
}
struct node *deleteAtEnding(struct node *head){
    if(head == nullptr || head->next == nullptr) return nullptr ;
    struct node *ptr = head ;
    struct node *prev = nullptr ;
    while(ptr->next){
        prev = ptr;
        ptr = ptr->next ;
    }
    prev->next = nullptr ;
    return head ;

}
struct node *deleteAtPosition(struct node *head , int pos){
    if(head == nullptr) return nullptr ;
    struct node *ptr = head ;
    struct node *prev = head ;
    if(pos - 1 == 0){
        ptr = head ;
        free(ptr);
        return head->next ;
    } 
    for(int i = 1 ; i < pos ; i++){
        prev = ptr ;
        ptr = ptr->next ;
    }
    prev->next = prev->next->next ;
    return head ;
}
void displayLinkedList(struct node *head){
    if(head == nullptr) cout << "empty LinkedList " << endl;
    while(head){
        cout << head->data << " " ;
        head = head->next ;
        if(head) cout << "-> " ;
    }
    cout << endl;
}
struct node *deleteEntireLinkedList(struct node *head){
    struct node *next ;
    while(head){
        next = head->next ;
        free(head);
        head = next ;
    }
    return head ;
}
int main(){
    struct node *head = nullptr ;
    head = insertAtBegining(head , 10);
    head = insertAtBegining(head , 20);
    head = insertAtBegining(head , 30);
    head = insertAtEnding(head , 40);
    head = insertAtEnding(head , 50);
    head = insertAtEnding(head , 60);
    head = insertAtPosition(head , 70 , 3);
    head = deleteAtBegining(head);
    head = deleteAtEnding(head) ;
    head = deleteAtPosition(head , 4);
    displayLinkedList(head) ;
    head = deleteEntireLinkedList(head);
    displayLinkedList(head);
    return 0;
}