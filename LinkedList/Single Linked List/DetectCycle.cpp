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

bool detectCycle(struct node *head){
// Method 1 : To store the address in a set . I an address we are going to insert is already present then there is a cycle .
// Method 2 : We Will maintain two pointers (slow and fast) where one will one step and other will move two at a time . When both these ptr are at same node it means there is a cycle . 
// Method 3 : This Method needs slight modification in Node structure  .We will add an extra element i.e bool visited which will tell us visited or not . If we visit that node we will make them as true . If we visit a node whose visited value is already true then there is a cycle at that node ;


// Method 1 :
    unordered_set s ;               // Here I am using unorderd Set because it will find the elements in O(1).
                                    // whereAs set(ordered) will take O(log n ) to find as the elements are in sorted manner .
    strut node *ptr = head ;
    while(head){
        if(s.find(head) == s.end())
            s.insert(head)
        else 
            return false ;
    }
    return true ;


// Method 2 :
    ptr = head ;
    struct node *slow = head ;
    struct node *fast = head ;
    while(fast && fast->next ){
        slow = slow->next ;
        fast = fast->next->next ;
        if(slow == fast)
            return true ;
    }
    return false ;
}


int main(){
    struct node *head = createNewNode(10);
    head->next = createNewNode(20);
    head->next->next = createNewNode(30);
    head->next->next->next = createNewNode(40);
    head->next->next->next->next = createNewNode(50);
    head->next->next->next->next->next = createNewNode(60);
    displayLinkedList(head);
    cout << detectCycle(head) << endl ;

}