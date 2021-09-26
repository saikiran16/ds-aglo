using namespace std;
#include<bits/stdc++.h>
int maxDepth(struct node * root , int *max_ptr);
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
void inorder(struct node* root){
    if(root == NULL)
        return;
    printf("%d ", root->data);
    inorder(root->left);
    inorder(root->right);
}

// Height of Tree
int diameter(struct node *root){
    int max = 0 ;
    maxDepth(root, &max) ;
    return max; 
}
int maxDepth(struct node* root, int *max_ptr){
    if(root == nullptr) return 0;
    int left = maxDepth(root->left , max_ptr);
    int right = maxDepth(root->right , max_ptr);
    *max_ptr = (left + right) > *max_ptr ? (left + right) : *max_ptr;
    return left > right ? left +1 : right + 1 ;
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
    //inorder(root);
    cout << diameter(root) << endl;
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