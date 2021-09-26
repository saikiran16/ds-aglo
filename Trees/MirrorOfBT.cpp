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
void inorder(struct node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void preorder(struct node* root){
    if(root == NULL)
        return;
     printf("%d ", root->data);
    inorder(root->left);
    inorder(root->right);
}
void postorder(struct node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    inorder(root->right);
    printf("%d ", root->data);
}


void mirrorOfBTUsingPostOrder(struct node *root){
    if(root == nullptr)
        return;
    else{
        mirrorOfBTUsingPostOrder(root->left);
        mirrorOfBTUsingPostOrder(root->right);
        struct node *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}
void mirrorOfBTUsingPreOrder(struct node* root){
    if(root == nullptr)
        return;
    else{
        struct node *temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirrorOfBTUsingPreOrder(root->left);
        mirrorOfBTUsingPreOrder(root->right);
    }
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
    inorder(root);
    cout << endl;
    //mirrorOfBTUsingPostOrder(root);
    mirrorOfBTUsingPreOrder(root);
    inorder(root);
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