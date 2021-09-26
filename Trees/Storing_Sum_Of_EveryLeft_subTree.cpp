/* Change a Binary Tree so that
every node stores sum of all
nodes in left subtree */
#include<bits/stdc++.h>
using namespace std ;
struct node {
    int data ;
    struct node* left ;
    struct node* right ;
};
struct node* createNewNode(int key){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->left = nullptr ;
    newNode->right  = nullptr ;
    newNode->data = key;
    return newNode ;
}
int sumOfLeftSubTree(struct node *root){
    if(root == nullptr) return 0;
    int lsum  = sumOfLeftSubTree(root->left);
    int rsum = sumOfLeftSubTree(root->right);
    root->data = root->data + lsum ;
    return root->data + rsum ;

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
    root->right->right = createNewNode(6);
    sumOfLeftSubTree(root);
    preOrder(root);

}