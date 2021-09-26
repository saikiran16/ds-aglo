#include<bits/stdc++.h>
using namespace std;
void remove_node(struct node *, struct node *);
struct node {
    int data;
    struct node *right;
    struct node *left;
};
struct node* createNewNode(int value){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    //if(value == 2) cout << "Address of 2  : " << newNode << endl;
    newNode->data = value;
    newNode->right = newNode->left =NULL;
    return newNode;
}
struct node* insertInToBT(struct node* root ,int value){
    struct node *newNode = createNewNode(value);
    queue<struct node* > q;
    if(root == NULL){
        return newNode;
    }
    q.push(root);
    while(!q.empty()){
        struct node* top = q.front();
        q.pop();
        if(top->left == NULL){
            top->left = newNode;
            return root;
        }
        else{
            q.push(top->left);
        }
        if(top->right == NULL){
            top->right = newNode;
            return root;
        }
        else
            q.push(top->right);
        
    }

    return root;
}
struct node* deleteNodeFromBT(struct node* root , int key){
    if(root == nullptr){
        return nullptr;
    }
    if(root->left == nullptr && root->right){
        root = nullptr;
        //return root;
    }
    queue<struct node *> q;
    struct node *current_node = nullptr;
    struct node *key_node = nullptr;
    q.push(root);
    while(!q.empty()){
        current_node = q.front();
        q.pop();
        if(current_node->left != nullptr)
            q.push(current_node->left);
        if(current_node->right != nullptr)
            q.push(current_node->right);
        if(current_node->data == key)
            key_node = current_node;

        
    }
    if(key_node){
        key_node->data = current_node->data;
        remove_node(root , current_node);
    }
    return root;
    // cout << "Address of key is : " << key_node << endl;
    //  cout << "Address of Parent is  : " << parent_node << endl;

}
void remove_node(struct node *root , struct node *n){
    if(root == nullptr) return ;
    if(root == n ) return ;
    if(root->left ==n ){
        root->left = nullptr;
        delete n;
        return;
    } 
    if(root -> right == n){
        root->right = nullptr;
        delete n;
        return;
    }
    remove_node(root->left ,n);
    remove_node(root->right, n);
}
void inorder(struct node* root){
    if(root == NULL)
        return;
    printf("%d ", root->data);
    inorder(root->left);
    inorder(root->right);
}
int main(){
    struct node *root = NULL;
    root = insertInToBT(root ,1);
    root = insertInToBT(root , 2);
    root = insertInToBT(root, 3);
    root = insertInToBT(root, 4);
    root = insertInToBT(root, 5);
    inorder(root);cout << endl;
    deleteNodeFromBT(root , 1);
    inorder(root);
    return 0;
}