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
void removeDuplicates_InUnsortedLL(struct node *head){
    if(head == nullptr || head->next == nullptr) return  ;
    struct node *current_node = head->next ;
    set<int> s ;
    s.insert(head->data);
    while(current_node){
        if(s.find(current_node->data) == s.end()){
            s.insert(current_node->data);
            head->next = current_node ;
            head = head->next ;
        }
        current_node = current_node->next;
        
    }
    head->next = nullptr;
}
int main(){
    struct node *head = createNewNode(10);
    head->next = createNewNode(100);
    head->next->next = createNewNode(30);
    head->next->next->next = createNewNode(5);
    head->next->next->next->next = createNewNode(60);
    head->next->next->next->next->next = createNewNode(60);
    removeDuplicates_InUnsortedLL(head);
    displayLinkedList(head);

}