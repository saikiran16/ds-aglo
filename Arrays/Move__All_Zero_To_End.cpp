/* --------------Move all zeroes to end of array----------------
    Given an array arr[] of N positive integers.
    Push all the zero’s of the given array to the right end of the array while maintaining the order of non-zero elements.

*/
using namespace std ;
#define takeArray for(int i = 0 ; i < n ; i++) cin >> arr[i];
#define printArray for(int i = 0 ; i < n ; i++) cout << arr[i] << " " ;cout<<endl;
#include<bits/stdc++.h>

void pushZerosToEnd(int arr[], int n) {
	     int  zero = 0 ;
        for(int i = 0 ; i <  n ; i++){
            if(arr[i] != 0 && arr[zero] == 0){
                int temp = arr[i];
                arr[i] = arr[zero];
                arr[zero] = temp;
                zero++;
            }
            
            if(arr[zero] > 0) zero++;
        }
	}
int main(){
    int arr[] = {3, 5, 0, 5 ,0 , 5 , 0, 4} ;
    int n = 8;
    pushZerosToEnd(arr , n) ;
    printArray
    return 0;
}