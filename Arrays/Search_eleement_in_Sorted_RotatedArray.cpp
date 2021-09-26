// Search an element in a sorted and rotated array
//Difficulty Level : Medium
// Use BinarySearch
/*
    First Find the pivot element where things got rotated 
    Divide the array into 2 parts by pivot element
    Apply Binarysearch to Search for key Ele .
*/


using namespace std ;
#include<bits/stdc++.h>
#define printArray for(int i = 0 ; i < n ; i++) cout << arr[i] << " " ;

// Finding Pivot : The Element which is less than Prevoius Element .
int findPivot(int arr[] , int low  ,int high){
        while(low <= high){
            int mid = (low + high) / 2 ;
            if( mid > low  && arr[mid-1] > arr[mid])
                return mid-1 ;
            else if( mid < high && arr[mid] > arr[mid + 1]) 
                return mid ;
            else if(arr[low ] >= arr[mid]){
                high = mid - 1  ;
            }
            else{
               low  = mid +  1 ;
            }
            
        }
    return -1 ;
    }
int binarySearch(int arr[] , int low , int high ,int key){
    while(low <= high){
        int mid = (low + high)/2 ;
        if(arr[mid] == key) return mid ;
        else if(arr[mid] < key)
            low = mid + 1 ;
        else 
            high = mid - 1 ; 
    }
    return -1;
}
int main(){
    int n = 7   ;
    int arr[n]  = {5,1,2,3,4};
    int key = 3 ;
    int pivot = findPivot(arr , 0 , 4) ;
    //cout << pivot  << endl;
    int first = binarySearch(arr , 0 , pivot , key) ;
    if(first == -1 ){
        int second = binarySearch(arr , pivot+1 , n-1 , key);
        cout << second ;
    }
    else 
        cout << first ;

    return 0;
}