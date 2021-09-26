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

// This is for a normal Tree and not for BinarySearchTree
int min_Value(struct node *root){
    if(root == nullptr ) return INT_MAX ;
    if(root->left == nullptr && root->right == nullptr) return root->data;


    int mini = min(min_Value(root->left ), root->data);
    mini = min(min_Value(root->right) , mini);
    return mini ;
}
int max_Value(struct node *root){
    if(root == nullptr ) return INT_MIN ;
    if(root->left == nullptr && root->right == nullptr) return root->data;


    int maxi = max(max_Value(root->left ), root->data);
    maxi = max(max_Value(root->right) , maxi);
    return maxi ;
}




int main(){
    struct node *root = nullptr;
    root = createNewNode(1);
    root->left = createNewNode(2);
    root->right = createNewNode(3);
    root->left->left = createNewNode(4);
    root->left->right = createNewNode(5);
    root->right->left = createNewNode(-5);
    root->right->right = createNewNode(-1);
    root->left->left->left = createNewNode(8);
    root->left->left->left->left = createNewNode(9);
    cout << "'Minimum value is : "<<min_Value(root) << endl;
    cout << "Maximum value is :" << max_Value(root) << endl;
    return 0;
}
/*        1
       /   \
      2     3
     / \   / \
    4   5 -5   -1
   /          
  8  
 /
9 */