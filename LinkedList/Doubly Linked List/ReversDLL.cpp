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
    cout << endl;
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
struct node *reverseDLL(struct node *head){
    if(head == nullptr || head->right == nullptr) return head ;
    struct node *current_node = head ;
    struct node *next = head->right;
    current_node->right = nullptr ;
    while(next){
        current_node = next ;
        next = next->right ;
        current_node->right = head ;
        current_node->left = nullptr ;
        head->left = current_node ;
        head  = current_node ;
       
       
    }
    return head ;
}
int main(){
    struct node *head = nullptr ;
    for(int i = 0 ; i < 6 ; i++) 
        head = insertAtEnd(head ,i) ;
    displayLinkedList(head);
    head = reverseDLL(head);
    displayLinkedList(head);
    
}

/*
1-2-3-4-5


*/