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
struct node *insertAtBegining(struct node *tail, int key){
    struct node *newNode = createNewNode(key);
    if(tail == nullptr){
        tail = newNode ;
        tail->next = tail ;
    }
    else{
        newNode->next = tail->next ;
        tail->next = newNode;
    }
    return tail ;
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
int main(){
   
    struct node *tail = nullptr  ;
    for(int i = 0 ; i < 8 ; i++){
        tail = insertAtBegining(tail , i);
        
    }
    displayCircularLinkedList(tail->next);
   

}