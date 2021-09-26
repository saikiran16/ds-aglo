/*
Given a sorted doubly linked list and a value to insert, write a function to insert the value in sorted way.
Initial doubly linked list
Case 1 : If head is null return null 
Case 2 : If data we like to insert is smaller than startig node then we need to insert ar begining 
Case 3 : Else we need to insert at the right position . we need to take care while inserting  because if may be last node .
*/
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
struct node *insertInSortedDLL(struct node *head , int key){
    struct node *newNode = createNewNode(key) ;

    //Case 1 : If head is null return null 
    if(head == nullptr )return head ;
    
    // Case 2 : If data we like to insert is smaller than startig node then we need to insert ar begining 

    if(head->data >= newNode->data){
        newNode->right = head ;
        head->left = newNode ;
        head = newNode ;
    }

    //Case 3 : Else we need to insert at the right position . we need to take care while inserting  because if may be last node .

    else{
        
        struct node *prev =  nullptr;
        struct node *ptr = head ;
        while(ptr!= nullptr && ptr->data < newNode->data){
            prev = ptr ;
            ptr= ptr->right ;    
        }
        
        if(ptr == nullptr){
            prev->right = newNode ;
            newNode->left = prev ;
        }
        else{
            prev->right = newNode ;
            newNode->left = prev ;
            newNode->right = ptr;
            ptr->left = newNode ;
        }

    }
    return  head;

}
int main(){
    struct node *head = nullptr ;
    for(int i = 0 ; i < 6 ; i++) 
        head = insertAtEnd(head ,i);
    displayLinkedList(head);
    head = insertInSortedDLL(head ,-1) ;
    displayLinkedList(head);
    
}

/*
1-2-3-4-5


*/