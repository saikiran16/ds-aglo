using namespace std ;
#define takeArray(arr ,n) for(int i = 0 ; i < n ; i++) cin >> arr[i];
#define printArray(arr , n) for(int i = 0 ; i < n ; i++) cout << arr[i]  ;cout<<endl;
#include<bits/stdc++.h>
int cmp(int a, int b){
    string x = std::to_string(a) ;
    string y = std::to_string(b);
    string xy = x+y ;
    string yx = y+x ;
    if(xy < yx) return 0 ;
    else 
    return 1 ;

}
int main(){
    int arr[] = {1, 34, 3, 98, 9, 76, 45, 4};
    sort(arr , arr + 8 , cmp );
    printArray(arr, 8);
    return 0;
}