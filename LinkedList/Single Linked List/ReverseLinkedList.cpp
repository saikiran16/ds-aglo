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

struct node  *reverseLinkedList(struct node *head){
    if(head == nullptr || head->next == nullptr) return head ;
    struct node *current_node = head ;
    struct node *next_node =head->next;
    head = nullptr ;
    while(current_node){
        current_node->next = head ;
        head = current_node ;
        current_node = next_node ;
        if(next_node)
        next_node = next_node->next ;

    }
    return head; 
}

int main(){
    struct node *head = createNewNode(10);
    head->next = createNewNode(20);
    head->next->next = createNewNode(30);
    head->next->next->next = createNewNode(40);
    head->next->next->next->next = createNewNode(50);
    head->next->next->next->next->next = createNewNode(60);
    displayLinkedList(head);
    displayLinkedList(reverseLinkedList(head)) ;
    

}