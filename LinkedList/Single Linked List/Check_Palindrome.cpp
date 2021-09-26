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

struct node *reverseLL(struct node *head){
    if(head == nullptr || head->next == nullptr) return head ;
    struct node *nextNode = head->next ;
    struct node *current_node = head ;
    current_node->next = nullptr ;
    while(nextNode){
        current_node = nextNode ;
        nextNode = nextNode->next ;
        current_node->next = head ;
        head = current_node ;
    }
    return head;
}
bool compareLL(struct node *head1 , struct node *head2){
    while(head1 && head2){
        if(head1->data != head2->data){
           // cout << head1->data << " " << head2->data << endl;
            return false;
        } ;
        head1 = head1->next ;
        head2 = head2->next ;
    }
    return true ;
}
bool isPalindrome_Using_Stack(struct node *head){

    stack<int> s ;
    struct node *ptr = head ;
    while(head){
        s.push(head->data);
        head = head->next ;
    }
    //comparing top pf stack with linked list 
    while(ptr){
        if(ptr->data == s.top()){
             ptr = ptr->next ;
             s.pop();
        }
        else return false;
    }
    return true ;

}
bool isPalindrome_Using_reversing(struct node *head){
    // we need to find the middle of the LL and reverse the second half
    // later compare those 2 half's

    // Finding Middle Node 
    struct node *slow = head ;    
    struct node *fast = head ;
    struct node *previous_slow = head ;
    struct node *first_half_ending , *second_half_starting ;

    while(fast && fast->next){
        previous_slow = slow ;
        slow = slow->next ;
        fast = fast->next->next ; 
    }
    
    if(fast != nullptr){
        first_half_ending = previous_slow ;
        second_half_starting = slow->next ;
    }
    else{
        first_half_ending = previous_slow ;
        second_half_starting = slow ;
    }
    first_half_ending->next = nullptr;

    // Its time to reverse second half 

    second_half_starting = reverseLL(second_half_starting);
     cout << "first half ending is " <<first_half_ending->data << endl;
    cout << "second half starting is " << second_half_starting->data << endl;
   // displayLinkedList(second_half_starting);
    return compareLL(head , second_half_starting) ;
 

}
bool isPalindrome_Using_Recursion(struct node **head , struct node *current_node){
    if(current_node == nullptr) return true ;

    if(isPalindrome_Using_Recursion(head , current_node->next )){
        cout << (*head)->data << " " << current_node->data <<endl ;
        if((*head)->data == current_node->data){
            (*head) = (*head)->next ;
            return true ;
        }
        else 
            return false ;
    }
    return false ;

}

bool isPalindrome(struct node *head){
// **Method 1 : Use a stack to get reversed version of linked start . 
//                Push all the eles into stack and start comparing from head of LL to Top of stack .

// **Method 2 : Conider LL into two halves . Reverse the second half . Compare both halves .
// **Method 3 : This uses recursion. We will pass the address of head to compare 1st node and last node ;
    // Method 1 :
       return isPalindrome_Using_Stack(head) ;// needs an extra space O(n)
    // Method 2 :
        return isPalindrome_Using_reversing(head);
    // Method 3 :
        return isPalindrome_Using_Recursion(&head ,head);



}

int main(){
    struct node *head = createNewNode(10);
    head->next = createNewNode(20);
    head->next->next = createNewNode(30);
    head->next->next->next = createNewNode(30);
    head->next->next->next->next = createNewNode(20);
    head->next->next->next->next->next = createNewNode(10);
    displayLinkedList(head);
    cout << isPalindrome(head) << endl ;

}