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
struct node* detectLoop(struct node *head){
    struct node *slow = head ;
    struct node *fast = head ;
    while(fast && fast->next ){
        slow = slow->next ;
        fast = fast->next->next ;
        if(slow == fast)
            return slow  ;
    }
    return nullptr ;
    
}
//Function to find the length of a loop in the linked list.
//Approach : First we will find the some point in the loop using two pointers(slow , fast) . 
//This commom point is the point where slow == fast .
// from this common point we will traverse the loop gain until common point == current node . until then 
// we will count the nodes and return them. 

int countNodesinLoop(struct node *head)
{
    struct node* loopAt = detectLoop(head);
    if(loopAt){
        struct node *ptr = loopAt->next;
        int c = 1 ;
        while(ptr != loopAt){
            c++ ;
            ptr = ptr->next ;
            
        }
        return c ;
        
        
    }
    else 
        return 0 ;
    
}
int main(){
    struct node *head = createNewNode(10);
    head->next = createNewNode(20);
    head->next->next = createNewNode(30);
    head->next->next->next = createNewNode(40);
    head->next->next->next->next = createNewNode(50);
    head->next->next->next->next->next = createNewNode(60);
    displayLinkedList(head);
    cout << lengthOfLinkedList(head) << endl ;

}