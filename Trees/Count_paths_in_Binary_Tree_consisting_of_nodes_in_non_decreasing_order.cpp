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
int countNoPathsWhoseNodeValuesAtMostX(struct node *root, int maxi, int sum){
    if(root == nullptr) return sum ;
    
    if(root->data >= maxi){
        sum++;
    }
    cout << "*** " <<root->data << " " << maxi << " " << sum << endl;
    maxi = max(root->data , maxi);
    sum = countNoPathsWhoseNodeValuesAtMostX(root->left , maxi , sum);
    sum = countNoPathsWhoseNodeValuesAtMostX(root->right , maxi , sum);

    return sum ;
}

int main(){
    struct node *root = nullptr;
    root = createNewNode(1);
    root->left = createNewNode(10);
    root->right = createNewNode(3);
    root->left->left = createNewNode(4);
    root->left->right = createNewNode(5);
    root->right->left = createNewNode(6);
    root->right->right = createNewNode(7);
    root->left->left->left = createNewNode(8);
    root->left->left->left->left = createNewNode(9);
    //inorder(root);
    cout << countNoPathsWhoseNodeValuesAtMostX(root , INT_MIN , -1) << endl;
    return 0;
}
/*        1
       /   \
      10    3
     / \   / \
    4   5 6   7
   /          
  8  
 /
9 */