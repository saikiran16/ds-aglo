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
    printf("%d ", root->data);
    inorder(root->left);
    inorder(root->right);
}

// 
void left_RightView(struct node* root){
    if(root == nullptr)
        return;
    queue<struct node *> q;
    q.push(root);
    int count = 1;
    struct node *curr_node = nullptr;
    list<int> left_view_results, right_view_results;
    while(!q.empty()){
        curr_node = q.front();
        q.pop();
        if(curr_node->left != nullptr)
            q.push(curr_node->left);
        if(curr_node->right != nullptr)
            q.push(curr_node->right);
        count--;
        if(count == 0){
            right_view_results.push_back(curr_node->data);
            count = q.size();
            if(!q.empty()){
            left_view_results.push_back(q.front()->data);
        }
        }

    }
    for (auto i = left_view_results.begin(); i != left_view_results.end(); i++){
        cout << *i << " ";
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
    //inorder(root);
    left_RightView(root);
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