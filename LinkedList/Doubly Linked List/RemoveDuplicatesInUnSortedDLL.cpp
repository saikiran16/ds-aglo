// Given an Unsorted DLL and we must remove all Duplicates.
// We can slove this using a Set .We will take unordered_set as time for accessing elements can be in constant time .
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
void removeDuplicatesInUnsortedDLL(struct node *head){
    unordered_set<int> elements ; 
    struct node *ptr = head->next ;
    struct node *nextNode ;
    elements.insert(head->data) ;
    while(ptr){
        if(elements.find(ptr->data) != elements.end()){
            ptr->prev->next = ptr->next ;
            if(ptr->next){
            ptr->next->prev = ptr->prev ;
            }
            
            nextNode = ptr->next ;
            free(ptr) ;
            ptr  = nextNode ;
        }
        else{
            elements.insert(ptr->data);
            ptr = ptr->next ;
        }
    }
    displayLinkedList(head);
}
int main(){
    struct node *head = nullptr ;
    head = insertAtEnd(head , 1);
    head = insertAtEnd(head , 1);
    head = insertAtEnd(head , 2);
    head = insertAtEnd(head , 2);
    head = insertAtEnd(head , 3);
    head = insertAtEnd(head , 4);
    head = insertAtEnd(head , 5);
    head = insertAtEnd(head , 5);
    cout << "Bofore Removing Duplicates  : " ;
    displayLinkedList(head);
    cout << "After Removing Duplicates   : " ;
    removeDuplicatesInUnsortedDLL(head );
    return 0;
}

/*
1-2-3-4-5


*/