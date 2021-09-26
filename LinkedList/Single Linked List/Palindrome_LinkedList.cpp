#include<stdio.h>
#define p 1000000007;
using namespace std;
#include<stack>
#define ll long long int
#include<iostream>
#include<algorithm>
bool f(int a ,int b)
{
    return a > b;
}
struct node{
    int data;
    struct node *next;
};
struct node* createNewNode(int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
void display(struct node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
        if(head)
            cout << "-> ";
    }
    cout << endl;
}
bool checkIsPalindromeThroughStack(struct node* head){
    stack<int> st;
    struct node *ptr = head;
    while(ptr){
        st.push(ptr->data);
        ptr = ptr->next;
    }
    while(!st.empty()){
        int c = st.top();
        cout << c << " " <<head->data<<endl;
        if(head->data !=c ){
            return false;
        }
        st.pop();
        head= head->next;
    }
    return true;
}
bool checkIsPalindrome(struct node* head){ // Space Complexity O(1)
     // Traverse till middle node and reverse second half of linked list and compare first half and second half
    if(head == NULL || head->next == NULL)
        return true;
    struct node *slow = head, *fast = head, *currentNode = NULL, *nextNode = NULL;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "middle node " << slow->data << endl;

                                                /*if(fast)
                                                    cout << "odd Nodes" << endl;
                                                else
                                                    cout << "even Nodes" << endl;
                                                cout << "middle node is " << slow->data << endl;*/

   
    struct node *secondHead = slow->next;
    slow->next = NULL;
    currentNode = secondHead->next;
    secondHead->next = NULL;
    while(currentNode){
        display(secondHead);
        nextNode = currentNode->next;
        currentNode->next = secondHead;
        secondHead = currentNode;
        currentNode = nextNode;
    }
    display(head);
    display(secondHead);
    while(secondHead){
        if(head->data != secondHead->data)
            return false;
       head = head->next;
       secondHead = secondHead->next;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    struct node *head = createNewNode(10);
    head->next = createNewNode(10);
    head->next->next = createNewNode(30);
    head->next->next->next = createNewNode(40);
    head->next->next->next->next = createNewNode(30);
    head->next->next->next->next->next = createNewNode(20);
    head->next->next->next->next->next->next = createNewNode(10);
    display(head);
    //cout << checkIsPalindromeThroughStack(head) << endl;
    cout <<  checkIsPalindrome(head);

    return 0 ;
}