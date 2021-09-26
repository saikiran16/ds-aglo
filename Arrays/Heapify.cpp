#include<bits/stdc++.h>
using namespace std ;
struct node {
    int data ;
    struct node *left , *right;
};
struct node* createNewNode(int key){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = key ;
    newNode->left = newNode->right = nullptr ;
    return newNode ;
}
void heapify(struct node *root){
    
}

void preOrder(struct node *root){
    if(root == nullptr) return ;
    
    cout << root->data << " " ;
    preOrder(root->left);
    preOrder(root->right);
}
int main(){
    struct node* root = createNewNode(1);
    root->left = createNewNode(2);
    root->right = createNewNode(3);
    root->left->left = createNewNode(4);
    root->left->right = createNewNode(5);
    root->right->left = createNewNode(6);
    root->right->right = createNewNode(7);
    preOrder(root);
    return 0;
}