/* --------Minimum swaps and K together------
    Given an array of n positive integers and a number k. Find the minimum number of swaps required to 
    bring all the numbers less than or equal to k together.
    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(1).
    Approach : Using sliding Window Technique We Take a window size equal to number of elements less than k
               and we will keep take the count of elements that are less than k in every window .
               Then we will take minimum of it .
*/
using namespace std ;
#define takeArray for(int i = 0 ; i < n ; i++) cin >> arr[i];
#define printArray for(int i = 0 ; i < n ; i++) cout << arr[i] << " " ;cout<<endl;
#include<bits/stdc++.h>
int minSwap(int arr[], int n, int k) {
    // Complete the function
    // Count is to keep track of no .of eles less than k in every window
    // min_swaps is to keep track of minimum of count 
    // Window size is for maintain window Size 

    int count = 0  ,min_swaps = 0  , flag = 0  , WindowSize = 0;
    // Setting Window size eqaul to No. of elements in array that are less than k .
    for(int i = 0 ; i < n ; i++) if(arr[i] <= k ) WindowSize++;
     if(WindowSize == 0 )   return 0 ;

     // Iterate First Window
    for(int i = 0 ; i < WindowSize ; i++){
        if(arr[i] <= k) 
        { 
            flag = 1 ; 
            count++;
        }
        
    }
    min_swaps = WindowSize - count ;
    for(int i = 1 ; i <= (n-WindowSize) ; i++){
        if(arr[i-1] <= k ) 
        {  
             flag = 1 ;
            count--;
        } 
        if(arr[i+WindowSize-1] <= k ) 
        {  
            flag = 1 ; count++;
        }
        
        min_swaps = min( WindowSize-count  , min_swaps);
    }
    if(flag == 0) return 0;
    return min_swaps ;
    
}
int main(){
    int n ; cin >> n ;
    int arr[n] ;
    takeArray 
    int k ;
    cin >> k ;
    cout << minSwap(arr , n , k) ;
    return 0;
}