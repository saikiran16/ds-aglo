using namespace std ;
#include<bits/stdc++.h>
struct node{
    int data ;
    struct node *next ;
};
struct node *createNewNode(int) ;
void displayCircularLinkedList(struct node *head);
struct node *insertAtEnd(struct node *tail , int key);

bool isCircular(struct node *head){
    //code here
    if(head == NULL) return true ;
    struct node *ptr = head ;
    do{
        ptr = ptr->next ;
    }while(ptr && head != ptr);
    if(ptr == NULL) return false ;
    return true ;
}
int main(){
   
    struct node *tail = nullptr  ;
    for(int i = 0 ; i < 8 ; i++){
        tail = insertAtEnd(tail , i);
        
    }
    displayCircularLinkedList(tail->next);
   return 0;

}


struct node *createNewNode(int data){
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->next = nullptr ;
    newNode->data = data ;
    return newNode ;
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