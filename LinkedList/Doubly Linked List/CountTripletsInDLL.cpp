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
void findPairs(struct node *head ,int targetSum){
    struct node *ptr_from_starting = head ;
    int length = 0 ;
    while(head->next){
        head = head->next ;
        length++ ;
    }
    length++;
    struct node *ptr_from_ending = head;
    int i = 0 , j = length-1 ;
    while(i < j){
        int current_sum = ptr_from_starting->data + ptr_from_ending->data ;
        if(current_sum == targetSum){
            cout << "Pairs found = {" << ptr_from_starting->data << "," << ptr_from_ending->data <<"}" <<endl;
            return ;
        }
        else if(current_sum > targetSum){
            j-- ;
            ptr_from_ending = ptr_from_ending->prev ;
        }
        else{
            i++;
            ptr_from_starting = ptr_from_starting->next ;
        }

    }
    cout << "Pairs not found "<< endl;
}



int main(){
    struct node *head = nullptr ;
    for(int i = 0 ; i < 6 ; i++) 
        head = insertAtEnd(head ,i) ;
    displayLinkedList(head);
    
    return 0;
}

/*
1-2-3-4-5


*/