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
void verticalOrderTraversal(struct node* root){
    if(root == nullptr)
        return;
    multimap<int, list<int>> results;
    queue<pair<struct node*, int> >q;
    pair<struct node *, int> current_node;
    q.push({root , 0});
    while(!q.empty()){
        current_node = q.front();
        q.pop();
        if(current_node.first->left != nullptr){
            q.push({current_node.first->left, current_node.second + 1});
        }
        if(current_node.first->right != nullptr){
            q.push({current_node.first->right, current_node.second - 1});
        }
        int distance = current_node.second; 
        auto index =  results.find(distance);
        if(index != results.end()){
            (index->second).push_back(current_node.first->data);
        }
        else{
            list<int> l;
            l.push_back(current_node.first->data);
            results.insert({distance, l});
        }
    }
     for (auto i = results.begin(); i != results.end();i++){
         cout << "key : " << i->first << " ";
         cout << "Value : ";
         for (auto j = i->second.begin(); j != i->second.end(); j++){
             cout << *j << " ";
         }
         cout << endl;
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
    verticalOrderTraversal(root) ;
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