// Given an sorted DLL and we find no of triplets whose sum is equals to target .
using namespace std ;
#include<bits/stdc++.h>
struct node {
    int data ;
    struct node *prev , *next ;
};
struct node *createNewNode(int key){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = key ;
    newNode->next = nullptr ;
    newNode->prev = nullptr ;
    return newNode ;
}
void displayLinkedList(struct node *head){
    while(head){
        cout << head->data  ;
        head = head->next;
        if(head) cout << " " ;
    }
    cout << endl;
}
struct node *insertAtEnd(struct node *head , int key){
    struct node *newNode = createNewNode(key);
    if(head == nullptr) return newNode ;
    struct node *ptr = head ;
    while(ptr->next){
        ptr = ptr->next ;
    }
    ptr->next = newNode ;
    newNode->prev = ptr ;
    return head ;
}
void removeAllOccurenceOfElementsInDLL(struct node *head, int toBeRemoved){
    if(head == nullptr) {return ;}
    struct node *ptr = head->next ;
    struct node *previousNode = head ;
    while(ptr){
        if(ptr->data == toBeRemoved){
            cout << "Current Node : " << ptr->data << endl ;
            previousNode->next = ptr->next ;
            if(ptr->next)
            ptr->next->prev = previousNode; 
            free(ptr);
            ptr = previousNode->next ;

        }
        else{
            cout << "Current Node : no matched " << ptr->data << endl; 
            previousNode = ptr ;
            ptr = ptr->next;
        }
       
    }
     // we haven't checked the First Node . So for that we need a check 
        if(head->data == toBeRemoved){
                head = head->next ;
                head->prev = nullptr ;
        }
    displayLinkedList(head) ;
}
int main(){
    struct node *head = nullptr ;
    for(int i = 0 ; i < 6 ; i++) 
        head = insertAtEnd(head ,i) ;
    displayLinkedList(head);
    removeAllOccurenceOfElementsInDLL(head , 1);
    return 0;
}

/*
1-2-3-4-5


*/