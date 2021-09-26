using namespace std ;
#define takeArray(arr ,n) for(int i = 0 ; i < n ; i++) cin >> arr[i];
#define printArray(arr , n) for(int i = 0 ; i < n ; i++) cout << arr[i] << " " ;cout<<endl;
#include<bits/stdc++.h>

void swap(int* a , int* b){
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}
void heapify(int arr[] , int n , int i ){
    int largest = i ;
    int leftChildIndex = 2*i+1;
    int rightChildIndex = 2*i+2;
    if( leftChildIndex < n && arr[leftChildIndex] > arr[largest])
        largest = leftChildIndex ;
    if( rightChildIndex < n  && arr[rightChildIndex] > arr[largest])
        largest = rightChildIndex ;
    if(largest != i){
        swap(&arr[largest] , &arr[i]);
        heapify(arr , n , largest);
    }
}

void heapSort(int arr[] , int n){
    for(int  i= n/2-1 ; i>=0 ; i--){
        heapify(arr , n , i);
       
    }
    for(int i = n - 1 ; i >= 0 ; i--){
        swap(&arr[0] , &arr[i]);
        heapify(arr , i , 0) ;
    }
    
}
int main(){
    int n = 7 ;
    int arr[] = {1,2,3,4,5,6,7};
    heapSort(arr , n) ;
    printArray(arr ,n );
    return 0;
}