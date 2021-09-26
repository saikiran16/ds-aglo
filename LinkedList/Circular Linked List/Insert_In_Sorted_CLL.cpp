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
struct node *sortedInsert(struct node *head, int data)
{
    //code here
    
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data ;
    newNode->next = NULL ;
    if(head == NULL){
        newNode->next = newNode ;return newNode ;
    } 
    struct node *ptr = head  , *tail = head ,*prev= head ;
    do{
        tail = tail->next ;
    }while(tail->next != head);
    if(head->data > data){
        newNode->next = head ;
        tail->next = newNode ;
        head = newNode ;
        return head;
    }
    else{
        ptr = head->next ; 
        while(ptr != head && ptr->data < data){
            prev = ptr ;
            ptr = ptr->next ;
        }
        prev->next = newNode ;
        newNode->next = ptr ;
    }
    return head ;
    
}
int main(){
    struct node *tail = nullptr ;
    for(int i = 0 ; i < 10 ; i++){
        tail = insertAtEnd(tail , i);
    }
    displayCircularLinkedList(tail->next);
    struct node *head = sortedInsert(tail->next,-1);
    displayCircularLinkedList(head);
    return 0;
}