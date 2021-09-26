using namespace std;
#include<bits/stdc++.h>
struct node {
    int data;
    struct node* left = nullptr ;
    struct node* right  = nullptr;
};
struct node* createNewNode(int value){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    //if(value == 2) cout << "Address of 2  : " << newNode << endl;
    newNode->data = value;
    newNode->right = newNode->left =NULL;
    return newNode;
}
void constructCLL(struct node *root , queue<struct node *>&q){
    if(root == nullptr) return ;
    constructCLL(root->left , q);
    q.push(root);
    cout << "Inserted " << root->data << endl;
    constructCLL(root->right  , q);
}
void displayCircularLinkedList(struct node *head){
    if(head == nullptr) { cout << "empty Linked List " << endl ; return ;}
    struct node *ptr = head ; 
    do{
        cout << ptr->data  ;
        ptr = ptr->right ;
        if(ptr!=head) cout << "-->";
    }while(ptr!=head);
    cout <<endl;
    // Since it is double ll we can traverse backwards ;
    ptr = head ; 
    do{
        cout << ptr->data  ;
        ptr = ptr->left ;
        if(ptr!=head) cout << "-->";
    }while(ptr!=head);
}
void constructCLL_Util(struct node *root){
    queue<struct node *> q ;
    constructCLL(root , q);
    struct node *prev = nullptr , *current_node = nullptr , *first_node = nullptr ;
    int i = 0 ,size = q.size();
   // cout << q.front() << endl;
   first_node = q.front() ;
   q.pop() ;
   first_node->right = first_node ;
   first_node->left = nullptr ;
   prev = first_node;
   while(!q.empty()){
       current_node = q.front();
       //cout << current_node->data << " " ;
       q.pop();
       prev->right = current_node ;
       current_node->left = prev ;
       current_node->right = first_node ;
       prev = current_node ;
   }
   cout << endl;
   first_node->left = current_node;
   displayCircularLinkedList(first_node);
}

int main(){
    struct node *root = nullptr;
    root = createNewNode(1);
    root->left = createNewNode(2);
    root->right = createNewNode(3);
    root->left->left = createNewNode(4);
    root->left->right = createNewNode(5);
    root->right->left = createNewNode(6);
    root->right->right = createNewNode(7);
    root->left->left->left = createNewNode(8);
    root->left->left->left->left = createNewNode(9);
    constructCLL_Util(root);
    return 0;
}
/*        1
       /   \
      2     3
     / \   / \
    4   5 6   7
   /          
  8  
 /
9 */