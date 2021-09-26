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

// He
void topView(struct node* root){
    if(root == nullptr)
        return;
    queue<pair<struct node *, int>> q;
    multimap<int, vector<int>> results;
    q.push({root, 0});
    pair<struct node* ,int> curr_node ;
    while(!q.empty()){
        curr_node = q.front();
        q.pop();
        if(curr_node.first->left != nullptr)q.push({curr_node.first->left , curr_node.second+1});
        if(curr_node.first->right != nullptr)q.push({curr_node.first->right,  curr_node.second-1});
        auto index = results.find(curr_node.second);
        int distance = curr_node.second;
        if(index != results.end()){
        }
        else{
            vector<int> l;
            l.push_back(curr_node.first->data);
            results.insert({distance, l});
        }

    }
    cout << "Top view is : ";
    for (auto i = results.begin(); i != results.end(); i++){
        cout << (i->second)[0] << " ";
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
    topView(root);
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