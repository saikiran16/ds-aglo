using namespace std ;
#define takeArray for(int i = 0 ; i < n ; i++) cin >> arr[i];
#define printArray for(int i = 0 ; i < n ; i++) cout << arr[i] << " " ;cout<<endl;
#include<bits/stdc++.h>
void rearrange(int arr[], int n) {
	    // code here
	    int pos_arrow = 0 ;
	    int neg_arrow = 1 ;
	    int res[n] ={0}  ,posCount = 0 , negCount = 0  ;
	    for(int i = 0 ; i < n ; i++){
	        if(arr[i] >= 0) posCount++ ;
	        else negCount++;
	    }
	    for(int i = 0 ; i < n ; i++){
	        if(arr[i] >= 0 ){
	            res[pos_arrow] = arr[i] ;
	            //cout << res[pos_arrow] << endl;
	            if(negCount == 0)
	                pos_arrow++;
	            else{
	                pos_arrow += 2 ; 
                    negCount--;
                }  
	        }
	        else{
	            res[neg_arrow] = arr[i];
	            //cout << res[pos_arrow] << endl;
	            
	            if(posCount == 0)
	                neg_arrow++;
	            else{
	                neg_arrow += 2;
                    posCount--;
                }
	        }
	        
	    }
	    for(int i = 0 ; i < n ; i++)
	        arr[i] = res[i];
	    
	}


void postive_and_negative(int arr[] , int n){
	int res[n]  ,i = 0 ,posArrow = 0 , negArrow = 0;
	while(i < n && posArrow < n && negArrow < n ){
		while(posArrow < n && arr[posArrow] < 0){
			posArrow++;
		}
		while(negArrow < n && arr[negArrow] > 0){
			negArrow++;
		}
		if(posArrow < n)
		{
			res[i] = arr[posArrow] ;
			i++;
			posArrow++;
		}
		if(negArrow < n)
		{
			res[i] = arr[negArrow] ;
			i++;
			negArrow++;
		}
		
	}
	cout << posArrow << " " << negArrow << " " << i << endl ;
	while(i < n && posArrow < n) {res[i] = arr[posArrow] ; posArrow++;i++;}
	while( i < n && negArrow < n ) {res[i] = arr[negArrow] ; negArrow ;i++;}
	for(int i = 0 ; i < n ; i++) cout << res[i] << " ";
}
int main(){
    int arr[] = {4, 5, 6, 7, -1,-2} , n = 6 ;
   // rearrange(arr , n);
   postive_and_negative(arr , n);
    //printArray
    return 0;
}