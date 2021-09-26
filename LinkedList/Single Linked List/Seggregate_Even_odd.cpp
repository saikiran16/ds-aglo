using namespace std ;
#include<bits/stdc++.h>
struct node{
    int data ;
    struct node *next ;
};
struct node *createNewNode(int key){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = key ;
    newNode->next = nullptr ;
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
void seggregateEvenOdd(struct node *head){
     struct struct node *end = head ;
    int length = 0,even=0 ;
    while(end->next ){
        if(end->data%2==0)even++;
        end = end->next ;
        length++ ;
    }
    if(end->data%2==0)even++;
    length++;
    if(even == 0)return head;
    struct struct node *ptr = head ;
    struct node *prev = nullptr;
    for(int i = 0 ; i < length ; i++){
        if(ptr && ptr->data%2 == 1 && ptr->next ){
            if(ptr == head)
            {
               // cout << "first node" <<endl;
                head = ptr->next ;
                ptr->next = nullptr ;
                end->next = ptr ;
                end = ptr ;
                ptr = head ;
            }
            else
            {
              //  cout << "else" << endl;
                prev->next = ptr->next ;
                ptr->next = nullptr ;
                end->next = ptr ;
                end = ptr ;
                ptr = prev->next ;

            }
            continue;

        }
        else{
            prev = ptr ; 
        }
       // cout << "end" << endl;
        ptr = ptr->next;
    }
    displayLinkedList(head);
    
}

// 17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL
int main(){
    struct node *head = createNewNode(17);
    head->next = createNewNode(15);
    head->next->next = createNewNode(8);
    head->next->next->next = createNewNode(9);
    head->next->next->next->next = createNewNode(2);
    head->next->next->next->next->next = createNewNode(4);
    head->next->next->next->next->next->next = createNewNode(6);
    displayLinkedList(head);
    seggregateEvenOdd(head);
    return 0;
}