using namepsace std ;
#include<bits/stdc++.h>
struct node {
    int data ;
    struct node *next ;
};
int intersectPoint(struct node* head1, struct node* head2)
{
    // Your Code Here
    struct node *ptr1 = head1 ;
    struct node *ptr2 = head2 ;
    int lenA = 0 , lenB = 0 ;
    while(ptr1){
        ptr1 = ptr1->next ;
        lenA++;
    }
    while(ptr2){
        ptr2 = ptr2->next ;
        lenB++;
    }
    ptr1 = head1 ; ptr2 = head2 ;
    int diff = abs(lenA - lenB);
    if(lenA > lenB){
        for(int i = 0 ; i < diff ; i++){
            ptr1 = ptr1->next ;
        }
    }
    else{
        for(int i = 0 ; i < diff ; i++){
            ptr2 = ptr2->next ;
        }
    }
    while(ptr1 && ptr2){
        if(ptr1 == ptr2) return ptr1->data ;
        ptr1 = ptr1->next ;
        ptr2 = ptr2->next ;
    }
    return -1 ;
}

int main(){
    
}