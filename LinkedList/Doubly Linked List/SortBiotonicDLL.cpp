/*
  case 1 : If the LL is Increasing and then Decreasing .
  case 2 : If the LL is strictly Increasing .
  case 3 : If the LL is strictly Decreasing.
*/
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
struct node *reverseDLL(struct node *head){
    if(head == nullptr || head->next == nullptr) return head ;     // 1 2 3 4 5 6
    struct node *current_node = head ;
    struct node *nextNode = nullptr;
    head = nullptr ;
    while(current_node){
        nextNode = current_node->next ;
        current_node->next = head ;
        head = current_node ;
        current_node = nextNode ;

    }
    displayLinkedList(head);
    return head; 
}
struct node* mergeTwoSortedDLL(struct node *A , struct node *B){
    if(A == nullptr) return B ;
    if(B == nullptr) return A ;
    if(A->data < B->data){
        A->next = mergeTwoSortedDLL(A->next , B);
        A->next->prev = A ;
        A->prev = nullptr ;
        return A ;
    }
    else{
        B->next = mergeTwoSortedDLL(A , B->next) ;
        B->next->prev = B ;
        B->prev = nullptr ;
        return B ;
    }
}


void sortTheBiotonicDLL(struct node *head){
    // Find the point where it starts decreasing 
    struct node *ptr = head->next ;
    struct node *previousNode = nullptr ;
    while(ptr && ptr->data >= ptr->prev->data){
        ptr = ptr->next ;
    }
    // Split the DLL 
    struct node *increasingDLLHead = head ;
    struct node *decreasingDLLHead = ptr ;
    ptr->prev->next = nullptr ;
    ptr->prev = nullptr ;
   // displayLinkedList(increasingDLLHead);
   // displayLinkedList(decreasingDLLHead);
  //  cout << "Reversed Version of decreasingDLLHead : "  ; 
    decreasingDLLHead = reverseDLL(decreasingDLLHead);
    
    // Merge two Sorted DLL .
    head = mergeTwoSortedDLL(increasingDLLHead , decreasingDLLHead);
    displayLinkedList(head);

}
int main(){
    struct node *head = nullptr ;
    head = insertAtEnd(head ,2 ) ;   
    head = insertAtEnd(head ,3 );
    head = insertAtEnd(head ,7 );
    head = insertAtEnd(head ,6 );
    head = insertAtEnd(head ,5 );
    head = insertAtEnd(head ,4);
    head = insertAtEnd(head ,4 );
    head = insertAtEnd(head , 4 );
    displayLinkedList(head);
    sortTheBiotonicDLL(head);
    
    
    return 0;
}

/*
1-2-3-4-5


*/