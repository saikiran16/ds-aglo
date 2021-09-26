#include <iostream> 
using namespace std;
#define mod 1000000007


int main()
 {
	    long long int n , k , i , prod = 1 ;
	    cin >> n >> k ;
	    long long int a[n] ;
	    for(i=0;i<n;i++){
	        cin >> a[i] ;
	    }
	    long long int start = 0 , end = 0 , count = 0 ;
	    while(end<n){
	        prod = prod*a[end] ;
	        while (start < end && prod >= k) 
                prod /= a[start++];
                
            if (prod < k) {
                int len = end-start+1;
                count += len;
            }
	        end++ ;
	    }
	    
	    cout << count << endl ;
	return 0;
}