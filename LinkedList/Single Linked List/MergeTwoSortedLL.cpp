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
struct node* mergeSorted(struct node *A , struct node *B){
    if(A == nullptr) return B ;
    if(B == nullptr) return A ;
    if(A->data < B->data){
        A->next = mergeSorted(A->next , B);
        return A ;
    }
    else{
        B->next = mergeSorted(A , B->next) ;
        return B ;
    }
}

int main(){
   
   
}