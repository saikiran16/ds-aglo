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
// Return time taken to burn the entire tree when fire starts from Target Node .
int burningTime(struct node* root , int TargetNode){
    int max_depth_from_TargetNode =  0 ;
    bool found = false ;
    return max_depth(root , TargetNode , &max_depth_from_TargetNode , &found);
}
int max_depth(struct node *root  , int TargetNode , int *max_depth_from_TargetNode ,bool *found_ptr){
    if(root == nullptr) return 0;
    if(root->data = TargetNode) return true ;
    bool found_on_left_subTree = false ;
    bool found_on_right_subTree = false ;
    int left = max_depth(root->left , TargetNode , *max_depth_from_TargetNode , found_ptr);
    


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