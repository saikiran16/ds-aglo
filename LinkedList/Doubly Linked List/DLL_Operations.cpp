using namespace std ;
#include<bits/stdc++.h>
struct node {
    int data ;
    struct node *left , *right ;
};
struct node *createNewNode(int key){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = key ;
    newNode->right = nullptr ;
    newNode->left = nullptr ;
    return newNode ;
}
void displayLinkedList(struct node *head){
    while(head){
        cout << head->data  ;
        head = head->right;
        if(head) cout << " " ;
    }
}
struct node *insertAtBegining(struct node *head,int key){
    struct node *newNode = createNewNode(key);
    if(head == nullptr) return newNode ;
    newNode->right = head ;
    head->left = newNode ;
    head = newNode ;
    return head ;
}
struct node *insertAtEnd(struct node *head , int key){
    struct node *newNode = createNewNode(key);
    if(head == nullptr) return newNode ;
    struct node *ptr = head ;
    while(ptr->right){
        ptr = ptr->right ;
    }
    ptr->right = newNode ;
    newNode->left = ptr ;
    return head ;
}
struct node *insertAtPosition(struct node *head , int pos , int key){
    if(pos == 0) return insertAtBegining(head , key); // Here pos is zero based indexing
    struct node *prev = head , *current_node = head ;
    for(int i = 0 ; (i < pos && current_node) ; i++){
        prev = current_node  ;
        current_node =  current_node->right ;
    }
    if(current_node== nullptr){
        return insertAtEnd(head , key);
    }
    struct node *newNode = createNewNode(key);
    newNode->left = prev ;
    newNode->right = current_node ;
    prev->right = newNode ;
    current_node->left = newNode ;
    return head ;
}
struct node *deleteAtBegining(struct node *head){
    if(head == nullptr) return nullptr;
    head = head->right ;
    head->left->right = nullptr ;
    free(head->left);
    head->left = nullptr ;
    return head ;
}
struct node *deleteAtEnd(struct node *head){
    if(head == nullptr || head->right == nullptr) return nullptr ;
    while(head->right){
        head = head->right ;
    }
    head = head->left ;
    free(head->right);
    head->right = nullptr ;
    return head ;
}
struct node *deleteAtPosition(struct node *head , int pos){ // zero based positiin .
    if(pos == 0) return deleteAtBegining(head);
    struct node *current_node = head ;
    for(int i = 0 ; (i < pos && current_node) ; i++){
       // cout << current_node   << i << " " << endl;
        current_node = current_node->right ;
    }
    if(current_node == nullptr){ // Invalid position
        return head;
    }
    else{
        current_node = current_node->left ;
        current_node->right = current_node->right->right ;
        current_node->right->left = current_node ;
    }
    return head ;
}
int main(){
    struct node *head = nullptr ;
    for(int i = 0 ; i < 6 ; i++) 
        head = insertAtPosition(head ,i , i);
    displayLinkedList(head);cout << endl;
    head = deleteAtPosition(head , 10);
    displayLinkedList(head);
    
}
