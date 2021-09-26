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
int findHeightOfCousin(struct node* currentNode , int *parent , int value , int height){
    if(currentNode == nullptr) return 0;
    if(currentNode->data == value) return height;
    *parent = currentNode->data ;
    int left = findHeightOfCousin(currentNode->left , parent , value , height+1);
    if(left != 0){  // IF LEFT != 0 THAT MEANS WE HAVE FOUND VALUE IN SOME NODE .
        return left;
    }
    int right = findHeightOfCousin(currentNode->right , parent , value , height+1);
    return right;

}
bool FindCousinORNot(struct node* root , int x , int y){

    int xParent = -1 ;
    int xHeight =  findHeightOfCousin(root , &xParent , x , 0);
    //cout << xParent << " " << xHeight <<endl;
    int yParent = -1 ;
    int yHeight =  findHeightOfCousin(root , &yParent , y , 0);
  //  cout << yParent << " " << yHeight <<endl;
    if(xParent != yParent && xHeight == yParent)
        return true;
    return false;

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
    cout << FindCousinORNot(root , 4,6);
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