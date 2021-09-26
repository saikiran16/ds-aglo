// Quickselect is a selection algorithm to find the k-th smallest element in an unordered list. 
//It is related to the quick sort sorting algorithm.
using namespace std ;
#define takeArray(arr ,n) for(int i = 0 ; i < n ; i++) cin >> arr[i];
#define printArray(arr , n) for(int i = 0 ; i < n ; i++) cout << arr[i] << " " ;cout<<endl;
//#define swap(a ,b) int temp = a ; a = b ; b = temp ;
#include<bits/stdc++.h>
void swap(int *a , int *b){ int t = *a ; *a = *b ; *b = t ; }

int partitionTheArray(int arr[] , int low , int high){
    int pivot = arr[high] ;
    int i = low - 1 ;
    for(int j = low ; j < high ; j++){
            if(arr[j] < pivot){
                i++;
                swap(&arr[i] , &arr[j]);
            }
    }
    swap(&arr[i+1] , &arr[high]);
    return i+1 ;
}

// Finding Kth smallest element using QUICK SELECT .
int findKthSmallestElement(int arr[] , int low , int high ,int k ){
    if(low < high){
        int pivotIndex = partitionTheArray(arr , low , high);
        cout << "pivot Index : " << pivotIndex << " Ele : "  << arr[pivotIndex]  << endl;
        if(pivotIndex == k-1)
            return arr[pivotIndex];
        else if(pivotIndex > k-1)
            return findKthSmallestElement(arr , low , pivotIndex-1 , k );
        else
            return findKthSmallestElement(arr , pivotIndex+1 , high , k);
    }
    else if(high == low && k-1 == low) return arr[low];
    return INT_MAX;
}
int main(){
    int arr[] = {1};
    int n = 1 ;
    int k = 1 ;
    cout << findKthSmallestElement(arr , 0 , n - 1 , k);
    return 0;
}