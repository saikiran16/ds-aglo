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

vector<float> averageOfEachLevel(struct node *root){
    queue<struct node *> q ;
    vector<float> avgOfEachlevel ;
    q.push(root);
    int avg = 0 , count = 1 ;
    int temp = count;
    while(!q.empty()){
        struct node* currentNode = q.front();
        avg = avg + currentNode->data;
        q.pop();
        if(currentNode->left) q.push(currentNode->left);
        if(currentNode->right)q.push(currentNode->right);
        count -- ;
        if(count == 0){
            avgOfEachlevel.push_back((float)avg/temp);
            count = q.size();
            temp = count;
            avg = 0;
        }
        
    }
    return avgOfEachlevel;
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
    vector<float> results  = averageOfEachLevel(root);
    for(auto it = results.begin() ; it != results.end() ; it++){
        cout << *it << " ";
    }
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