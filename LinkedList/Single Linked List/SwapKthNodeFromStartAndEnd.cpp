// Swap Kth Nodes from start and end  in a Single Linked List
// Do In place swappings . That is Swaps nodes but do not swap data .
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
int length(struct node *head){
    int n = 0  ;
    while(head){
        n++;
        head = head->next ;
    }
    return n ;
}
void swapkthnode(struct node* head, int k)
{
    // Your Code here
    int n = length(head);
    if(k > n) {displayLinkedList(head) ; return ;};
   // cout << "Length = " << n << endl;
    int node_from_starting =  k ;
    int node_from_ending = n - k + 1  ;
    cout << node_from_starting << " -- " << node_from_ending << endl ;
    if(node_from_starting == node_from_ending || n == 1 ) {displayLinkedList(head) ; return ;} ;
    struct node *starting_prev =nullptr ,*starting = nullptr , *ending_prev = nullptr, *ending , *prev=nullptr, *ptr = head;
    for(int i = 1 ; i <  n ; i++){
         prev = ptr ;
         ptr = ptr->next ;
        if(i+1 == node_from_starting)
        {
            starting = ptr ;
            starting_prev = prev ;
        }
        if(i+1 == node_from_ending)
        {
            ending = ptr ;
            ending_prev = prev ;
        }
    }
    if(node_from_starting == 1 || node_from_ending == 1){ // we need to swap starting and ending Nodes
        cout << prev->data << " " << ptr->data <<endl;
        
        if(head->next == ptr){
          prev->next = nullptr ;
          ptr->next = prev ;
          displayLinkedList(ptr);
          return ;   
        }
        prev->next = nullptr ;
       
        ptr->next = head->next ;
        prev->next = head;
        head->next = nullptr ;
        head = ptr ;
    }
    else{
       /* cout << starting->data << " " << starting_prev->data <<endl;
        cout << ending->data << " " << ending_prev->data << endl;*/
       
       if (starting_prev)
        starting_prev->next = ending;
 
        // Same thing applies to y_prev
        if (ending_prev)
        ending_prev->next = starting;
    
        // Swap next pointers of x and y.
        // These statements also break self
        // loop if x->next is y or y->next is x
        struct node* temp = starting->next;
        starting->next = ending->next;
        ending->next = temp;

    }
    
    displayLinkedList(head);
}
int main(){
    struct node *head = createNewNode(10);
    head->next = createNewNode(20);
    head->next->next = createNewNode(30);
    head->next->next->next = createNewNode(40);
    head->next->next->next->next = createNewNode(50);
    head->next->next->next->next->next = createNewNode(60);
    displayLinkedList(head);
    swapkthnode(head , 3);
    

}