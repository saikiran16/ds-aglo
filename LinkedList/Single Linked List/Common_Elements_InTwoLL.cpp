//Given two lists sorted in increasing order, create and return a new list representing the intersection of the two lists. 
//The new list should be made with its own memory — the original lists should not be changed. 

#include<bits/stdc++.h>
using namepsace std;
struct node{
    int data ;
    struct node *next;
};
struct node *createNewNode(int k){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = k ;
    newNode->next = nullptr ;
    return newNode ;
}

struct node* findIntersection(struct node* head1, struct node* head2)
{
    // Your Code Here
    struct node *ptr1 = head1 ;
    struct node *ptr2 = head2;
    struct node *finalHead = nullptr ;
    struct node *finalTail = nullptr ;
    while(ptr1 && ptr2){
        if(ptr1->data == ptr2->data){
            if(finalHead == nullptr){
                finalHead = createNewNode(ptr1->data);
                finalTail = finalHead ;
            }
            else{
                finalTail->next = createNewNode(ptr2->data);
                finalTail = finalTail->next;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next ;
            
        }
        else if(ptr1->data > ptr2->data )ptr2 = ptr2->next ;
        else ptr1 = ptr1->next; 
    }
    return finalHead;
    
    
}
int main(){
   
   
}