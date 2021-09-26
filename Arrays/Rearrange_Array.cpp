/*
Given an array of elements of length N, ranging from 0 to N – 1. 
All elements may not be present in the array. If the element is not present then there will be -1 present in the
 array. Rearrange the array such that A[i] = i and if i is not present, display -1 at that place.
 Input : arr = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1}
Output : [-1, 1, 2, 3, 4, -1, 6, -1, -1, 9]
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).
*/

using namespace std ;
#define takeArray for(int i = 0 ; i < n ; i++) cin >> arr[i];
#define printArray for(int i = 0 ; i < n ; i++) cout << arr[i] << " " ;cout<<endl;
#include<bits/stdc++.h>

//Using Extra Space .
int Rearrange(int *arr,int n){
    // Complete the function
     int *b = (int * )malloc(sizeof(int)*n)  ;
     for(int i = 0 ;  i< n ; i++)b[i] = -1 ;
     for(int i = 0 ; i < n ; i++){
       if(arr[i] != -1 && arr[i] < n){
           b[arr[i]] = arr[i];
       }
        
     }
    return b;
}
// Optimized and O(1) space 
int Rearrange(int *arr , int n){
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == i || arr[i] == -1 ) continue ;
        // Swap the elements to their place  i.e if we found 6 we must swap to arr[6] since we need to map arr[i] = i;

        else{
            int temp = arr[i] ;
            arr[i] = arr[temp] ;
            arr[temp] = temp ;
            i--;
        }
    }
}
int main(){
    int arr[] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1} ;
    int n = 10 ;
    Rearrange(arr  , n)
    printArray
    return 0;
}