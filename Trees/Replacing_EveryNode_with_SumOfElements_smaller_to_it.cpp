/*
   Question :  Replace Every Node with CurrenNode value + (sum of all elements less than currentNode)
*/
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
void preOrder(struct node* root){
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
/*
    For a CurrentNode we should add sum of all Nodes in their Left SubTree
*/
int replace(struct node *root , int sum_of_nodes){
    if(root == nullptr) return sum_of_nodes;
    sum_of_nodes  = replace(root->left , sum_of_nodes) ;
    root->data = root->data + sum_of_nodes;
    sum_of_nodes = root->data;
    sum_of_nodes = replace(root->right, sum_of_nodes);
    return sum_of_nodes ;

}

int main(){
    struct node *root = nullptr;
    root = createNewNode(9);
    root->left = createNewNode(6);
    root->left->left = createNewNode(3);
    root->right = createNewNode(15);
    root->right->right = createNewNode(21);
    replace(root , 0);
    preOrder(root);
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