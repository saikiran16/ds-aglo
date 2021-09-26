//Given a sorted and rotated array, find if there is a pair with a given sum
/*
    Solution : First we find the pivot element where the array is rotated 
               Next We Will use two pointer technique and we assign start and end pointers .
               ex : 3 4 5 1 2 3
               here pivot is 5 
               so start = pivot + 1 ==> 3
                  end = pivot ==> 2
                  

*/
using namespace std ;
#define takeArray for(int i = 0 ; i < n ; i++) cin >> arr[i];
#define printArray for(int i = 0 ; i < n ; i++) cout << arr[i] << " " ;cout<<endl;
#include<bits/stdc++.h>
int findPivot(int arr[] , int n ){
    for(int i = 0 ; i < n - 1 ; i++){
        if(arr[i] > arr[i+1]) return i ;
    }
    return -1;
}
int countParis(int  arr[] , int sum,int n ){
    int pivot = findPivot(arr , n);
    int start  = 0,end_ = n-1  ;
    if(pivot != -1){
        start = pivot + 1 ;
        end_ = pivot ;
    }
    int pairs = 0;
    while(1){
        int s = arr[start] + arr[end_] ;
        
        if(s == sum) { pairs++; start++ ; end_-- ;}
        else if(s < sum){start++;}
        else end_--;

        if(start == n) start = 0 ;
        if(end_ == -1) end_ = n - 1;
        if(start == end_ ) return pairs ;
        if(start == 0 && end_ == n-1) return pairs ;
        if(abs(start - end_ == 1)) return pairs ;

    }

}
int main(){
    int n,x ; cin >> n ;
    int arr[n]  ;
    takeArray
    cout << "Enter SUM : " ;
    cin >> x ;
    cout << countParis(arr ,x ,n );
    
    return 0;

}
