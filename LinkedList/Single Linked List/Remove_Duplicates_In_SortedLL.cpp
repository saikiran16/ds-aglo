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

void removeDuplicatesInSortedLL(struct node *head){
     if(head == nullptr || head->next == nullptr) return ;;
    struct node *ptr = head ;
    struct node *current_node = head->next ;
    while(current_node){
        if(current_node->data != ptr->data){
            ptr->next = current_node ;
            ptr = ptr->next ;

        }
        current_node = current_node->next ;
    }
    ptr->next = nullptr ;
    

}

int main(){
    struct node *head = createNewNode(10);
    head->next = createNewNode(20);
    head->next->next = createNewNode(20);
    head->next->next->next = createNewNode(20);
    head->next->next->next->next = createNewNode(60);
    head->next->next->next->next->next = createNewNode(60);
    removeDuplicatesInSortedLL(head);
    displayLinkedList(head) ;

}