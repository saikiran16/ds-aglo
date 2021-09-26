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
void invertBinaryTree(struct node *root){
    if(root == nullptr)return ;
    struct node *temp = root->left ;
    root->left = root->right ;
    root->right = temp ;
    invertBinaryTree(root->left) ;
    invertBinaryTree(root->right);
}
void preOrder(struct node * root){
    if(root == nullptr) return ; 
    cout << root->data << " ";
    preOrder(root->left) ;
    preOrder(root->right);
}
int main(){
    struct node *root = nullptr;
    root = createNewNode(10);
    root->left = createNewNode(5);
    root->right = createNewNode(15);
    root->left->left = createNewNode(2);
    root->left->right = createNewNode(6);
    root->right->left = createNewNode(13);
    root->right->right = createNewNode(22);
    root->left->left->left = createNewNode(1);
    //root->left->left->left->left = createNewNode(9);
    preOrder(root);
    cout <<endl;
    invertBinaryTree(root);
    preOrder(root);

    return 0;
}
/*       10
       /   \
      5     15
     / \   / \
    2   6 13  22
   /          
  1 
output :
         10
       /   \
      15    5
     / \   / \
    22 13 6   2 
               \
                1
 */