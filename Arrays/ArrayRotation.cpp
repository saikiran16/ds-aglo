// Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements. 
// CPP
using namespace std;
#define takeInput for(int i = 0 ; i < n ; i++) cin >> arr[i] ;
#define printArray for(int i = 0 ; i < n ; i++) cout << arr[i] << " " ;
#include<bits/stdc++.h>

// Function to rotate Array
void rotate(int arr[] , int d , int n) {
    // Brute force 
    // Time Complexity : O(n)

    int tempArray[d]  , startIndex = n - d ;
    for(int i = 0 ; i < d ; i++ ){
        tempArray[i] = arr[i];
    }
    for(int i = d ; i < n ; i++){
        arr[i-d] = arr[i] ;
    }
    for(int i = 0 ; i < d ; i++)
    {
        arr[startIndex ] = tempArray[i];
        startIndex++;
    }
    printArray

}
void rotateArrayIn_N_TIME_(int arr , int d , int n){
    /* ex : 1 2 3 4 5 6 7 rotate this array by 2 elements . Final Answer would be 3 4 5 6 7 1 2
            Step 1 : Reverse first "d" elements i.e 2 elements ==> 2 1 3 4 5 6 7
            Step 2 : Reverse remaining Elements                ==> 2 1 7 6 5 4 3
            Step 3 : Reverse Entire Array                      ==> 3 4 5 6 7 1 2    
    */

}
int main(){
    int n ;
    cout << "Enter No of elements in Arrays" <<endl;
    cin >> n ;
    cout << "Enter elements into array" << endl ;
    int arr[n] ;
    takeInput
   // printArray 
    rotate(arr , 3 , n);
    return 0;
}

/*
There is another algo called as Juggling Method where the entire array will be break down in  sets of each
 having k elements
k = gcd(n ,d )
i = 1 
Iterate 1 : no of sets
    rotate i_th ele of every set
    i++
*/