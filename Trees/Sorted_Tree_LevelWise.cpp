/*Check if a binary tree is sorted level-wise or not
*/
/*
Solution : 
            An efficient solution is to do level order traversal and keep track of
the minimum and maximum values of current level. Use a variable prevMax to store the
maximum value of the previous level. Then compare the minimum value of current level
with the maximum value of the previous level, pevMax. If minimum value is greater than the
prevMax, then the given tree is sorted level-wise up to current level. For next level, prevMax
is the equal to maximum value of current level. So update the prevMax with maximum
value of current level. Repeat this until all levels of given tree are not traversed.


*/
#include<bits/stdc++.h>
using namespace std ;
struct node {
    struct node *left , *right ;
    int data ;
};
struct node* createNewNode(int key){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->left = nullptr ;
    newNode->right = nullptr ;
    newNode->data = key ;
    return newNode ;
}
int isSortedLevelWise(struct node* root){
    queue<struct node*> q ;
    q.push(root) ;
    int c = 1 ;
    int currMax = INT_MIN ;
    int prevMax = INT_MIN ;
    int previous = INT_MIN ;
    while(!q.empty()){
        struct node* curr = q.front();
        if(curr->data < previous ) return false ;
        previous = curr->data;
        q.pop();
        c--;
        if(curr->left != nullptr) q.push(curr->left);
        if(curr->right != nullptr) q.push(curr->right);
        if(c == 0){

            c = q.size();
        }
    }
    return true ;
}
int main(){
    struct node* root = createNewNode(10);
    root->left = createNewNode(2);
    root->right = createNewNode(3);
    root->left->left = createNewNode(4);
    root->left->right = createNewNode(5);
    root->right->left = createNewNode(6);
    root->right->right = createNewNode(7);
    if(isSortedLevelWise(root)) cout << "True ";
    else cout << "False ";
}