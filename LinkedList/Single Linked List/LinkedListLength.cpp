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
int lengthOfLinkedList(struct node * head){
    // BruteForce
    struct node *ptr = head ;
    int length = 0 ;
    while(ptr){
        length++ ; ptr = ptr->next ;
    }
    return length ;

}
int main(){
    struct node *head = createNewNode(10);
    head->next = createNewNode(20);
    head->next->next = createNewNode(30);
    head->next->next->next = createNewNode(40);
    head->next->next->next->next = createNewNode(50);
    head->next->next->next->next->next = createNewNode(60);
    displayLinkedList(head);
    cout << lengthOfLinkedList(head) << endl ;

}