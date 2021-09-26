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
void PrintLeftNodesExceptLeafNodes(struct node *root){
    if(root == nullptr )
        return;
    if(root->left == nullptr && root->right == nullptr)
        return;
    printf("%d ", root->data);
    PrintLeftNodesExceptLeafNodes(root->left);
}
void PrintLeafNodes(struct node *root){
    if(root == nullptr)
        return;
    if(root->left == nullptr && root->right == nullptr){
        cout << root->data << " ";
        return;
    }
    PrintLeafNodes(root->left);
    PrintLeafNodes(root->right);
    return;
}
void PrintRightNodesExceptLeafNode(struct node *root){
    if(root == nullptr)
        return;
    if(root->left == nullptr && root->right == nullptr){
        return;
    }
    PrintRightNodesExceptLeafNode(root->right);
    cout << root->data << " ";
}
void boundaryTraversalOfBT(struct node *root){
    PrintLeftNodesExceptLeafNodes(root);
    PrintLeafNodes(root);
    PrintRightNodesExceptLeafNode(root);
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
    boundaryTraversalOfBT(root);
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