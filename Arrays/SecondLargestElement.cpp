using namespace std ;
#define takeArray(arr ,n) for(int i = 0 ; i < n ; i++) cin >> arr[i];
#define printArray(arr , n) for(int i = 0 ; i < n ; i++) cout << arr[i] << " " ;cout<<endl;
#include<bits/stdc++.h>
int print2largest(int arr[], int n)
    {
    	//code here.
    	int first_max = INT_MIN ;
    	int second_max = INT_MIN ;
    	for(int i = 0 ; i < n ; i++){
    	    if(first_max == INT_MIN){
    	        first_max = arr[i];
    	    }
    	    else if(first_max < arr[i]){
    	        second_max = first_max ;
    	        first_max = arr[i];
    	    }
    	    else if(arr[i] < first_max && arr[i] > second_max){
    	        second_max = arr[i];
    	    }
    	}
    	if(second_max == INT_MIN) return -1 ;
    	return second_max ;
    }
int main(){
    int n = 5 ;
    int arr[] = { 2, 4, 5, 6, 7 } ;
    cout << print2largest(arr , n) << endl;
    return 0;
}