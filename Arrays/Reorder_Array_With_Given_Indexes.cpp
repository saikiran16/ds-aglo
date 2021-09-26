
/*  -------- Reorder an array according to given indexes-------
    Given two integer arrays of same size, “arr[]” and “index[]”, 
    reorder elements in “arr[]” according to given index array. It is not allowed to given array arr’s length.
    Time : O(n) ; Space : O(1)
    Sol : Swap Elements along with indexs.

*/
using namespace std ;
#define takeArray(arr ,n) for(int i = 0 ; i < n ; i++) cin >> arr[i];
#define printArray(arr , n) for(int i = 0 ; i < n ; i++) cout << arr[i] << " " ;cout<<endl;
#include<bits/stdc++.h>
void reOrderArrayUsingIndices(int arr[] ,int index[]  , int n){
    for(int i = 0 ; i < n ; i++){
        if(index[i] != i){

            // Swapping Elements 
            int tempElement = arr[index[i]];
            arr[index[i]] = arr[i];
            arr[i] = tempElement;

            // Swapping indexes
            int tempIndex = index[index[i]];
            index[index[i]] = index[i];
            index[i] = tempIndex ;
        }

    }
}
int main(){
    int  n  = 5;
    int arr[] = {50, 40, 70, 60, 90};
    int index[] = {3,  0,  4,  1,  2};
    reOrderArrayUsingIndices(arr , index ,n);
    printArray(arr , n);
    

    return 0;
}