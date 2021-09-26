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
int validateBST(struct node* root , int min_value , int max_value){
    if(root == nullptr) return 1;
    if(root->data > min_value && root->data <= max_value){
        return validateBST(root->left , min_value , root->data) && validateBST(root->right , root->data , max_value);
    }
    return 0;
}


// Watch AlgoExpert Video BST Validation
int isBST(struct node *root){
   return validateBST(root , INT_MIN , INT_MAX);
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
    cout << isBST(root);
    return 0;
}
/*       10
       /   \
      5     15
     / \   / \
    2   6 13  22
   /          
  1 
 */