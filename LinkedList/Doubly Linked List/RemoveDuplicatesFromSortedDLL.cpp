// Swap Kth Nodes from start and end  in a Single Linked List
// Do In place swappings . That is Swaps nodes but do not swap data .
using namespace std ;
#include<bits/stdc++.h>
struct node{
    int data ;
    struct node *next ;
};
struct node *createNewNode(int data){
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->next = nullptr ;
    newNode->data = data ;
    return newNode ;
}
void displayLinkedList(struct node *head){
    if(head == nullptr) { cout << "empty Linked List " << endl ; return ;}
    while(head){
        cout << head->data << " ";
        head = head->next ;
        if(head) cout << " -> " ;
    }
    cout <<endl;
}
void removeDuplicates(struct node *head){
    if(head ==nullptr || head->next == nullptr ) return  ;
    struct node *currentNode = head ;
    struct node *ptr = currentNode->next ;
    while(ptr){
        if(ptr->data == currentNode->data){
            ptr = ptr->next ;
        }
        else{
            currentNode->next = ptr ;
            currentNode = ptr ;
            ptr = ptr->next ;
        }
    }
    currentNode->next = nullptr;
    displayLinkedList(head);
    return;
}


int main(){
    struct node *head = createNewNode(10);
    head->next = createNewNode(10);
    head->next->next = createNewNode(30);
    head->next->next->next = createNewNode(30);
    head->next->next->next->next = createNewNode(30);
    head->next->next->next->next->next = createNewNode(60);
    displayLinkedList(head);
    removeDuplicates(head );
    

}