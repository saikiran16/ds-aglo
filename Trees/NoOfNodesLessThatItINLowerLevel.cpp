using namespace std ;
#include<bits/stdc++.h>
struct node {
    int data ;
    struct node* left = nullptr ;
    struct node* right = nullptr;
};
struct node* createNewNode(int key){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = key ;
    newNode->right = newNode->left = nullptr;
    return newNode ;
}
void preOrder(struct node* root){
    if(root == nullptr) return ;
    cout << root->data << " " ;
    preOrder(root->left);
    preOrder(root->right);
}
vector<int> calulateMin_In_Of_EachLevel(struct node* root ,vector<int>& minElements_In_EachLevel){
    queue<struct node*> q ;
    q.push(root);
    int c = 1 , mini=INT_MAX;
    while(!q.empty()){
        struct node* curr = q.front();
        q.pop();
        if(curr->left != nullptr) q.push(curr->left);
        if(curr->right != nullptr)q.push(curr->right);
        mini = min(mini , curr->data);
        c--;
        if(c == 0){
            c = q.size() ;
            minElements_In_EachLevel.push_back(mini);
            mini=INT_MAX;
            
        }
    }
    return minElements_In_EachLevel;
    

}
void findNodes(struct node* root , vector<int> minElements_In_EachLevel , 
                                                                vector<int>& levelResults , int currentLevel){
    if(root == nullptr) return ;
    findNodes(root->left , minElements_In_EachLevel , levelResults , currentLevel+1);
    findNodes(root->right , minElements_In_EachLevel , levelResults , currentLevel+1);

    for(int i = 0 ;i < currentLevel ; i++ ){
        if(root->data <= minElements_In_EachLevel[i])
        levelResults[i]++;
    }
}
void PrintNode_Count_lessInAllLevels(struct node *root){
    vector<int> minElements_In_EachLevel ;
    minElements_In_EachLevel = calulateMin_In_Of_EachLevel(root ,minElements_In_EachLevel);
    //for(int i = 0 ; i < minElements_In_EachLevel.size() ; i++)cout << minElements_In_EachLevel[i] <<" ";
    vector<int> levelResults(minElements_In_EachLevel.size() , 0);
    findNodes(root , minElements_In_EachLevel,levelResults , 0);
    for(int i = 0 ; i < levelResults.size() ; i++){
        cout << levelResults[i] <<  " ";
    }

}
int main()
{
    struct node* root = createNewNode(4);
 
    root->left = createNewNode(3);
    root->right = createNewNode(5);
 
    root->right->left = createNewNode(3);
    root->right->right = createNewNode(1);

    root->left->left = createNewNode(10);
    root->left->right = createNewNode(2);
    PrintNode_Count_lessInAllLevels(root);
    //preOrder(root);
    return 0;
}