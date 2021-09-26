using namespace std ;
#define takeArray(arr ,n) for(int i = 0 ; i < n ; i++) cin >> arr[i];
#define printArray(arr , n) for(int i = 0 ; i < n ; i++) cout << arr[i] << " " ;cout<<endl;
#include<bits/stdc++.h>
void swap(int* a , int* b){
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}
int partitionTheArray(int arr[] , int low , int high) {
    int pivot = arr[high] ;
    int i = low - 1 ;
    for(int j = low ; j < high ; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i] , &arr[j]);
        }
    }
    swap(&arr[i+1] , &arr[high]);
    return i+1;
}
void quickSort(int arr[] , int low , int high){
    if(low < high){
        int l = partitionTheArray(arr , low , high) ;
        quickSort(arr , low , l-1) ;
        quickSort(arr , l+1 , high);
    }

}
int main(){
    int n = 7 ;
    int arr[] = {100,2,5,6,4,7,9};
    quickSort(arr, 0 ,n-1);
    cout << n << endl;
    printArray(arr ,n);
    return 0;
}